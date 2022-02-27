#include <stdio.h>
#include <stdlib.h>
//利用栈的特性
#define maxSize 10
#define maxSIZE 100
typedef struct SequenceStack {
	char* top;
	char* end;
	int size;//记录栈的数据个数
	int maxsize;//记录栈的最大容量
}Stack;
int test=1;
void menu();//主界面
void InitStack(Stack* stack);//初始化顺序栈
void insert(Stack* stack, char key);//入栈
void delete_stack(Stack* stack);//出栈
int judge(Stack* stack, char* temp);//判断题目是否正确
int main()
{
	while(1)
	{
		menu();
	}
	return 0;
}
void menu()
{
	int i = 0;
	printf("请输入题目:");
	Stack stack;
	InitStack(&stack);
	char temp[maxSIZE];
	gets(temp);
	while(temp[i]!='\0')//左括号入栈
	{
		if (temp[i] == '(')
		{
	    	insert(&stack, temp[i]);
	    }
	    i++;
	}
	if (judge(&stack, temp))
	{
		printf("题目正确\n");
	}
	else
	{
		printf("错误\n");
	}
}
void InitStack(Stack* stack)
{

	stack->end = (char*)malloc(sizeof(char));
	if (!stack->end)//判断
	{
		printf("内存分配失败");
		exit(0);
	}
	else
	{
		stack->top = stack->end;
		stack->size = 0;
		stack->maxsize = maxSize;
	}
}
void insert(Stack* stack,char key)
{
	if (!stack->end)//判断
	{
		printf("未初始化");
		exit(0);
	}
	if (stack->size==stack->maxsize)//判断是否栈满，栈满就扩容
	{
		char* temp = stack->end;
		stack->maxsize += maxSize;
		stack->top++;
		*stack->top = key;
		stack->size++;
	}
	else
	{
		stack->top++;
		stack->top = key;//数据入栈
		stack->size++;
	}
}
void delete_stack(Stack* stack)
{
	if (!stack->end)//判断
	{
		printf("未初始化");
		exit(0);
	}
	if (stack->end == stack->top)//判断是否栈空
	{
		printf("栈空无法删除");
		exit(0);
	}
	else
	{
		stack->top--;
		stack->size--;
	}
}
int judge(Stack* stack, char* temp)
{
	char* move = stack->end;
	int i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == ')')
		{
			delete_stack(stack);
		}
		i++;
	}
	if (stack->top == stack->end)
		return 1;
	return 0;
}