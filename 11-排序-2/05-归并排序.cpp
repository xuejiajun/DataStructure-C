#include "sorttesthelper.h"

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


template<typename T>
//[start mid]  [mid+1 end]合并
void __merge(T arr[],const int start,const int mid,const int end)
{
	//开辟临时空间,赋值
	T temp[end-start+1];

	//[start mid]  i 
	//[mid+1,end]  j
	//arr          k
	int i = start;
	int j = mid+1;
	int k = 0;

	while(i<=mid && j<=end)
		temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=end)
		temp[k++]  = arr[j++];
	//temp的值赋值给arr
	for(int i=0;i<end-start+1;i++)
		arr[start+i] = temp[i];
}


//[start end]区间排序
template<typename T>
void __mergesortrecurion(T arr[],const int start,const int end)
{
	if(end<=start)
		return ;
	int len = end-start, mid = (len>>1) + start;//	不使用mid = (start + end)/2为了防止越界问题
	int start1 = start,end1 = mid;
	int start2 = mid+1,end2 = end;
	__mergesortrecurion(arr,start1,end1);
	__mergesortrecurion(arr,start2,end2);
	if(arr[mid] > arr[mid+1])   //对近乎有序的数组排序的时候加上这句话会提高效率
		__merge(arr,start,mid,end);
}

//递归版本
template<typename T>
void MergeSort1(T arr[],const int len)
{
	__mergesortrecurion(arr,0,len-1);
}


//迭代版,自底向上，可以对链表排序，因为没有对数组[]操作
template<typename T>
void MergeSort2(T arr[],const int len)
{	//从规模1开始，直到最大
	for(int size = 1;size<=len;size+=size)
	{
		//每次 i 增加2 size,归并从[i i+size-1][i+size,i+2*size-1],为防止越界问题min(i+size+size-1,len-1)
		for(int i = 0;i+size<len;i+=size+size)
		{
			__merge(arr,i,i+size-1,min(i+size+size-1,len-1));
		}
	}
}


int main(int argc, char const *argv[])
{
	const int len = 10000;
	int* a = SortTestHelper::GenerateRandomArray(len,0,len);
	int* b = SortTestHelper::CopyArray(a,len);
	SortTestHelper::TestSort("MergeSort2",MergeSort2,a,len);
	SortTestHelper::TestSort("InsertSort3",InsertSort3,b,len);

	delete[] a;
	delete[] b;
	return 0;
}






