#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
typedef struct LINKNODE
{
    struct LINKNODE* next;
    void* data;
}LinkNode;

typedef struct QUEUQLINK
{
    LinkNode* head;
    int size;
}QueueLink;

//初始化一个队列
QueueLink* InitQueueLink(void)
{
    //为队列分配空间并填充成员
    QueueLink* queue = (QueueLink*)malloc(sizeof(QueueLink));
    queue->size = 0;
    queue->head = (LinkNode*)malloc(sizeof(LinkNode));
    //为头结点填充数据
    queue->head->data = NULL;
    queue->head->next= NULL;

    return queue;
}

//向队列中添加数据
//链表的头作为队列的头，取出数据
//链表的尾作为队列的尾，插入数据
void PushQueueLink(QueueLink* queue,void*data)
{
    //判断传入的参数是否合法
    if(queue == NULL)
        return ;
    
    //为data封装为一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->next = NULL;

    //定位到链表的尾部，插入数据
    LinkNode* pCurrent = queue->head;
    while(pCurrent->next != NULL)
    {
        pCurrent = pCurrent->next;
    }

    //更新指针，插入数据
    pCurrent->next = pNode;
    pNode->next = NULL;
    queue->size++;
}

//取出对头元素
void* TopQueueLink(QueueLink* queue)
{
    //判断传入的参数是否合法
    if(queue == NULL)
        return NULL;
     return queue->head->next->data;
}

//弹出队头元素
void PopQueueLink(QueueLink* queue)
{
    //判断传入的参数是否合法
    if(queue == NULL)
        return ;
    
    LinkNode* pCurrent = queue->head;
    LinkNode* pDel = pCurrent->next;
    LinkNode* pNext = pDel->next;
    //更新指针
    pCurrent->next = pNext;
    free(pDel);
    queue->size--;
}

//返回队列中元素个数
int SizeQueueLink(QueueLink* queue)
{
    //判断传入的参数是否合法
    if(queue == NULL)
        return -1;
    return queue->size;
}

//判断是否为空队列
int IsEmptyQueueLink(QueueLink* queue)
{
    //判断传入的参数是否合法
    if(queue == NULL)
        return -1;
    return (queue->size == 0);
}

//销毁一个队列
void FreeSpaceQueueLink(QueueLink* queue)
{
    //判断传入的参数是否合法
    if(queue == NULL)
        return ;

    LinkNode* pCurrent = queue->head;
    while(pCurrent != NULL)
    {
        LinkNode* pNext = pCurrent->next;
        free(pCurrent);
        pNext = pCurrent;
    }
    free(queue->head);
    free(queue);
}

typedef struct STUDENT
{
    char name[40];
    int age;
    int score;
}Student;

void PrintStudent(void* data)
{
    Student* p = (Student*)data;
    printf("Name = %s , Age = %d , Score = %d\n",p->name,p->age,p->score);
}
int main(void)
{
    printf("这是一个链式队列的例程\n");
    
    Student s1 = {"aaa",11,66};
    Student s2 = {"bbb",22,77};
    Student s3 = {"ccc",33,88};
    Student s4 = {"ddd",44,99};
    Student s5 = {"eee",55,111};

    QueueLink* queue = InitQueueLink();

    PushQueueLink(queue,&s1);
    PushQueueLink(queue,&s2);
    PushQueueLink(queue,&s3);
    PushQueueLink(queue,&s4);
    PushQueueLink(queue,&s5);

    int size = SizeQueueLink(queue);
    printf("Queue-size = %d\n",size);

    while(!IsEmptyQueueLink(queue))
    {
        void* p = TopQueueLink(queue);
        PrintStudent(p);
        int size = SizeQueueLink(queue);
        printf("Queue-size = %d\n",size);
        PopQueueLink(queue);
        //sleep(1);
    }

   // FreeSpaceQueueLink(queue);
    return 0;
}
