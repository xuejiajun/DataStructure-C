#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


typedef struct CYCQUEUE
{
    int size;
    int front;
    int rear;
    void* data[MAXSIZE];
}CycQueue;

//初始化一个队列

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
