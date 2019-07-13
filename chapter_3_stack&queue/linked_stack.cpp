typedef int ElemType;
typedef struct{
	ElemType data;
}LinkStNode;
void InitStack(LinkStNode * & s)
{
	s=(LinkStNode *)malloc(sizeof(LinkStNode));
	s->next=NULL;
}
void DestroyStack(LinkStNode * & s)
{
	LinkStNode *p,*pre;
	p=s->next;
	pre=s;
	while(p!=NULL)
	{
		free(pre);
		pre=p;
		p=p->next;
	}
	free(pre);
}
bool StackEmpty(LinkStNode * & s)
{
	return(s->next==NULL);
}
void Push(LinkStNode *& s,ElemType e)
{
	LinkStNode *p;
	p=(LinkStNode*)malloc(sizeof(LinkStNode));
	p->data=e;
	p->next=s->next;
	s->next=p;
}
bool Pop(LinkStNode * & s,ElemType &e)
{
	LinkStNode *p;
	if(s->next==NULL)
		return false;
	p=s->next;
	e=p->data;
	s->next=p->next;
	free(p);
	return true;
}
bool GetTop(LinkStNode *& s,ElemType &e)
{
	if(s->next==NULL)
		return false;
	e=s->next->data;
	return true;
}


















