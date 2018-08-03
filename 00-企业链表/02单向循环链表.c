#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LINKNODE
{
    struct LINKNODE* next;
}LinkNode;

typedef struct LINKLIST
{
    LinkNode head;
    int size;
}LinkList;

LinkList* InitLinkList(void)
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;
  // list->head = NULL;
    return list;
}

void AppendLinkList(LinkList* list,LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || data == NULL)
        return ;
}

void InsertLinkList(LinkList* list,int pos, LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || data == NULL || pos > list->size || pos < -(list->size + 1))
        return ;
    if(pos < 0)
        pos = pos + list->size + 1;


}

void RemoveByPosLinkList(LinkList* list, int pos)
{
    //判断传入的参数是否合法
    if(list == NULL || pos >= list->size || pos < -(list->size))
        return ;
    if(pos < 0)
        pos = pos + list->size;


}

void RemoveByValLinkList(LinkList* list,LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || data == NULL)
        return ;
}

void ChangeByPosLinkList(LinkList* list,int pos,LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || data == NULL || pos >= list->size || pos < -(list->size))
        return ;
    if(pos < 0)
        pos = pos + list->size;


}

void ChangeByValLinkList(LinkList* list,LinkNode* srcdata,LinkNode* dstdata){

    //判断传入的参数是否合法
    if(list == NULL || srcdata == NULL || dstdata == NULL)
        return ;
}

LinkNode* GetItemLinkList(LinkList* list,int pos)
{
    //判断传入的参数是否合法
    if(list == NULL || pos >= list->size || pos < -(list->size))
        return NULL;
    if(pos < 0)
        pos = pos + list->size;

    return NULL;
}

int FindByPosLinkList(LinkList* list,LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || data == NULL)
        return -1;
}

typedef void(*FUNC)(LinkNode*);
void TraverseLinkList(LinkList* list,FUNC func)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return ;
}

int SizeLinkList(LinkList* list)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return -1;
}

void FreeSpaceLinkList(LinkList* list)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return ;

}

typedef struct STUDENT
{
    LinkNode node;
    char name[40];
    int age;
    int score;
}Student;

void PrintStudent(LinkNode* data)
{
    Student* p = (Student*)data;
    printf("Name = %s , Age = %d , Score = %d\n",p->name,p->age,p->score);
}

int main(void)
{
    printf("这是一个普通企业链表的例程\n");

    Student s1,s2,s3,s4,s5;
    strcpy(s1.name,"aaa");
    strcpy(s2.name,"bbb");
    strcpy(s3.name,"ccc");
    strcpy(s4.name,"ddd");
    strcpy(s5.name,"eee");
    
    s1.age = 11; s1.score = 66;
    s2.age = 22; s2.score = 77;
    s3.age = 33; s3.score = 88;
    s4.age = 44; s4.score = 99;
    s5.age = 55; s5.score = 111;

    return 0;
}
