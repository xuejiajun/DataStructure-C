#include <iostream>
#include "student.h"
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
	int a[10] = {1,3,5,7,9,10,8,6,4,2,};
	SelectSort(a,10);
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		cout<<a[i]<<"  ";
	}
	cout<<endl;

	float b[10] = {1.1,3.2,5.7,7.9,9.1,10.2,8.3,6.4,4.0,2.1,};
	SelectSort(b,10);
	for (int i = 0; i < 10; ++i)
	{
		/* code */
		cout<<b[i]<<"  ";
	}
	cout<<endl;


	string c[4] = {"D","B","C","A"};
	SelectSort(c,4);
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		cout<<c[i]<<"  ";
	}
	cout<<endl;

	Student d[4] = {{"D",100},{"C",80},{"A",80},{"B",80}};
	SelectSort(d,4);
	 for (int i = 0; i < 4; ++i)
	{
		/* code */
		cout<<d[i]<<"  ";
	}
	cout<<endl;
}
