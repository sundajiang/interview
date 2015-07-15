
#include <stdio.h>
#include <stack>   //STL
#include <queue>

class Tree
{
public:
    Tree * leftchild;
    Tree * rightchild;
    char data;
    //静态成员函数可以在没有对象的情况下直接调用（不能访问非静态成员变量），写在类里面的唯一不同是限制在类中使用
    static void CreatTree(Tree * &T);
};

//想要使用递归，函数必须是带参数的！ 这个参数比较特殊，即是指针，同时又必须是引用！否则只能得到一个本函数内部副本
void Tree::CreatTree(Tree * &T)
{
    printf("please input the data of tree Node : \n");
    char temp;
    //scanf %c的时候要想办法清楚后面的回车，一种方法是跟随一个getchar();函数，另外一种是%c前面加空格，吃掉空字符
    scanf(" %c",&temp);
    if('c' == temp)
    {
        printf("set NULL\n");
        T = NULL;
    }
    else
    {
        T = new Tree;
        T->data = temp;
        CreatTree(T->leftchild);
        CreatTree(T->rightchild);
    }
}
//前序根左右
void PreOrderVisit(Tree * T)
{
    if(T != NULL)
    {
        printf("data = %c\n",T->data);
        PreOrderVisit(T->leftchild);
        PreOrderVisit(T->rightchild);
    }
}
//中序左根右
void InOrderVisit(Tree * T)
{
    if(T != NULL)
    {
        PreOrderVisit(T->leftchild);
        printf("data = %c\n",T->data);
        PreOrderVisit(T->rightchild);
    }
}
//后序左右根
void LastOrderVisit(Tree * T)
{
    if(T != NULL)
    {
        PreOrderVisit(T->leftchild);
        PreOrderVisit(T->rightchild);
        printf("data = %c\n",T->data);
    }
}
//层序遍历每层压入队列（先进先出），记住三个函数，入队列push，返回首个pront，弹出首个pop。
//注意，是一边出队列一边入队列，再统一个循环中
void LayerOrderVisit(Tree * T)
{
    if(T == NULL)
        return;
    std::queue<Tree *> Q;           //层序遍历要用到队列
    Tree * temp;
    if(T)
    {
        Q.push(T);
        while(!Q.empty())
        {
            temp = Q.front();       //只返回不移除
            Q.pop();                //只移除不返回
            printf("data = %c\n",temp->data);
            if(temp->leftchild)
                Q.push(temp->leftchild);
            if(temp->leftchild)
                Q.push(temp->rightchild);
        }
    }
}
//记住三个函数，压栈push，返回栈顶top，出栈pop。
//非递归前序是压栈前打印，中序是出栈后打印,
void NoRecur_PreVisitOrder(Tree * T)
{
    if(T == NULL)
        return;
    std::stack<Tree*> S;
    Tree * p;
    p = T;
    //当p不为空时压栈（保存回退路径），指左；当p为空时，出栈（回退），指右
    //注意，p是栈顶节点的左孩子
    //左边全部出栈之后右边才能入栈
    while(!S.empty() || p !=NULL)
    {
        if(p)
        {
            printf("data = %c\n",p->data);
            S.push(p);
            p = p->leftchild;
        }
        //改变方向前先出栈
        else
        {
            p = S.top();
            S.pop();
            p = p->rightchild;
        }
    }
}
//中序非递归遍历
//同样，左边全部出栈之后右边才能入栈，和前序不同的只是打印时机，这里是出栈时打印
void NoRecur_InVisitOrder(Tree * T)
{
    if(T == NULL)
        return;
    std::stack<Tree *> S;
    Tree * p = T;
    while(!S.empty() || p != NULL)
    {
        if(p)
        {
            S.push(p);                      //压栈
            p = p->leftchild;               //指左
        }
        else
        {
            p = S.top();                    //出栈
            S.pop();
            printf("data = %c\n",p->data);  //打印
            p = p->rightchild;              //指右
        }
    }
}
//后序遍历和前两个差别较大，需要在压栈到最左之后判断p的右孩子是否为空，而不是p本身是否为空
void NoRecur_LastVisitOrder(Tree * T)
{
    std::stack<Tree*> S;
    Tree * p;
    Tree * pre = NULL;      //临时保存刚才已经打印过的节点，对应右子树不为空，但是
    p = T;

    while(!S.empty() || p !=NULL)
    {
        while(p)        //这一步是p向左到尽头
        {
            S.push(p);
            p = p->leftchild;
        }
        //经过前面步骤，p指向左边的NULL，所以需要返回栈顶元素（注意！！不弹出！！）
        p = S.top();
        //右子树为空或者右子树元素已经打印过，则打印本节点。否则转向右孩子，（以右孩子为基础）重新开始左到尽头的操作
        if(p->rightchild == NULL || p->rightchild == pre)
        {
            printf("data = %c\n",p->data);
            pre = p;
            S.pop();
            p = NULL;
        }
        else
            p = p->rightchild;

    }
}

//题目：已知前序遍历和中序遍历，生成二叉树
//思路：递归，传入参数分别为前序数组（不变），前序开始下标（可变），前序结束下标（可变）；后序数组，后序开始，后序结束；
Tree * Convert(char pre[], int pre_s, int pre_e,
              char in [], int in_s , int in_e )
{

    //要进行条件判断，此处缺失

    Tree *p = new Tree;
    p->data = pre[pre_s];
    p->leftchild = p->rightchild = NULL;

    //如果后序开始下标等于后序结束下标，则递归结束
    if(in_s == in_e)
    {
        if(pre_s == pre_e || pre[pre_s] == in[in_s])
        {
            return p;
        }
        else
        {
            printf("error end\n");
            return NULL;
        }
    }

    //在中序遍历中找到根节点的值
    int i = in_s;
    for(i=in_s;i<=in_e&&in[i]!=pre[pre_s];i++);
    if(i == in_e && in[i] != pre[pre_s])
    {
        printf("error find!\n");
        return NULL;
    }

    //递归左子树,注意前序的末尾序号表示，要考虑in_s
    pre_s = pre_s + 1;
    pre_e = pre_s+i-in_s;
    in_s = in_s;
    in_e = i -1;
    p->leftchild = Convert(pre, pre_s, pre_e,in,in_s,in_e);


    //递归右子树，注意前序的开始序号表示
    pre_s = pre_s+i-in_s+1;
    pre_e = pre_e;
    in_s = i+1;
    in_e = in_e;
    p->rightchild = Convert(pre, pre_s, pre_e,in,in_s,in_e);

    return p;
}

class A
{
    public:
        A();
        virtual ~A();
        void haha()
        {
            printf("fd\n");
        }
    private:
        int a;
};

int main()
{
    char pre[]="abdc";
    char in[]="bdac";
    Tree *head = NULL;

    //head = Convert(pre,0,strlen(pre)-1,in ,0,strlen(in)-1);

    //InTranverse(head);

    return 0;

    Tree * T;
    Tree::CreatTree(T);
    //PreOrderVisit(T);
    //InOrderVisit(T);
    //LastOrderVisit(T);
    //LayerOrderVisit(T);
    // NoRecur_PreVisitOrder(T);
    NoRecur_InVisitOrder(T);
    return 0;
}

