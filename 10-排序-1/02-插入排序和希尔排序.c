#include<stdio.h>
#include<stdlib.h>
#include<sys/timeb.h>
#include<time.h>

#define MAX_SIZE  60000

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

void InsertSort(int arr[],int len)
{
    //i代表数组中前 i 个是有序的
    for(int i = 1;i<len;i++)
    {   
        //如果要排序的数大于已经排序好的最后一个，不用动
        if(arr[i] >= arr[i-1])
            continue;
        //要插入的数据小于排序好的最后一个，移动排序好的数组
        else
        {
            int temp = arr[i];//保存一下当前待排序的值
            //比较移动数据
            //if 这个数小于temp ,向后移动一位
            while(temp < arr[i-1])
            {
                arr[i] = arr[i-1];
                i--;
            }
            //把数据插入到这个temp
            arr[i] = temp;
        }
    }
}

void ShellSort(int arr[], int len)
{
	int increasement = len;
	int i = 0, j = 0;
	do {
		increasement = increasement / 3 + 1;
		for (i = 0; i<increasement; i++)
		{
			for (j = i + increasement; j<len; j += increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					int k = j-increasement;
					while (k>=0 && temp < arr[k])
					{
						arr[k+increasement] = arr[k];
						k -= increasement;
					}
					arr[k+increasement] = temp;
				}
			}
		}
	} while (increasement > 1);
}

int main(void)
{
    printf("这是一个插入排序和希尔排序例程\n");
    srand((unsigned int)time(NULL));
    int arr[MAX_SIZE];
    for(int i = 0;i<MAX_SIZE;i++)
    {
        int temp = rand()%MAX_SIZE;
        arr[i] = temp;
    }
    PrintArray(arr,MAX_SIZE);
    time_t starttime = GetSystemTime();
   // InsertSort(arr,MAX_SIZE);
    ShellSort(arr,MAX_SIZE);
    time_t endtime = GetSystemTime();
    PrintArray(arr,MAX_SIZE);
    
    printf("排序%d个数据消耗的时间:%ld ms\n", MAX_SIZE,endtime - starttime);
    return 0;
}
