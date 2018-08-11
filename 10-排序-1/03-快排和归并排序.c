#include<stdlib.h>
#include<stdio.h>
#include<time.h>//生成随机种子用
#include<sys/timeb.h>//获取系统运行时间

#define MAX_SIZE 100

//获取系统时间
time_t GetSystemTime(void)
{
   struct timeb tb;
   ftime(&tb);
   return tb.time * 1000 + tb.millitm;
}

//打印数组
void PrintArray(int arr[],int len)
{
    for(int i=0;i<len;i++)
        printf("%d  ",arr[i]);
    printf("\n");
}

void QuickSort(int arr[],int start,int end)
{
    if(start<end)
    {
        //定义左右指针
        int left = start;
        int right = end;
        //选取基准数
        int base = arr[left];
        while(left<right)
        {
                //从右向左找第一个比基准小的数
            while(left<right && arr[right] >= base)
            {
                right--;
            }
            //将右侧的数填到坑中
            if(left<right)
            {
                arr[left] = arr[right];
                left++;
            }
            //从右向左找第一个比基准小的数
            while(left<right && arr[left] <= base)
            {
                left++;
            }
            //将右侧的数填到坑中
            if(left<right)
            {
                arr[right] = arr[left];
                right--;
            }

        }
        arr[left] = base;
        QuickSort(arr,start,left-1);
        QuickSort(arr,left+1,end);
    }
}




void MergeSortRecur(int arr[],int start,int end,int dst[])
{
    if(start>=end)
        return ;
    int len = end-start,mid = start+(len>>1);
    int start1 = start,end1 = mid;
    int start2 = mid+1,end2 = end;

    MergeSortRecur(arr,start1,end1,dst);
    MergeSortRecur(arr,start2,end2,dst);

    int k = start;
    while(start1<=end1 && start2<=end2)
        dst[k++] = arr[start1]<arr[start2] ? arr[start1++] : arr[start2++];
    while(start1<=end1)
        dst[k++] = arr[start1++];
    while(start2<=end2)
        dst[k++] = arr[start2++];

    for(k = start;k<=end;k++)
        arr[k]  = dst[k];
}

void MergeSort(int arr[],const int len)
{
    int dst[len];
    MergeSortRecur(arr,0,len-1,dst);
}



int main(void)
{
    printf("这是快速排序和归并排序的例程\n");
    int arr[MAX_SIZE];
    srand((unsigned int)time(NULL));//生成随机种子
    for(int i=0;i<MAX_SIZE;i++)
    {
        int temp = rand() % MAX_SIZE;
        arr[i] = temp;
    }

    PrintArray(arr,MAX_SIZE);
    time_t starttime = GetSystemTime();
    //QuickSort(arr,0,MAX_SIZE-1);
    int dst[MAX_SIZE];
    MergeSort(arr,MAX_SIZE);
    time_t endtime = GetSystemTime();

    PrintArray(arr,MAX_SIZE);
    printf("排序%d个数据消耗的时间是%ldms\n",MAX_SIZE,endtime - starttime);


    return 0;
}
