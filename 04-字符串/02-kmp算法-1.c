#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//根据 Pattern 计算前缀表
void GetPrefix(char pattern[],char prefix[],int n)
{
    int len=0;//用来存储当前字符串的最大前缀
    int i = 1;
    prefix[0] = 0;

    while(i<n)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            if(len > 0)
                len = prefix[len - 1];
            else
            {
                prefix[i] = len;
                i++;
            }
        }
    }
}

//向后移动一位
void MovePrefix(char prefix[],int n)
{
    for(int i = n -1;i > 0;i--)
    {
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;
}

void KMP(char text[],char pattern[])
{
    //text[i]    m
    //pattern[j] n
    int m = strlen(text);
    int n = strlen(pattern);
    int i = 0;
    int j = 0;
    char* prefix = (char*)malloc(sizeof(char));
    
    GetPrefix(pattern,prefix,n);
    MovePrefix(prefix,n);

    while(i<m)
    {

        if(j == n -1 && text[i] == pattern[j])
        {
            printf("Find pattern at %d\n",i-j);
            j = prefix[j];
        }
        if(text[i] == pattern[j])
        {
            i++;j++;
        }
        else
        {
            j = prefix[j];
            if(j==-1)
            {
                i++;j++;
            }
        }
    }

    free(prefix);
}

int main(void)
{   
    printf("这是一个KMP算法的例程\n");

    char pattern[] ="ABABCABAA";
    char text[] = "ABAABABCABAABABAA";
    
    KMP(text,pattern);

    return 0;
}
