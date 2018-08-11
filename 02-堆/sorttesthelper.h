#ifndef __SORTTESTHELPER_H__
#define __SORTTESTHELPER_H__

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

namespace SortTestHelper
{

	int* CopyArray(int arr[],const int len)
	{
		int* a = new int[len];
		copy(arr,arr+len,a);
		return a;
	}

	int* GenerateNearlyOrderArray(const int len,const int swaptimes)
	{
		//先生成一个有序的数组
		int* arr = new int[len];
		for (int i = 0; i < len; ++i)
		{
			arr[i] = i;
		}

		srand(time(NULL));
		for (int i = 0; i < swaptimes; ++i)
		{
			int pos1 = rand()%len;
			int pos2 = rand()%len;
			int temp = arr[pos1];
			arr[pos1] = arr[pos2];
			arr[pos2] = temp;
		}
		return arr;
	}
	//生成随机数组
	int* GenerateRandomArray(const int len ,int rangeL,int rangeR)
	{
		assert(rangeL<rangeR);
		int* arr =  new int[len];
		srand(time(NULL));
		for(int i=0;i<len;i++)
		{
			arr[i] = rand()%(rangeR-rangeL+1)+rangeL;
		}
		return arr;
	}
	//打印数据
	template<typename T>
	void PrintArray(T arr[],const int len)
	{
		for (int i = 0; i < len; ++i)
		{
			cout<<arr[i]<<"  ";
		}	
		cout<<endl;
	}
	//验证数据是否被排序
	template<typename T>
	bool IsSort(T arr[],const int len)
	{
		for (int i = 0; i < len-1; ++i)
		{
			if(arr[i]>arr[i+1])
				return false;
		}
		return true;
	}

	//测试排序函数
	template<typename T>
	void TestSort(const string& sortfunctname,void(*sort)(T[] ,const int),T arr[],const int len)
	{
		clock_t starttime = clock();
		sort(arr,len);
		clock_t endtime = clock();
		assert(IsSort(arr,len));
		cout<<sortfunctname<<"排序"<<len<<"个数据花费的时间是: "<<double(endtime-starttime)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
		return ;
	}  
}


#endif /*__SORTTESTHELPER_H__*/