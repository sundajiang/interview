
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

int main()
{
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

