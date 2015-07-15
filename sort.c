
#include <stdio.h>
#include <time.h>

#define MAX 10
#define SWAP(x, y) {int t=x; x=y; y=t;}


//这个定位分隔函数除了可以应用再快速排序中，还可以用来查找定长数组中k大的数，或者用来查找数组中最小的k个数之类的问题
//函数返回基准（原首位值）值经过一系列交换重新定位之后的位置
//有指针left和right，对于right，如果其所指的元素的值大于或者等于基准值，那么指针往左移一位，如果小于基准值，则和基准值交换；
//同理，对于left，如果left所指元素的值小于或者等于基准值，那么指针往右移一位，如果大于基准值，则和基准值交换。
//从right开始执行，重复这两步骤，直至left == right为止。
int Partition(int *a, int left, int right)
{
    int pivot = a[left];
    while (left < right)
    {
        while (left < right && a[right] >= pivot)
        {
            right--;
        }
        if(left<right)
        {
            SWAP(a[left], a[right]);
            left++;
        }

        while (left < right && a[left] <= pivot)
        {
            left++;
        }
        if(left<right)
        {
            SWAP(a[left], a[right]);
            right--;
        }
    }

    return left;
}

//思路2,再云笔记上有说明图，重点记这一种：
void quickSort2(int *a, int left, int right)
{
    int pivot_l;

    if (left < right)
    {
        pivot_l = Partition(a, left, right);
        quickSort2(a, left, pivot_l-1);
        quickSort2(a, pivot_l+1, right);
    }
}



//这个版本是比较好理解的版本(效率不是最高的)
//quickSort函数第二个参数是要排序的数组起始下标，第三个参数是结束下标
 /*
 1. 将最左边的数设为val(也即关键字)
 2. 从i开始向右找比val大的数，找到后停下
 3. 从j开始向左找比val小的数，找到后停下
 4. 如果i>=j则离开循环
 5. 否则：交换当前的两个数
 6. 对左边递归
 7. 对右边递归
 */
void quickSort(int *a, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right+1;

        while (1)
        {
            while (i+1<MAX && a[++i]<a[left]);
            while (j-1>-1 && a[--j]>a[left]);

            if (i >= j)
            {
                break;
            }
            SWAP(a[i], a[j]);
        }

        SWAP(a[left], a[j]);

        quickSort(a, left, j-1);
        quickSort(a, j+1, right);
    }
}



int main(void)
{
    int a[MAX] = {0};
    int i;

    srand(time(NULL));

    printf("排序前:\n");
    for (i=0; i<MAX; i++)
    {
        a[i] = rand()%100;
        printf("%d ", a[i]);
    }

    quickSort2(a, 0, MAX-1);

    printf("\n排序后:\n");
    for (i=0; i<MAX; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}


