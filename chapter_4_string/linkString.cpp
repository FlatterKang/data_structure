#include<iostream>
using namespace std;

typedef struct snode
{
    char data;
    struct snode *next;
} LinkStrNode;

void StrAssign(LinkStrNode * &s, char cstr[])

void DestroyStr(LinkStrNode * &s)

void StrCopy(LinkStrNode * &s, LinkStrNode * &t)

void StrEqual(LinkStrNode * s, LinkStrNode *t)

int Strlength(LinkStrNode * s)

LinkStrNode * Concat(LinkStrNode *s, LinkStrNode *t) //返回一个串的指针

