#include<stdio.h>
#include<stdlib.h>


typedef struct LINKNODE
{
    struct LINKNODE* prior;
    struct LINKNODE* next;
    void* data;
}LinkNode;

typedef struct DLINKNODE
{
    LinkNode* head;
    int size;
}DLinkList;


//初始化链表
DLinkList* InitDLinkList(void)
{
    //创建一个链表，并填充数据
    DLinkList* list = (DLinkList*)malloc(sizeof(DLinkList));
    list->size = 0;
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    
    //填充头结点数据
    list->head->data = NULL;
    list->head->prior = NULL;
    list->head->next = NULL;

    return list;
}


void AppendDLinkList(DLinkList* list,void* data)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return ;
    
    //封装data为一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->prior = NULL;
    pNode->next = NULL;

    //定位到最后一个节点
    LinkNode* pCurrent = list->head;
    while(pCurrent->next != NULL)
    {
        pCurrent = pCurrent->next;
    }

    //更新指针，插入数据
    pNode->next = NULL;
    pNode->prior = pCurrent;
    pCurrent->next = pNode;

    list->size++;
}

//在指定位置插入元素
void InsertDLinkList(DLinkList* list,int pos,void* data)
{
    //检查参数是否合法
    if(list == NULL || pos>list->size || pos<-(list->size+1))
        return ;
    
    //如果插入到最后一个节点的后面，相当于追加
    if(pos == -1 || pos == list->size)
    {
        AppendDLinkList(list,data);
        return ;
    }

    if(pos<0)
        pos = pos + list->size + 1;

    //把data封装为一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->next = NULL;
    pNode->prior = NULL;

    
    //定位到要插入元素的位置的前一个
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    
    //更新指针，插入数据
    LinkNode* pNext  = pCurrent->next;
    pNode->next = pNext;
    pNext->prior = pNode;
    pNode->prior = pCurrent;
    pCurrent->next = pNode;

    list->size++;  
}


void RemoveByPosDLinkList(DLinkList* list,int pos)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0) || pos>=(list->size) || pos<-(list->size))
        return ;

    if(pos<0)
        pos = pos + list->size;

    //定位到要删除节点的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    
    //更新指针，删除节点
    LinkNode* pDel = pCurrent->next;
    LinkNode* pNext = pDel->next;

    pCurrent->next = pNext;
    if(pNext != NULL)
    {
        pNext->prior = pCurrent;
        printf("删除的不是最后一个元素\n");
        
    }//如果不是最后一个元素，需要维护prior指针
   
    free(pDel);
    list->size--;
}



void RemoveByValDLinkList(DLinkList* list,void* data)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0))
        return ;
    
    //遍历节点
    LinkNode* pPre = list->head;
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != NULL)
    {
        LinkNode* pNext = pCurrent->next;
        if(pCurrent->data == data)
        {   //保存一下要删除元素的地址
            LinkNode* pDel = pCurrent;
            pPre->next = pNext;
            if(pNext != NULL)
                pNext->prior = pPre;
            pCurrent = pNext;
	    free(pDel);
            list->size--;
            continue;
        }
        pPre = pCurrent;
        pCurrent = pCurrent->next;    
    }
}

void ChangeByPosDLinkList(DLinkList* list,int pos,void* data)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0) || pos>=(list->size) || pos<-(list->size))
        return ;
    
    if(pos<0)
        pos = pos + list->size;

    //定位到要改的元素的前一个节点
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    //改变数据
    LinkNode* pChange = pCurrent->next;
    pChange->data = data;
}

void ChangeByValDLinkList(DLinkList* list,void* srcdata,void* dstdata)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0))
        return ;

    //遍历每一个节点
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

//取出链表中某个节点的元素
void* GetItemDLinkList(DLinkList* list,int pos)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0) || pos>=(list->size) || pos<-(list->size))
        return NULL;
    
    if(pos<0)
        pos = pos + list->size;
    
    //定位到要查找的节点的前一个位置
    LinkNode* pCurrent = list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent = pCurrent->next;
    }
    return pCurrent->next->data;
}

//根据值查找
int FindByValDLinkList(DLinkList* list,void*data)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0))
        return -1;
    
    //遍历列表查找
    LinkNode* pCurrent = list->head->next;
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

//链表中的节点的个数
int SizeDLinkList(DLinkList* list)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return -1;
    return list->size;
}

typedef void (*FUNC)(void*);
void TraverseDLinkList(DLinkList* list,FUNC func)
{
    //判断传入的参数是否合法
    if(list == NULL || (list->size == 0))
        return ;
   
   //为每一个节点的数据执行func
   LinkNode* pCurrent = list->head->next;
   while(pCurrent != NULL)
   {
        func(pCurrent->data);
        pCurrent = pCurrent->next;   
   }
}


//销毁一个链表
void FreeSpaceDLinkList(DLinkList* list)
{
    //判断传入的参数是否合法
    if(list == NULL)
        return ;

    //逐个释放链表中的节点
    LinkNode* pCurrent = list->head;
    if(pCurrent != NULL)
    {
        LinkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;    
    }
    //释放链表
    list->size = 0;
    free(list);
}



typedef struct STUDENT
{
    char name[40];
    int age;
    int score;
}Student;

void PrintStudent(void* data)
{
	if(data != NULL)
	{
		Student* p = (Student*)data;
    	printf("Name = %s , Age = %d , Score = %d\n",p->name,p->age,p->score);
	}

}

int main(void)
{
    printf("这是一个双向链表的例程\n");

      printf("这是一个单向循环链表的例程\n");

    Student s1 = {"aaa",11,66};
    Student s2 = {"bbb",22,77};
    Student s3 = {"ccc",33,88};
    Student s4 = {"ddd",44,99};
    Student s5 = {"eee",55,111};

    DLinkList* list = InitDLinkList();

    AppendDLinkList(list,&s1);
    AppendDLinkList(list,&s1);
    AppendDLinkList(list,&s2);
    AppendDLinkList(list,&s3);
    AppendDLinkList(list,&s4);
    AppendDLinkList(list,&s5);
    AppendDLinkList(list,&s5);



    printf("增加数据 size = %d\n", SizeDLinkList(list));
    TraverseDLinkList(list,PrintStudent);

    //RemoveByValDLinkList(list,&s5);
    RemoveByValDLinkList(list,&s1);
    RemoveByPosDLinkList(list,-1);
    printf("删除数据 size = %d\n", SizeDLinkList(list) ); 
    TraverseDLinkList(list,PrintStudent);

    ChangeByValDLinkList(list,&s2,&s5);
    ChangeByPosDLinkList(list,0,&s1);
    printf("更改数据 size = %d\n", SizeDLinkList(list) );
    TraverseDLinkList(list,PrintStudent);

    printf("取出数据和查找数据 size = %d\n", SizeDLinkList(list) );
    int pos2 = FindByValDLinkList(list,&s1);
    printf("pos2 = %d\n",pos2);

    PrintStudent(GetItemDLinkList(list,-1));
    
    printf("size = %d\n",SizeDLinkList(list));

    FreeSpaceDLinkList(list);
    return 0;

}
