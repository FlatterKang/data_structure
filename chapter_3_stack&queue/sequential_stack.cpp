#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
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
	if(-1=s->top)
		return false;
	e=s->data[s->top];
	return true;
}


















