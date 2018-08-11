#include <iostream>

using namespace std;


//在arr中查找target
template<typename T>
int BinarySearch1(T arr[],const int len,T target)
{
	int left = 0;
	int right = len -1;
	//在arr[left...right]中进行查找
	while(left<=right)
	{
		//int mid = (left+right)/2;
		int mid = left + (right-left)/2;
		if(target == arr[mid])
			return mid;

		else if(target>arr[mid])
			//在arr[mid+1 right]
			left = mid+1;
		else
			//在left mid-1查找
			right = mid -1;
	}
	return -1;
}

template<typename T>
int __BinarySearch(T arr[],int left,int right,int target)
{
	if(left>right)
		return -1;

	int mid = left + (right-left)/2;
	if(target == arr[mid])
		return mid;

	else if(target>arr[mid])
		//在arr[mid+1 right]
		//left = mid+1;
		__BinarySearch(arr,mid+1,right,target);
	else
		//在left mid-1查找
		//right = mid -1;
		__BinarySearch(arr,left,mid-1,target);
}

template<typename T>
int BinarySearch2(T arr[],const int len,T target)
{
	return __BinarySearch(arr,0,len-1,target);
}
int main(int argc, char const *argv[])
{
	const int len = 100;
	int a[len];
	int target = 33;
	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
	}

	cout<<"target "<<target<<" at "<<BinarySearch2(a,len,target)<<endl;

	return 0;
}