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

void BubbleSort(int arr[],int len)
{
    for(int i= 0;i<len;i++)
    {
        for(int j = i+1;j<len;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }	
}

//改进版排序算法
void BubbleEnchceSort(int arr[],int len)
{
    int flag = 1;//默认没有排序
    for(int i= 0;i<len && flag == 1;i++)
    {
        flag = 0;
        for(int j = i+1;j<len;j++)
        {
            if(arr[i]>arr[j])
            {
                flag = 1;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }	
}

//选择排序
void SelectSort(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int min = i;
        for(int j = i+1;j<len;j++)
        {
            if(arr[min]>arr[j])
            {
               min = j; //记录最小的位置
            }
        }
        //交换min , i
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main(void)
{
    printf("这是排序算法汇总\n");
    int arr1[MAX_SIZE];
    srand((unsigned int)time(NULL));//生成随机种子
    for(int i=0;i<MAX_SIZE;i++)
    {
        int temp = rand() % MAX_SIZE;
        arr1[i] = temp;
    }
    PrintArray(arr1,MAX_SIZE);
    
    SelectSort(arr1,MAX_SIZE);
    
    PrintArray(arr1,MAX_SIZE);
    
    return 0;
}
