
//二分查找递归
int BinSearch(int Array[],int low,int high,int key/*要找的值*/)
{
    if (low<=high)
    {
        int mid = (low+high)/2;
        if(key == Array[mid])
            return mid;
        else if(key<Array[mid])
            return BinSearch(Array,low,mid-1,key);
        else if(key>Array[mid])
            return BinSearch(Array,mid+1,high,key);
    }
    else
        return -1;
}

//二分查找非递归
int BinSearch2(int Array[],int SizeOfArray,int key/*要找的值*/)
{
    int low=0,high=SizeOfArray-1;
    int mid;
    while (low<=high)
    {
        mid = (low+high)/2;
        if(key==Array[mid])
            return mid;
        if(key<Array[mid])
            high=mid-1;
        if(key>Array[mid])
            low=mid+1;
    }
    return -1;
}
