#include <iostream>
#include "student.h"
#include "sorttesthelper.h"
using namespace std;


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


int main(void)
{	
	const int len = 100000;
	int* a = SortTestHelper::GenerateRandomArray(len,0,len);

	SortTestHelper::TestSort("SelectSort",SelectSort,a,len);

	//SortTestHelper::PrintArray(a,len);
	delete[] a;

	return 0;
}
