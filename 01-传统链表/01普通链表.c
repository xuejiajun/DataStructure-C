#include<stdio.h>
#include<stdlib.h>

typedef struct LINKNODE
{
    struct LINKNODE* next;
    void* data;
}LinkNode;

typedef struct LINKLIST
{
    LinkNode* head;
    int size;
}LinkList;

//初始化一个链表
LinkList* InitLinkList(void)
{
    //创建一个链表
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;

    //创建一个头结点
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;
    
    //返回地址
    return list;
}

//为链表追加一个节点
void AppendLinkList(LinkList* list ,void* data)
{
    //判断参数是否合法
    if(list == NULL)
        return ;

    //封装数据data为一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->next = NULL;

    //定位到最后一个节点
    LinkNode* pCurrent = list->head;
    while(pCurrent->next != NULL)
    {
        pCurrent = pCurrent->next;
    }

    //更新指针
    pCurrent->next = pNode;
    
    list->size++;
}

//在指定位置插入
void InsertLinkList(LinkList* list,int pos,void* data)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size+1))
        return ;

    if(pos < 0)
        pos = pos + list->size + 1;

    //封装数据data为一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->next = NULL;
    
    //定位到要插入位置的前一个节点
    LinkNode* pCurrent = list->head;
    int i=0;
    for(i= 0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }

    //更新指针域
    pNode->next = pCurrent->next;
    pCurrent->next = pNode;
    list->size++;
}

//根据位置进行删除
void RemoveByPosLinkList(LinkList* list,int pos)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size))
        return ;
    
    if(pos<0)
        pos = pos + list->size;

    //定位到要插入位置的前一个节点
    LinkNode* pCurrent = list->head;
    int i=0;
    for(i= 0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    
    //保存要删除的节点地址
    LinkNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;//更新指针
    free(pDel);

    list->size--;
}

void RemoveByValLinkList(LinkList* list,void* data)
{
    //判断参数是否合法
    if(list == NULL)
        return ;

    //遍历每一个节点
    LinkNode* pPre = list->head;
    LinkNode* pCurrent = pPre->next;
    
    while(pCurrent != NULL)
    {
        LinkNode* pNext = pCurrent->next;
        if(pCurrent->data == data)
        {
            //更新指针删除pCurrent
	    LinkNode* pDel = pCurrent;
            pPre->next = pNext;
            pCurrent = pNext;
            free(pDel);
            list->size--;
            continue;
        }
        pPre = pCurrent;
        pCurrent = pNext;
    }
}

void ChangeByPosLinkList(LinkList* list,int pos,void* data)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size))
        return ;
    if(pos<0)
        pos = pos + list->size;
 
    //定位到待改变元素的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    { 
        pCurrent = pCurrent->next; 
    }
    pCurrent->next->data = data;  
}

void ChangeByValLinkList(LinkList* list,void* srcdata,void* dstdata)
{
    //判断参数是否合法
    if(list == NULL)
        return ;
    //遍历链表
    LinkNode* pCurrent = list->head;
    while(pCurrent != NULL)
    {
        if(pCurrent->data == srcdata)
        {
            pCurrent->data = dstdata;
        }
        pCurrent = pCurrent->next;
    }
}

void* GetItemLinkList(LinkList* list,int pos)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size))
        return NULL; 
    if(pos< 0)
        pos = pos + list->size;
    
    //定位到待改变元素的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    { 
        pCurrent = pCurrent->next; 
    }
    return pCurrent->next->data;
}

int FindByValLinkList(LinkList* list ,void*data)
{
    //判断参数是否合法
    if(list == NULL)
        return -1;

    //遍历列表
    LinkNode* pCurrent = list->head;
    int pos = 0;
    while(pCurrent != NULL)
    {
        
        if(pCurrent->data == data)
        {
            return pos;
        }
        pos++;
        pCurrent = pCurrent->next;
    }
    return -1;
}


//遍历链表
typedef void(*FUNC)(void*);
void TraverseLinkList(LinkList* list, FUNC func)
{    
    //判断参数是否合法
    if(list == NULL)
        return ;
    
    //遍历每个节点
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != NULL)
    {
        func(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

int SizeLinkList(LinkList* list)
{
    //判断参数是否合法
    if(list == NULL)
        return -1;
    return list->size;
}

void FreeSpaceLinkList(LinkList* list)
{
    //判断参数是否合法
    if(list == NULL)
        return ;
	LinkNode* pCurrent = list->head;
	while(pCurrent != NULL)
	{
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	free(list);
}

typedef struct STUDENT
{
    char name[20];
    int age ;
    int score;
}Student;

void PrintStudent(void*data)
{
    Student* p = (Student*)data;
    printf("Name = %s,Age = %d,Score = %d\n",p->name,p->age,p->score);
}


int main(void)
{
    printf("这是一个普通链表的例程\n");

    Student s1 = {"aaa",11,66};
    Student s2 = {"bbb",22,77};
    Student s3 = {"ccc",33,88};
    Student s4 = {"ddd",44,99};
    Student s5 = {"eee",55,111};

    LinkList* list = InitLinkList();

    AppendLinkList(list,&s1);
    AppendLinkList(list,&s1);
    AppendLinkList(list,&s2);
    AppendLinkList(list,&s3);
    AppendLinkList(list,&s4);
    AppendLinkList(list,&s5);
    AppendLinkList(list,&s5);

    printf("增加数据 size = %d\n", SizeLinkList(list) );
    TraverseLinkList(list,PrintStudent);

    RemoveByValLinkList(list,&s1);
    RemoveByValLinkList(list,&s5);
    RemoveByPosLinkList(list,-1);
    printf("删除数据 size = %d\n", SizeLinkList(list) ); 
    TraverseLinkList(list,PrintStudent);

    ChangeByValLinkList(list,&s2,&s5);
    ChangeByPosLinkList(list,0,&s1);
    printf("更改数据 size = %d\n", SizeLinkList(list) );
    TraverseLinkList(list,PrintStudent);

    printf("取出数据和查找数据 size = %d\n", SizeLinkList(list) );
    int pos2 = FindByValLinkList(list,&s1);
    printf("pos2 = %d\n",pos2);

    PrintStudent(GetItemLinkList(list,-1));
    
    printf("size = %d\n",SizeLinkList(list));

    FreeSpaceLinkList(list);
    return 0;
}
