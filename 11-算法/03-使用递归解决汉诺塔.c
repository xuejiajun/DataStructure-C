#include<stdio.h>
#include<stdlib.h>


//
void MoveHanoi(int n,char from,char depend,char end)
{
    static int num;
    num++;
    printf("此时 n = %d\n",n);
	if(n <1 )
	{
		return;
	}
	if( n == 1)
	{
		printf("第%d步n = %d : %c-->%c\n",num,n,from,end);
		return ;
	}
	MoveHanoi(n-1,from,end,depend);
	printf("第%d步n = %d : %c-->%c\n",num,n,from,end);
	MoveHanoi(n-1,depend,from,end);	
}


int main(void)
{
	MoveHanoi(3,'A','B','C');
	printf("z");
	return 0;
}
