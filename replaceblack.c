#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100
//题目：实现一个函数，要求吧字符串中的所有空格替换成“%20”。例如“hello world "  ——>  ”hello%20world%20"
//面试时要问清楚是在原字符串基础上替换还是可以重新定义一个新位置

//思路一：可以再造一个数组，遇到空格就替换成”%20“这样就造成了空间的浪费，可以实现但不是最佳
//思路二：从前往后：在原基础上进行替换（当然前提是空间足够），如果从前往后遇到空格就替换，必然会对原来的字符造成覆盖，不可以实现。
//从后往前：如果倒着遇到空格就往后移动同时替换，那么如果全部是空格，那势必造成时间复杂度为O(n2)的开销。可以实现，但不是最佳
//思路三：因为把空格替换为”%20“，每次替换多2个字符，因此可以统计出字符串中空格的总个数，然后新数组大小为“原数组大小 + 2*空格数 ”。
//从后往前处理：遇到非空格，直接搬到后面，遇到空格替换为”%20“. 直到待插入位置指针和原数组为指针重合位置。
void ReplaceBlack(char *p)
{
  if (p != NULL)
  {
    int i, end, pos ,size_black = 0;
    size_t  lenold = strlen(p), lennew;
    //先统计空格的数量，才能计算新字符串的长度
    for (i=0; i != lenold; i++)
    {
        if (p[i] == ' ')
            size_black++;
    }
    lennew = lenold + 2 * size_black;
    //这里设置了字符串的长度限制
    if(lennew > MAXLEN)
        return;
    pos = lennew-1;
    end = lenold-1;
    //两个尾指针重合则停止
    while(pos != end)
    {
        if (p[end] != ' ')
            p[pos--] = p[end--];
        else
        {
            p[pos--] = '0';
            p[pos--] = '2';
            p[pos--] = '%';
            end--;
        }
    }//while
  }
}

int main()
{
    char *a = (char*)malloc(sizeof(char) * MAXLEN);
    if(NULL != a)
    {
        strcpy(a, "hello world ");
        ReplaceBlack(a);
        printf("%s\n", a);
        free(a);
    }
    return 0;
}
