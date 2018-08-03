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

//初始化链表
LinkList* InitLinkList(void)
{
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;
    list->head.next = NULL;
    return list;
}

void AppendLinkList(LinkList* list,LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || data == NULL)
        return ;

    //定位到最后一个节点
    LinkNode* pCurrent = &(list->head);
    while(pCurrent->next)
    {
        pCurrent = pCurrent->next;
    }
    //更新指针，插入数据
    data->next = NULL;
    pCurrent->next = data;
    list->size++;
}


void InsertLinkList(LinkList* list,int pos, LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || data == NULL || pos > list->size || pos < -(list->size + 1))
        return ;
    if(pos < 0)
        pos = pos + list->size + 1;

    //定位到带插入的位置
    LinkNode* pCurrent = &(list->head);
    for(int i =0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }

    data->next = pCurrent->next;
    pCurrent->next = data;
    list->size++;

}

void RemoveByPosLinkList(LinkList* list, int pos)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0) || pos >= list->size || pos < -(list->size))
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
    if(list == NULL || (list->size == 0) || data == NULL || pos >= list->size || pos < -(list->size))
        return ;
    if(pos < 0)
        pos = pos + list->size;


}

void ChangeByValLinkList(LinkList* list,LinkNode* srcdata,LinkNode* dstdata){

    //判断传入的参数是否合法
    if(list == NULL || srcdata == NULL || dstdata == NULL)
        return ;
    LinkNode* pCurrent = &(list->head);
}

LinkNode* GetItemLinkList(LinkList* list,int pos)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0)  || pos >= list->size || pos < -(list->size))
        return NULL;
    if(pos < 0)
        pos = pos + list->size;
    //定位到指定位置
    LinkNode* pCurrent = &(list->head);
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    return pCurrent -> next;
}

int FindByPosLinkList(LinkList* list,LinkNode* data)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0) || data == NULL)
        return -1;
}

typedef void(*FUNC)(LinkNode*);
void TraverseLinkList(LinkList* list,FUNC func)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0))
        return ;
    //遍历链表中的每一个节点
    LinkNode* pCurrent = list->head.next;
    while(pCurrent != NULL)
    {
        func(pCurrent);
        pCurrent = pCurrent->next;
    }
}

int SizeLinkList(LinkList* list)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return -1;
    return list->size;
}

void FreeSpaceLinkList(LinkList* list)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return ;

    list->size = 0;
    free(list);
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
    if(data != NULL)
    {
        Student* p = (Student*)data;
        printf("Name = %s , Age = %d , Score = %d\n",p->name,p->age,p->score);
    }
}

int main(void)
{
    printf("这是一个普通企业链表的例程\n");

    Student s1 = {NULL,"aaa",11,66};
    Student s2 = {NULL,"bbb",22,77};
    Student s3 = {NULL,"ccc",33,88};
    Student s4 = {NULL,"ddd",44,99};
    Student s5 = {NULL,"eee",55,111};
    
    LinkList* list = InitLinkList();
   
    AppendLinkList(list,(LinkNode*)(&s1));
    AppendLinkList(list,(LinkNode*)(&s1));

    InsertLinkList(list,0,(LinkNode*)(&s3));
    InsertLinkList(list,0,(LinkNode*)(&s4));
    InsertLinkList(list,4,(LinkNode*)(&s5));
    
    
    printf("追加数据 size = %d\n",SizeLinkList(list));
    TraverseLinkList(list,PrintStudent);

    //PrintStudent(GetItemLinkList(list,6));


    FreeSpaceLinkList(list);
    return 0;
}
