#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) 
	{
		/*统计出源字符串中空格的数量numofspace
		则新的字符串的长度是  newstringlength = (oldstringlenth-numofspace) + numofspace * 3
		从后向前遍历，得到空格除，分别用 %20 替换即可 */
		char* oldstring = str;
		int oldstringlenth = length;
		//统计空格数量
		int numofspace = 0;
		while(*oldstring!='\0' && length > 0 )
		{
			if(*oldstring == ' ')
			{
				numofspace++;
			}
				
			oldstring++;
			length--;
		}

		
		int newstringlength = (oldstringlenth-numofspace) + numofspace * 3;
		char* newstring = str;

		int i = oldstringlenth - 1 ;
		int j = newstringlength - 1;
		while(i >= 0 && j >= 0)
		{
			//如果是空格，则替换
			if(str[i] == ' ')
			{
				newstring[j] = '0';
				j--;
				newstring[j] = '2';
				j--;
				newstring[j] = '%';
			}
			//不是空格则逐一替换
			else
				newstring[j] = str[i];

			i--;j--;
		}
		str = newstring;
	}
	
};


int main(int argc, char const *argv[])
{
	Solution s;
	char str[] = "I am happy";
	s.replaceSpace(str,strlen(str));
	cout<<str<<endl;
	getchar();
	return 0;
}
