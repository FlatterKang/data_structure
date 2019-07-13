/*例3.4：利用顺序栈判断一个字符串是否为顺序串
         实参：一个字符串数组
         返回值：true/false*/
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack * &s)
{
	s=(SqStack*)malloc(sizeof(SqStack));
	s->top=-1;
}
void DestroyStack(SqStack * &s)
{
	free(s);
}
bool StackEmpty(SqStack *s)
{
	return (s->top==-1);
}
bool Push(SqStack * &s,ElemType e)
{
	if(MaxSize-1==s->top)
		return false;
	++s->top;
	s->data[s->top]=e;
	return true;
}
bool Pop(SqStack * &s,ElemType &e)
{
	if(-1==s->top)
		return false;
	e=s->data[s->top];
	--s->top;
	return true;
}
bool GetTop(SqStack *s,ElemType &e)
{
	if(-1==s->top)
		return false;
	e=s->data[s->top];
	return true;
}
bool symmetry(ElemType str[])
{
	int i;
	ElemType e;
	SqStack *st;
	InitStack(st);
	for(i=0;str[i]!='\0';i++)   //把字符串全部进栈
		Push(st,str[i]);
	for(i=0;str[i]!='\0';i++)
	{
		Pop(st,e);
		if(str[i]!=e)
		{
			DestroyStack(st);
			return false;
		}
	}
	DestroyStack(st);
	return true;
}

int main()
{
	int flag;
	char str[MaxSize];
	gets(str);
	if(symmetry(str))
		printf("该串为对称串！\n");
	else
		printf("该串为非对称串！\n");
	return 0;
}

//2019 07 07 11:07