#include <string.h>
#include <stdio.h>

//特殊情况：
//1.字符串为空指针或空串
//2.字符串中有非0到9的字符(负号,#，@，等等)
//特别需要注意的是：还要考虑溢出的问题。正整数最大值0x7FFFFFFF,负整数最小值0x80000000
//函数功能：将字符串str转换为整数, 若转换成功返回nInt,否则返回-1

int StrToInt(char *str)
{
    if (str == NULL)
    {
        printf("the point to str is empty\n");
        return -1;
    }
    else if ((strcmp(str, "")==0))
    {
        printf("the str is empty\n");
        return -1;
    }
    else if ((strcmp(str, "+")==0) || (strcmp(str, "-")==0))
    {
        printf("input error\n");
        return -1;
    }
    else
    {
        char *p = str;
        int nInt = 0;
        int hasMinus = 0;//标记字符串的第一个字符是否为负号

        if((*p)=='-')
        {
            hasMinus = 1;
            p++;
        }
        else if((*p)=='+')
        {
            p++;
        }

        while (*p != '\0')
        {
            if ((*p) >='0' && (*p) <= '9')//当前字符为数字字符
            {
                nInt = nInt * 10 + (*p) - '0';
                //注意此处(signed int)
                /*if ((!hasMinus && nInt>0x7FFFFFFF) || (hasMinus && nInt<(signed int)0x80000000))
                {
                    printf("overflow\n");
                    return -1;
                }*/
                p++;
            }
            else//当前字符为非数字字符
            {
                printf("wrong char(not num)!\n");
                return -1;
            }
        }

        if (hasMinus)//字符串有负号
        {
            nInt = (-1) * nInt;
        }

        printf("nInt : %d\n",nInt);

        //将这个整数逆序,包括负数
        int nTemp;
        while(nInt)
        {
            nTemp = nTemp*10 + nInt%10;
            nInt /= 10;
        }

        return nTemp;
        return nInt;
    }
}

int main(int argc, char* argv[])
{
    int num;
    num = StrToInt("");
    printf("num : %d\n",num);


    return 0;
}
