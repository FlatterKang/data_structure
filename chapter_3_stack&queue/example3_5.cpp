/*
利用链栈
设计一个算法
判断圆括号是否配对
输入：字符数组和字符串的长度n
输出：返回true/false
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

#define Maxsize 100
typedef char ElemType;
typedef struct linknode{
    ElemType data;
    struct linknode *next;
} LinkStNode;

void InitStack(LinkStNode * & s)
{
    s = (LinkStNode *)malloc(sizeof(LinkStNode));
    s->next = NULL;
}
void DestroyStack(LinkStNode * & s)
{
    LinkStNode *p, *pre;
    p = s->next;
    pre = s;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}
bool StackEmpty(LinkStNode * & s)
{
    return (s->next == NULL);
}
void Push(LinkStNode *& s, ElemType e)
{
    LinkStNode *p;
    p = (LinkStNode*)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = s->next;
    s->next = p;
}
bool Pop(LinkStNode * & s, ElemType &e)
{
    LinkStNode *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}
bool GetTop(LinkStNode *& s, ElemType &e)
{
    if (s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}

bool Match(char exp[], int n)
{
    ElemType e;
    int i;
    bool match = true;
    LinkStNode * st;
    InitStack(st);
    for (i = 0; i < n && match == true; i++)
    {
        if ('(' == exp[i])
            Push(st, exp[i]);
        if (')' == exp[i])
        {
            if (!StackEmpty(st))
                Pop(st, e);
            else
                match = false;
        }
    }
    if (!StackEmpty(st))
        match = false;
    DestroyStack(st);
    return match;
}

int main()
{
	int n;
	char str[Maxsize];
	scanf("%s",str);
	n=sizeof(str);
	if(Match(str,n))
		printf("该字符串左右括号匹配！\n");
	else
		printf("该字符串左右括号不匹配！\n");
	return 0;
}






















