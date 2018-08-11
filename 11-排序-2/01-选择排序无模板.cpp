#include <iostream>

using namespace std;

void swap(int &left,int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void SelectSort(int arr[],const int len)
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
	int a[10] = {1,3,5,7,9,10,8,6,4,2,};
	SelectSort(a,10);
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}
