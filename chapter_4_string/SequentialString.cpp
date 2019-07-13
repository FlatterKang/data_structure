#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100

typedef struct {
    char data[MaxSize];
    int length;
} SqString;

void StrAssign(SqString &s, char cstr[])
{
    int i = 0;
    while ((s.data[i] = cstr[i]) != '\0')
        i++;
    s.length = i;
}

void DestroyStr(SqString &s)
{}

void StrCopy(SqString &s, SqString t)
{
    int i = 0;
    while ((s.data[i] = t.data[i]) != '\0')
        i++;
    s.length = t.length;
}

bool StrEqual(SqString s, SqString t)
{
    int i = 0;
    if (s.length != t.length)
        return false;
    else
    {
        while (s.data[i] == t.data[i] && s.data[i] != '\0')
            i++;
        if (s.data[i] != '\0')
            return false;
    }
    return true;
}

int StrLength(SqString s)
{
    return s.length;
}

SqString Concat(SqString s, SqString t)
{
    int i;
    SqString str;
    for (i = 0; i < s.length; i++)
        str.data[i] = s.data[i];
    for (i = 0; i < t.length; i++)
        str.data[i + s.length] = t.data[i];
    str.data[i] = '\0';
    str.length = s.length + t.length;
    return str;
}

SqString SubStr(SqString s, int i, int j)
{
    SqString str;
    int k;
    for (k = 0; k < j; k++)
    {
        str.data[k] = s.data[i - 1 + k];
    }
    str.data[k]='\0';
    str.length = j;
    return str;
}

SqString InsStr(SqString s1, int i, SqString s2)
{
	SqString str;
	int k;        //为了保持思路清晰，k始终是str的下标。
	for(k=0;k<i-1;k++)
		str.data[k] = s1.data[k];   //首次，k是两个串同步的。
	for(k=i-1;k<i-1+s2.length;k++)
		str.data[k] = s2.data[k-i+1];
	for(k=i-1+s2.length;k<s1.length+s2.length;k++)
		str.data[k] = s1.data[k-s2.length];
	str.data[k]='\0';
	str.length = s1.length+s2.length;
	return str;
}

SqString DelStr(SqString s, int i, int j)
{
	int k;
	SqString str;
	for(k=0;k<i-1;k++)
		str.data[k] = s.data[k];
	for(k=i-1;k<s.length-j;k++)
		str.data[k] = s.data[k+j];
	str.data[k]='\0';
	return str;
}

SqString RepStr(SqString s, int i, int j, SqString t)
{
	int k;
	SqString str;
	for(k=0;k<i-1;k++)
		str.data[k] = s.data[k];
	for(k=i-1;k<i-1+t.length;k++)
		str.data[k] = t.data[k-i+1];
	for(k=i-1+t.length;k<s.length-j+t.length;k++)
		str.data[k] = s.data[k-t.length+j];
	str.data[k] = '\0';
	return str;
}

void DispStr(SqString s)
{
	int i;
	for(i=0;i<s.length;i++)
		printf("%c",s.data[i]);
}

int main()
{
	return 0;
}

















