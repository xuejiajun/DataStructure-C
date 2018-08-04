#include<stdlib.h>
#include<stdio.h>
#include<time.h>//生成随机种子用
#include<sys/timeb.h>//获取系统运行时间

#define MAX_SIZE 10

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
    //定义左右指针
    int left = start;
    int right = end;
    //选取基准数
    int base = arr[left];
    //从右向左找第一个比基准小的数
    while(arr[right] > base)
    {
        right--;
    }
    //将右侧的数填到坑中
    arr[left] = arr[right];
    
    //左侧指针向右移动一格子
    left++;
    //右侧指针不动，左侧指针向右移动，直到第一
    


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


    time_t starttime = GetSystemTime();
    time_t endtime = GetSystemTime();

    PrintArray(arr,MAX_SIZE);
    
    printf("排序%d个数据消耗的时间是%ldms\n",MAX_SIZE,endtime - starttime);
    return 0;
}
