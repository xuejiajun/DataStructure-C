#include<stdio.h>
#include<stdlib.h>

typedef struct LINKNODE
{
    struct LINKNODE* prior;
    struct LINKNODE* next;
    void* data;
}LinkNode;

typedef struct DCIRLINKLIST
{
    LinkNode* head;
    int size;
}DCirLinkList;


//初始化链表
DCirLinkList* InitDCirLinkList(void)
{
    //创建一个链表，填充成员数据
    DCirLinkList* list = (DCirLinkList*)malloc(sizeof(DCirLinkList));
    list->size = 0;
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
   
   //头结点指向自己
    list->head->data = NULL;
    list->head->prior = list->head;
    list->head->next = list->head;
    
    return list;
}

//追加数据
void AppendDCirLinkList(DCirLinkList* list,void* data)
{
    //判断传入的参数
    if(list == NULL)
        return ;

    //把data封装成一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->prior = NULL;
    pNode->next = NULL;

    //定位到最后一个节点
    LinkNode* pCurrent = list->head;
    while(pCurrent->next != list->head)
    {
        pCurrent = pCurrent->next;
    }

    //更新指针，添加节点
    LinkNode* pNext = pCurrent->next;
    pNode->next = pNext;
    pNext->prior = pNode;
    pNode->prior = pCurrent;
    pCurrent->next = pNode;
    list->size++;
}

//在指定位置插入数据
void InsertDCirLinkList(DCirLinkList* list,int pos,void* data)
{
    //判断参数是否合法
    if(list == NULL || pos > list->size || pos < -(list->size + 1))
        return ;
    
    if(pos<0)
        pos = list->size + pos + 1;

    //把data封装成一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->prior = NULL;
    pNode->next = NULL;

    //定位到待插入位置的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;    
    }

    //更新指针，插入数据
    LinkNode* pNext = pCurrent->next;
    pNode->next = pNext;
    pNext->prior = pNode;
    pNode->prior = pCurrent;
    pCurrent->next = pNode;

    list->size++;
}

void RemoveByPosDCirLinkList(DCirLinkList* list,int pos)
{
    //判断参数是否合法
    if(list == NULL || pos >= list->size || pos < -(list->size))
        return ;
    
    if(pos<0)
        pos = list->size + pos;
    //定位到带删除节点的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }

    //更新指针，完成删除
    LinkNode* pDel = pCurrent->next;
    LinkNode* pNext = pDel->next;
    pCurrent->next = pNext;
    pNext->prior = pCurrent;
    free(pDel);
    list->size--;
}

void RemoveByValDCirLinkList(DCirLinkList* list,void* data)
{
    //判断参数是否合法
    if(list == NULL)
        return ;
  
    //遍历节点
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != list->head)
    {
        LinkNode* pPre = pCurrent->prior;
        LinkNode* pNext = pCurrent->next;
        if(pCurrent->data == data)
        {
            LinkNode* pDel = pCurrent;
            pPre->next = pNext;
            pNext->prior = pPre;
            free(pDel);
            list->size--;
        }
        pCurrent = pNext;
    }
}

//修改指定位置的值
void ChangeByPosDCirLinkList(DCirLinkList* list,int pos,void* data)
{
    //判断参数是否合法
    if(list == NULL || pos >= list->size || pos < -(list->size))
        return ;

    if(pos<0)
        pos = pos + list->size;

    //定位到要修改的位置的前一个节点
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    LinkNode* pChange = pCurrent->next;
    pChange->data = data;
}

//根据值进行修改
void ChangeByValDCirLinkList(DCirLinkList* list,void* srcdata,void* dstdata)
{
    //判断参数是否合法
    if(list == NULL)
        return ;

    //遍历列表
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


//根据位置查找某元素
void* GetItemDCirLinkList(DCirLinkList* list,int pos)
{
    //判断参数是否合法
    if(list == NULL || pos >= list->size || pos < -(list->size))
        return (void*)-1;
    
    if(pos<0)
        pos = pos+list->size;

    //定位到指定位置
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next; 
    }
    return pCurrent->next->data;
}

//根据值查找
int FindByValDCirLinkList(DCirLinkList* list,void* data)
{
    //判断参数是否合法
    if(list == NULL)
        return -1;

    //遍历列表，寻找数据相等的节点
    int pos=0;
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != list->head)
    {
        if(pCurrent->data == data)
        {
            return pos;
        }
        pos++;
        pCurrent = pCurrent->next;    
    }
}

//顺序遍历链表
typedef void(*FUNC)(void*);
void TraverseDCirLinkList(DCirLinkList* list,FUNC func)
{
    //判断参数是否合法
    if(list == NULL)
        return ;

    //为每一个节点的数据执行func函数
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != list->head)
    {
        func(pCurrent->data);
        pCurrent = pCurrent->next;
        
    }
}
//逆序遍历列表
void ClockTraverseDCirLinkList(DCirLinkList* list,FUNC func)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return ;

    //为每一个节点的数据执行func函数
    LinkNode* pCurrent = list->head->prior;
    while(pCurrent != list->head)
    {
        func(pCurrent->data);
        pCurrent = pCurrent->prior;
    }
}


int SizeDCirLinkList(DCirLinkList* list)
{
    if(list == NULL)
        return -1;
    return list->size;
}

void FreeSpaceDCirLinkList(DCirLinkList* list)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return ;
    LinkNode* pCurrent = list->head->next;
    //释放链表中的每一个节点，除头节点
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
    printf("这是一个双向循环链表的例程\n");

    Student s1 = {"aaa",11,66};
    Student s2 = {"bbb",22,77};
    Student s3 = {"ccc",33,88};
    Student s4 = {"ddd",44,99};
    Student s5 = {"eee",55,111};

  DCirLinkList* list = InitDCirLinkList();


    AppendDCirLinkList(list,&s1);
    AppendDCirLinkList(list,&s1);
    AppendDCirLinkList(list,&s2);
    AppendDCirLinkList(list,&s3);
    AppendDCirLinkList(list,&s4);
    AppendDCirLinkList(list,&s5);
    AppendDCirLinkList(list,&s5);

  
    printf("增加数据 size = %d\n", SizeDCirLinkList(list) );
    TraverseDCirLinkList(list,PrintStudent);

    RemoveByValDCirLinkList(list,&s1);
    RemoveByValDCirLinkList(list,&s5);
    RemoveByPosDCirLinkList(list,-1);
    printf("删除数据 size = %d\n", SizeDCirLinkList(list) ); 
    TraverseDCirLinkList(list,PrintStudent);

    ChangeByValDCirLinkList(list,&s2,&s5);
    ChangeByPosDCirLinkList(list,0,&s1);
    printf("更改数据 size = %d\n", SizeDCirLinkList(list) );
    TraverseDCirLinkList(list,PrintStudent);

    printf("取出数据和查找数据 size = %d\n", SizeDCirLinkList(list) );
    int pos2 = FindByValDCirLinkList(list,&s1);
    printf("pos2 = %d\n",pos2);

    PrintStudent(GetItemDCirLinkList(list,-1));
    
    printf("size = %d\n",SizeDCirLinkList(list));

    FreeSpaceDCirLinkList(list);
    return 0;
}
