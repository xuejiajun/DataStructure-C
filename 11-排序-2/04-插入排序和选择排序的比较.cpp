#include "sorttesthelper.h"

template<typename T> 
void SelectSort(T arr[],const int len)
{
	for(int i=0;i<len;++i)
	{
		//从i+1开始寻找这之后的最小值
		int minIndex = i;
		for (int j = i+1; j < len; ++j)
		{
			if(arr[j]<arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}


template<typename T>
void InsertSort1(T arr[],const int len)
{
	for(int i  = 1; i < len; i++)
	{
		for(int j = i;j>0 && arr[j]<arr[j-1];j--)
			swap(arr[j],arr[j-1]);
	}
}

template<typename T>
void InsertSort2(T arr[],const int len)
{
	for (int i = 1; i < len; ++i)
	{
		if(arr[i]<arr[i-1])
		{
			T temp = arr[i];
			int j = i;
			while(j>=0 && temp<arr[j-1])
			{
				arr[j] = arr[j-1];
				j--;
			}
			arr[j] = temp;
		}
	}
}

template<typename T>
void InsertSort3(T arr[],const int len)
{
	for (int i = 1; i < len; ++i)
	{
		T temp = arr[i];
		int j = 0;
		for(j=i;j>0 && arr[j-1] > temp;--j)
			arr[j] = arr[j-1];
		arr[j] = temp;
	}
}

int main(int argc, char const *argv[])
{
	const int len = 100000;
	//int* a = SortTestHelper::GenerateRandomArray(len,0,10);
	//对近乎有序的数组进行排序,效率更高
	int* a = SortTestHelper::GenerateNearlyOrderArray(len,len/10);
	int* b = SortTestHelper::CopyArray(a,len);


	SortTestHelper::TestSort("InsertSort",InsertSort3,a,len);
	SortTestHelper::TestSort("SelectSort",SelectSort,b,len);
	//SortTestHelper::PrintArray(a,len);
	return 0;
}