#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) 
	{
		/*
			//每次和最右上角的数 array[i][j] 做比较
			//if target == array[i][j]  结束
			//if target > array[i][j]   去除当前行
			//if target < array[i][j]   去除当前列
		*/
		int row = array.size();
		int col = array[1].size();
		int i = 0;  //row
		int j = col - 1;
		if ((!array.empty()) && (row>0) && (col>0))
		{
			while (i<row && j>= 0)
			{
				if (target == array[i][j])
					return true;
				else if (target > array[i][j])
				{
					++i;
				}
				else
				{
					--j;
				}
			}
		}
		return false;
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<vector<int> > array;
	for (int i = 0; i<5; i++)
	{
		vector<int> temp;
		for (int j = 0; j<10; j++)
		{
			temp.push_back(i + j);
		}
		array.push_back(temp);
	}
	int target = 0;
	bool flag = s.Find(target, array);
	cout << "target = " << target << "flag = " << flag << endl;
	getchar();
	return 0;
}

