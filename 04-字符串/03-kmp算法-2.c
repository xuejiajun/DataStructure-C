#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetPrefix(char pattern[],char prefix[])
{
    prefix[0] = -1;
    int j = 0;
    int k = -1;
    int length = strlen(pattern);

    while(j < length -1)
    {
        if(k == -1 || pattern[k] == pattern[j])
        {
            if(pattern[++j] == pattern[++k])
            {
                prefix[j] = prefix[k];
            }
            else
            {
                prefix[j] = k;
            }
        }
        else
        {
            k = prefix[k];
        }
    }
}

void KMP(char text[],char pattern[])
{
    //text[i]   m
    //pattern[j] n
   

    int i = 0;
    int j = 0;
    int m = strlen(text);
    int n = strlen(pattern);
    char* next = (char*)malloc(sizeof(char)*n);
    GetPrefix(pattern,next);


    while(i<m && j<n)
    {
        if(j == -1 || text[i] == pattern[j])
        {
            i++;j++;
        }
        else
        {
            //i = i-j+1;//i是不需要回溯的
            j = next[j];
        }
    }
    if(j = n)
    {
        printf("Find pattern at %d\n",i-j);
    } 
    else
    {
        printf("No Find pattern\n");
    }

    free(next);
}


int main(void)
{
    printf("这是一个使用KMP算法匹配字符串的例程\n");
    char pattern[] = "ABABCABAA";
    char text[] = "ABCBABABCABAABBACB";
    char prefix[9];
    GetPrefix(pattern,prefix);
    for(int i=0;i<9;i++)
        printf("%d\n",prefix[i]);
    
    KMP(text,pattern);
    return 0;
}
