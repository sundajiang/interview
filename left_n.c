//p_sum个人围一桌，从0号开始报数1，数到n的倍数的离开，直至最后一个人，求他原来几号

#include <stdio.h>
//没有这个头文件malloc函数会报警告
//warning: incompatible implicit declaration of built-in function ‘malloc’ [enabled by default]
#include <stdlib.h>
//没有这个头文件memset函数会报警告
//incompatible implicit declaration of built-in function ‘memset’ [enabled by default]
#include <string.h>

//思路：按照总的人数生成一个数组，数组内元素值为0说明状态正常，值为-1，说明已经出队
//设置一个变量left记录出队的人数，达到总人数减一的时候则停止报数

//参数p_num为总人数，参数n为跳过的基数
int left_n(const int p_sum , int n)
{
    int left = 0;//出队的人数
    int i = 0;//数组下标
    int j = 0;//报数
    int if_call = 0;
    //要用到动态数组，应为传入参数p_sum是一个变量，普通数组的元素个数必须是常量
    int *p = (int *)malloc(sizeof(int)*p_sum);
    if(p == NULL)
    {
        printf("malloc error !\n");
        return -1;
    }
    memset(p,0,sizeof(int)*p_sum);
    //int p[p_sum] = {0};//数据为0说明为队列中状态

    //注意这里的减一，p_sum是人数而不是下标！
    while(left < p_sum - 1)
    {
        //若状态正常，则报数加一
        if(p[i] == 0)
        {
            j++;
            //注意这个出队判断应该放在里面，因为只有报数加一之后才进行判断
            if(j%n == 0)
            {
                printf("person %d out\n",i+1);
                left++;
                p[i] = -1;
            }
        }
        //下标到p_sum之后自动变回为0，每一个人其实并不真正出队，只是不再报数而已，下次到已出队的位置仍会进行判断
        i++;
        i %= p_sum;
    }
    for(i = 0;i < p_sum;i++)
    {
        if(p[i] == 0)
        {
            printf("the last one is %d\n",i+1);
        }
    }
    return 0;
}


int main()
{
    left_n(5,3);
    return 0;
}
