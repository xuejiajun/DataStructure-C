#include<stdio.h>
#include<stdlib.h>

#define STACK_MAX_ITEM   1024
typedef struct STACKDEQ
{
	int size;
	void* stack[STACK_MAX_ITEM];
}StackDeq;

StackDeq* InitStackDeq(void)
{
	StackDeq* stack = (StackDeq*)malloc(sizeof(StackDeq));
	stack->size = 0;
	return stack;
}

//压栈
void PushStackDeq(StackDeq* stack, void* data)
{
	//判断传入的参数是否合法
	if (stack == NULL)
		return;
	stack->stack[stack->size] = data;
	stack->size++;
}

//返回栈顶元素
void* TopStackDeq(StackDeq* stack)
{
	//判断传入的参数是否合法
	if (stack == NULL)
		return NULL;

	return stack->stack[stack->size - 1];
}

//出栈
void PopStackDeq(StackDeq* stack)
{
	//判断传入的参数是否合法
	if (stack == NULL)
		return;

	stack->stack[stack->size - 1] = NULL;
	stack->size--;
}

//返回栈中元素个数
int SizeStackDeq(StackDeq* stack)
{
	//判断传入的参数是否合法
	if (stack == NULL)
		return -1;
	return stack->size;
}

//判断栈是否为空
int IsEmptyStackDeq(StackDeq* stack)
{
	//判断传入的参数是否合法
	if (stack == NULL)
		return -1;
	return (stack->size == 0);
}

//释放栈空间
void FreeSpaceStackDeq(StackDeq* stack)
{
	//判断传入的参数是否合法
	if (stack == NULL)
		return;
	free(stack);
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
	printf("Name = %s , Age = %d , Score = %d\n", p->name, p->age, p->score);
}



int main(void)
{
	printf("这是一个顺序栈的例程\n");

	Student s1 = { "aaa",11,66 };
	Student s2 = { "bbb",22,77 };
	Student s3 = { "ccc",33,88 };
	Student s4 = { "ddd",44,99 };
	Student s5 = { "eee",55,111 };

	StackDeq* stack = InitStackDeq();

	PushStackDeq(stack, &s1);
	PushStackDeq(stack, &s2);
	PushStackDeq(stack, &s3);
	PushStackDeq(stack, &s4);
	PushStackDeq(stack, &s5);

	while (!IsEmptyStackDeq(stack))
	{
		void* p = TopStackDeq(stack);
		PrintStudent(p);
		PopStackDeq(stack);
		int size = SizeStackDeq(stack);
		printf("stack-size = %d\n", stack->size);
	}
	FreeSpaceStackDeq(stack);
	return 0;
}
