#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class CMyString
{
public:
    CMyString(char *pData=NULL);//构造函数
    CMyString(const CMyString& str);//拷贝构造函数
    ~CMyString();//析构函数
    CMyString& operator=(const CMyString& str);//重载运算符
    void Print();//打印字符串
private:
    char* m_pData;//数据域，字符指针
};

void CMyString::Print()
{
    cout<<m_pData<<endl;
}

//构造函数
CMyString::CMyString(char *pData)
{
    if(pData==NULL)//如果构造函数的参数为空
    {
        m_pData=new char[1];
        m_pData[0]='\0';//初始化字符串，内容为'\0'
    }
    else//如果构造函数的参数不为NULL，那么首先求出字符串长度，然后new一个长度为len+1的字符数组
    {
        int len=strlen(pData);
        m_pData=new char[len+1];
        strcpy(m_pData,pData);//字符串拷贝
    }
}

//析构函数
CMyString::~CMyString()
{
    delete[] m_pData;
}

//拷贝构造函数，拷贝构造函数与构造函数的思路非常类似。
CMyString::CMyString(const CMyString& str)
{
    int len=strlen(str.m_pData);
    m_pData=new char[len+1];
    strcpy(m_pData,str.m_pData);
}

//重载运算符
CMyString& CMyString::operator=(const CMyString& str)
{
    //如果传入的参数与当前的实例是同一个实例，则直接返回自身
    /*if(this==&str)
        return *this;

    //释放实例自身已有内存
    delete[] m_pData;
    m_pData=NULL;

    //在删除自身内存以后在重新new一个长度为len+1的字符数组，类似拷贝构造函数
    int len=strlen(str.m_pData);
    m_pData=new char[len+1];
    strcpy(m_pData,str.m_pData);*/

    //在运行完if语句以后，因为出了strTemp的作用域，该实例会自动调用析构函数，把strTemp.m_pData所指向的内存释放掉
    //而此时strTemp.m_pData指向的是实例原先m_pData指向的内存，并没有释放当前指向的pTemp这一块内存。
    //所以还是相当与自动使释放掉了this原来的的m_pData，
    if(this!=&str)
    {
        CMyString strTemp(str);//使用构造函数创建一个临时对象
        //交换临时对象与当前对象的m_pData值
        //pTemp存放临时实例strTemp的m_pData，以保证if结束之后这一块内存没有被释放
        char* pTemp=strTemp.m_pData;
        //strTemp.m_pData指向m_pData原来的内存地址，所以if结束后是否那个掉的其实是旧地址的内存
        strTemp.m_pData=m_pData;
        m_pData=pTemp;
    }
    return *this;

}

int main()
{
    char a[] = "Hello World!";
    CMyString str1(a);
    CMyString str2;
    str2=str1;

    str1.Print();
    str2.Print();

    return 0;
}
