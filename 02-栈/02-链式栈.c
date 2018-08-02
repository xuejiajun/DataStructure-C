#include<stdio.h>
#include<stdlib.h>

typedef struct LINKNODE
{
    struct LINKNODE* next;
    void* data;
}LinkNode;

typedef struct STACK
{
    LinkNode* head;
    int size;
    
}StackLink;


//初始化一个栈
StackLink* InitStackLink(void)
{
    StackLink* stack = (StackLink*)malloc(sizeof(StackLink));
    stack->size = 0;
    stack->head = (LinkNode*)malloc(sizeof(LinkNode));
    
    stack->head->next = NULL;
    stack->head->data = NULL;

    return stack;
}

//压栈:列表的头部作为栈顶，尾部作为栈底，每次操作只操作头部的下一个节点即可
void PushStackLink(StackLink* stack,void* data)
{
    //判断传入的参数是否合法
    if(stack == NULL)
        return ;

    //封装data为一个节点
    LinkNode* pNode = (LinkNode*)malloc(sizeof(LinkNode));
    pNode->data = data;
    pNode->next = NULL;

    //将pNode插入到头结点的下一个位置
    LinkNode* pCurrent = stack->head;
    LinkNode* pNext = pCurrent->next;

    pNode->next = pNext;
    pCurrent->next = pNode;
    
    stack->size++;
}

//出栈
void PopStackLink(StackLink* stack)
{
    //判断传入的参数是否合法
    if(stack == NULL)
        return ;

    //删除头结点的下一个元素
    LinkNode* pCurrent = stack->head;
    LinkNode* pDel = pCurrent->next;
    LinkNode* pNext = pDel->next;
    pCurrent->next = pNext;
    free(pDel);

    stack->size--;
}

//返回栈顶元素
void* TopStackLink(StackLink* stack)
{
    //判断传入的参数是否合法
    if(stack == NULL)
        return NULL;
    
    return stack->head->next->data;
}

//返回栈中元素的个数
int SizeStackLink(StackLink* stack)
{
    //判断传入的参数是否合法
    if(stack == NULL)
        return -1;
    return stack->size;
}

int IsEmptyStackLink(StackLink* stack)
{
    if(stack == NULL)
        return -1 ;
    return (stack->size == 0);
}
//释放栈空间
void FreeSpaceStackLink(StackLink* stack)
{
    //判断传入的参数是否合法
    if(stack == NULL)
        return ;

    //释放栈中的节点
    LinkNode* pCurrent = stack->head;
    while(pCurrent != NULL)
    {
        LinkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
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
    printf("这是一个链式栈的例程\n");
    
    Student s1 = {"aaa",11,66};
    Student s2 = {"bbb",22,77};
    Student s3 = {"ccc",33,88};
    Student s4 = {"ddd",44,99};
    Student s5 = {"eee",55,111};

    StackLink* stack = InitStackLink();
    
    PushStackLink(stack,&s1);
    PushStackLink(stack,&s2);
    PushStackLink(stack,&s3);
    PushStackLink(stack,&s4);
    PushStackLink(stack,&s5);

    while(!IsEmptyStackLink(stack) )
    {
        void* p = TopStackLink(stack);
        PrintStudent(p);
        PopStackLink(stack);
        int size = SizeStackLink(stack);
        printf("stack-size:%d\n",size);
    }
    FreeSpaceStackLink(stack);
    return 0;
}

