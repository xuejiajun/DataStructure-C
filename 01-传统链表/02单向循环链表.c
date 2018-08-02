#include<stdio.h>
#include<stdlib.h>

typedef struct LINKNODE
{
    struct LINKNODE* next;
    void* data;
}LinkNode;

typedef struct CIRLINKLIST
{
    LinkNode* head;
    int size;
}CirLinkList;

//初始化一个链表
CirLinkList* InitCirLinkList(void)
{
    //创建一个链表
    CirLinkList* list = (CirLinkList*)malloc(sizeof(CirLinkList));
    list->size = 0;

    //创建一个头结点
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = list->head;//自己指向自己
    
    //返回地址
    return list;
}

//为链表追加一个节点
void AppendCirLinkList(CirLinkList* list ,void* data)
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
    while(pCurrent->next != list->head)
    {
        pCurrent = pCurrent->next;
    }

    //更新指针
    pNode->next = pCurrent->next;//pNode->next = list->head;
    pCurrent->next = pNode;
    
    list->size++;
}

//在指定位置插入
void InsertCirLinkList(CirLinkList* list,int pos,void* data)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size + 1))
        return ;
    if(pos<0)
        pos = pos + list->size+1;

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
void RemoveByPosCirLinkList(CirLinkList* list,int pos)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size))
        return ;
    if(pos<0)
        pos = pos+list->size;

    //定位到要插入位置的前一个节点
    LinkNode* pCurrent = list->head;
    for(int i= 0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    
    //保存要删除的节点地址
    LinkNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;//更新指针
    free(pDel);

    list->size--;
}

void RemoveByValCirLinkList(CirLinkList* list,void* data)
{
    //判断参数是否合法
    if(list == NULL)
        return ;

    //遍历每一个节点
    LinkNode* pPre = list->head;
    LinkNode* pCurrent = pPre->next;
    while(pCurrent != list->head)
    {   
        LinkNode* pNext = pCurrent->next;
        if(pCurrent->data == data)
        {	
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

void ChangeByPosCirLinkList(CirLinkList* list,int pos,void* data)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size))
        return ;
    if(pos<0)
        pos = pos+list->size;
    //定位到待改变元素的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i= 0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    pCurrent->next->data = data;
}

void ChangeByValCirLinkList(CirLinkList* list,void* srcdata,void* dstdata)
{
    //判断参数是否合法
    if(list == NULL)
        return ;
   
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != list->head)
    {
       if(pCurrent->data == srcdata)
       {
           pCurrent->data = dstdata;
       }
       pCurrent = pCurrent->next;
    }
}

void* GetItemCirLinkList(CirLinkList* list,int pos)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size))
        return NULL ;
    if(pos<0)
        pos = pos+list->size;

    //定位到待改变元素的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i= 0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    return pCurrent->next->data;
}

int FindByValCirLinkList(CirLinkList* list ,void*data)
{
    //判断参数是否合法
    if(list == NULL)
        return -1;

    //遍历列表
    LinkNode* pCurrent = list->head->next;
    int pos = 0;
    while(pCurrent != list->head)
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
void TraverseCirLinkList(CirLinkList* list, FUNC func)
{    
    //判断参数是否合法
    if(list == NULL)
        return ;
    
    //遍历每个节点
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != list->head)
    {
        func(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

int SizeCirLinkList(CirLinkList* list)
{
    //判断参数是否合法
    if(list == NULL)
        return -1;
    return list->size;
}

void FreeSpaceCirLinkList(CirLinkList* list)
{
    //判断参数是否合法
    if(list == NULL)
        return ;
    
    //遍历每个节点
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != list->head)
    { 
        LinkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    //释放头结点
    free(list->head);
    //释放链表
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
    printf("这是一个单向循环链表的例程\n");

    Student s1 = {"aaa",11,66};
    Student s2 = {"bbb",22,77};
    Student s3 = {"ccc",33,88};
    Student s4 = {"ddd",44,99};
    Student s5 = {"eee",55,111};

    CirLinkList* list = InitCirLinkList();


    AppendCirLinkList(list,&s1);
    AppendCirLinkList(list,&s1);
    AppendCirLinkList(list,&s2);
    AppendCirLinkList(list,&s3);
    AppendCirLinkList(list,&s4);
    AppendCirLinkList(list,&s5);
    AppendCirLinkList(list,&s5);

  
    printf("增加数据 size = %d\n", SizeCirLinkList(list) );
    TraverseCirLinkList(list,PrintStudent);

    RemoveByValCirLinkList(list,&s1);
    RemoveByValCirLinkList(list,&s5);
    RemoveByPosCirLinkList(list,-1);
    printf("删除数据 size = %d\n", SizeCirLinkList(list) ); 
    TraverseCirLinkList(list,PrintStudent);

    ChangeByValCirLinkList(list,&s2,&s5);
    ChangeByPosCirLinkList(list,0,&s1);
    printf("更改数据 size = %d\n", SizeCirLinkList(list) );
    TraverseCirLinkList(list,PrintStudent);

    printf("取出数据和查找数据 size = %d\n", SizeCirLinkList(list) );
    int pos2 = FindByValCirLinkList(list,&s1);
    printf("pos2 = %d\n",pos2);

    PrintStudent(GetItemCirLinkList(list,-1));
    
    printf("size = %d\n",SizeCirLinkList(list));

    FreeSpaceCirLinkList(list);
    return 0;
}
