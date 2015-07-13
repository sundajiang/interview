#include <stdio.h>
//二维数组查找，在一个二维整数数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

//注意二维数组参数的传入，这里是当作一维数组来处理
int find(int *a,int rows,int lines,int num)
{
    int find = 0;
    if(a != NULL && rows > 0 && lines > 0)
    {
        int row = 0;
        int line = lines -1;
        while(row < rows && line >= 0)
        {
            //因为实际上二维数组还是按照一维数组来存储的，所以可以按照这种方法来操作二维数组
            if(a[row*lines + line] == num)
            {
                find = 1;
                printf("row = %d,line = %d\n",row+1,line+1);
                break;
            }
            else if(a[row*lines + line] > num)
            {
                line -= 1;
            }
            else
            {
                row++;
            }
        }
    }
    return find;
}

//直接传入二维数组参数，第二维必须是一个确定的值
int find2(int a[][3],int rows,int lines,int num)
{
    int find = 0;
    if(a != NULL && rows > 0 && lines > 0)
    {
        int row = 0;
        int line = lines -1;
        while(row < rows && line >= 0)
        {
            //因为实际上二维数组还是按照一维数组来存储的，所以可以按照这种方法来操作二维数组
            if(a[row][line] == num)
            {
                find = 1;
                printf("row = %d,line = %d\n",row+1,line+1);
                break;
            }
            else if(a[row][line] > num)
            {
                line -= 1;
            }
            else
            {
                row++;
            }
        }
    }
    return find;
}

//使用行指针传入，第二维必须同样是一个确定的值
int find3(int (*a)[3],int rows,int lines,int num)
{
    int find = 0;
    if(a != NULL && rows > 0 && lines > 0)
    {
        int row = 0;
        int line = lines -1;
        while(row < rows && line >= 0)
        {
            //因为实际上二维数组还是按照一维数组来存储的，所以可以按照这种方法来操作二维数组
            if(a[row][line] == num)
            {
                find = 1;
                printf("row = %d,line = %d\n",row+1,line+1);
                break;
            }
            else if(a[row][line] > num)
            {
                line -= 1;
            }
            else
            {
                row++;
            }
        }
    }
    return find;
}

int main()
{
    int i,j,a[3][3]={ {1,2,3} , {4,5,6} , {7,8,9} };
    //int result = find( (int *)a ,3,3,7);
    int result = find2(a ,3,3,7);
    //int result = find3(a ,3,3,7);

    printf("find? %d\n",result);
    return 0;

}

