#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//返回子串在主串中的位置，不存在返回-1
int BS(char text[],char pattern[])
{
    //text[i]      m
    //pattern[j]   n

    int m = strlen(text);
    int n = strlen(pattern);
    int i=0;
    int j=0;
    while(i<m-1)
    {
        if(text[i] == pattern[j])
        {
            i++;j++;
        }
        else
        {
            i = i-j+1;
            j = 0;
        }
        if(j == n-1)
        {
            printf("Find Pattern at %d\n",i-j);
            i = i - j + 1;
            j = 0;
        }
    }
    return -1;
}


int main(void)
{
    printf("这是一个暴力匹配字符串的例程\n");

    char text[] = "ABCABBCABCA";
    char pattern[] = "BCA";
    BS(text,pattern);

    return 0;
}
