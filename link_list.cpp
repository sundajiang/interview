#include <stdio.h>

//如果传入指针，再任何情况下都要先判断是否为空指针！！
//创建时要注意每个节点先申请空间在赋值
//删除时要判断头节点的情况
//插入时要判断头节点和尾节点的情况
//反转时要注意把传入的head的next指向null

class Node
{
public:
    int data;
    Node * next;
};
//单链表的创建，关键点是要分别定义一个 头指针 一个新建节点指针，和一个 滑动指针。头指针中保存着链表头部位置，不移动。
//在创建的时候，每一个节点都要申请空间。
//在创建的时候，不能直接用p = p->next；因为在创建之前p->next还什么都没有。
Node* creat()
{
    int h = 5;
    printf("%d\n",h);
    return 0;
    Node* head,* p,*s;
    int cycle = 1,x;
    head = new Node;
    p = head;
    while(cycle)
    {
        printf("please input data end with 0:\n");
        scanf("%d",&x);
        if(x != 0)
        {
            s = new Node;//必须先申请空间再复制，否则会指向不可知位置
            s->data = x;
            p->next = s;
            p = s;
        }
        else
        {
            cycle = 0;
        }
    }
    p->next = NULL;

    Node* head_del;
    head_del = head;
    head = head->next; //头指针需要后移一个元素，因为最初的头指针没有数据，会打印出一个随机数
    //其实可以增加一个删除原来头指针空间的步骤
    delete head_del;
    return head;
}

void print(Node* head)
{
    Node * p;
    p = head;
    if(head != NULL)
    {
        while(p != NULL)
        {
            printf("%d\n",p->data);
            p = p->next;
        }
    }
}

int length(Node * head)
{
    int n = 0;
    Node* p = head;
    while(p != NULL)
    {
        p = p->next;
        n++;
    }
    return n;
}

//删除节点，关键是要先定义出指向前一个节点的指针p2。
//第二个关键是要考虑删除头结点的情况。
Node * del(Node * head,int num)
{
    Node *p1,*p2; //p1指向要删除的元素，p2指向要删除的元素前一个元素。
    p1 = head;
    //寻找删除位置，插入位置也是这样找
    while(p1->data != num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(p1->data == num)
    {
        if(p1 == head) //注意等号不要写成赋值号，很难检查出来。
        {
            head = head->next;
        }
        else
        {
            p2->next = p1->next;
        }
        delete p1;   //注意删除元素的内存回收
    }
    else
        printf("not found num %d\n",num);
    return head;
}

//插入节点需要三个指针，分别指向新建节点，前节点和后节点
Node * insert(Node* head,int num)
{
    Node *p0,*p1,*p2;
    p0 = new Node;           //注意一定要申请空间
    p0->data = num;
    p1 = head;
    while(p1->data < num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if(num <= p1->data)
    {
        if(p1 == head)
        {
            p0->next = head;
            head = p0;
        }
        else
        {
            p0->next = p1;
            p2->next = p0;
        }
    }
    else
    {
        p0->next = NULL;
        p1->next = p0;
    }
    return head;

}
//冒泡排序，只是交换节点的数据，节点指针不变，head指针也不变。
Node * sort(Node * head)
{
    Node * p;
    int n , temp;
    p = head;
    n = length(head);
    if(p == NULL || p->next == NULL)
    {
        return head;
    }
    for(int i = 1 ;i < n;i++)//要从1开始！！！  筛n-1遍
    {
        p = head;
        for(int j = 0;j < n-i;j++)
        {
            if(p->data > p->next->data)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
    return head;
}

//链表逆置需要三个指针，分别指向连续的三个元素，然后从前到后依次改变指向。
Node * reverse(Node * head)
{
    Node *p1,*p2,*p3;
    if(head == NULL || head->next == NULL)
        return head;
    p1 = head;
    p2 = p1->next;
    while(p2)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head->next = NULL;
    return p1;
}

//求链表倒数第k个节点
//要注意检查k
Node * findKthtotail(Node* head,int k)
{
    if(head == NULL)
    {
        printf("wrong head ptr\n");
        return NULL;
    }
    int len = length(head);
    if(k>len || k<0)
    {
        printf("wrong k\n");
        return NULL;
    }

    Node *p1 = head;
    Node *p2 = head;
    int i;
    for(i = 0;i < k-1;i++)
    {
        p1 = p1->next;
    }
    while(p1->next != NULL)
    {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p2;
}

int main()
{
    char c[10];
    scanf(" %s",c);
    printf("got c value:%s\n",c);
    return 0;

    Node* head = creat();
    print(head);
    printf("length = %d\n",length(head));
    head = reverse(head);
    print(head);
    return 0;
}



