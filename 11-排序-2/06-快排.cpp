#include "sorttesthelper.h"

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



//返回pos  arr[left p-1]< arr[p]   arr[p+1 right]>arr[p]
template<typename T>
int __partition(T arr[],const int left,const int right)
{
	//优化1，将基准改成数组中随机的位置,提高对近乎有序数组排序的效率
	swap(arr[left],arr[rand()%(right-left+1)+left]);
	T base = arr[left];
	//arr[l+1...j]<base arr[j+1...i]>base
	int j = left;
	for(int i = left+1;i<=right;i++)
	{
		if(arr[i]<base)
		{
			swap(arr[j+1],arr[i]);
			j++;
		}	
	}
	swap(arr[left],arr[j]);
	return j;
}


template<typename T>
void __quicksortrecursion(T arr[],const int left,const int right)
{
	if(left>=right)
		return ;

	int pos = __partition(arr,left,right);
	__quicksortrecursion(arr,left,pos-1);
	__quicksortrecursion(arr,pos+1,right);
}



template<typename T>
void QuickSort1(T arr[],const int len)
{
	//优化1,每次选取的基准不一定是要最左侧的
	srand(time(NULL));
	__quicksortrecursion(arr,0,len-1);
}




int main(int argc, char const *argv[])
{
	const int len = 100000;
	//int* a = SortTestHelper::GenerateNearlyOrderArray(len,100);
	int* a = SortTestHelper::GenerateRandomArray(len,0,10);
	int* b = SortTestHelper::CopyArray(a,len);

	SortTestHelper::TestSort("MergeSort1",MergeSort1,a,len);
	SortTestHelper::TestSort("QuickSort1",QuickSort1,b,len);

	delete[] a;
	delete[] b;
	return 0;
}