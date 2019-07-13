/*输入：一个字符指针指向中缀表达式字符串
  输出：一个字符数组表示后缀表达式
       */
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MaxSize 100

typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack * &s)
{
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
}
void DestroyStack(SqStack * &s)
{
    free(s);
}
bool StackEmpty(SqStack *s)
{
    return (s->top == -1);
}
bool Push(SqStack * &s, ElemType e)
{
    if (MaxSize - 1 == s->top)
        return false;
    ++s->top;
    s->data[s->top] = e;
    return true;
}
bool Pop(SqStack * &s, ElemType &e)
{
    if (-1 == s->top)
        return false;
    e = s->data[s->top];
    --s->top;
    return true;
}

bool Pop(SqStack * &s,double & e)
{
    if(-1 == s->top)
        return false;
    e = (double)s->data[s->top];
    --s->top;
    return true;
}
bool GetTop(SqStack *s, ElemType &e)
{
    if (-1 == s->top)
        return false;
    e = s->data[s->top];
    return true;
}
bool GetTop(SqStack *s, double &e)
{
    if(-1 == s->top)
        return false;
    e = (double)s->data[s->top];
    return true;
}
bool trans(char *exp, char postexp[])
{
    int i = 0;
    ElemType e;
    SqStack *Optr;
    InitStack(Optr);
    while (*exp != '\0')
    {
        switch (*exp)
        {
        case '(':
            Push(Optr, '(');
            ++exp;
            break;
        case ')':
            while (!StackEmpty(Optr))
            {
                Pop(Optr, e);      //无论栈顶元素是什么都可以直接出栈，左括号也可以。
                if ('(' == e)
                    break;
                postexp[i++] = e;
            }
            //右括号从不进栈。
            exp++;
            break;
        case '+':
        case '-':
            while (!StackEmpty(Optr))
            {
                GetTop(Optr, e); //+、-、*、/都可以全部直接出栈，唯独‘(’不用理会。
                if ('(' == e)
                    break;
                else
                {
                    Pop(Optr, e);
                    postexp[i++] = e;
                }
            }
            Push(Optr, *exp);
            ++exp;
            break;
        case '*':
        case '/':
            while (!StackEmpty(Optr))
            {
                GetTop(Optr, e); //*、/先出栈后进栈，+、-、(不用理会，直接进栈
                if ('*' == e || '/' == e)
                {
                    Pop(Optr, e);
                    postexp[i++] = e;
                }
                else
                    break;
            }
            Push(Optr, *exp);
            ++exp;
            break;
        default:
            while (*exp >= '0' && *exp <= '9')
            {
                postexp[i++] = *exp;
                ++exp;
            }
            postexp[i++] = '#';
        }
    }
    while (!StackEmpty(Optr))
    {
        Pop(Optr, e);
        postexp[i++] = e;
    }
    postexp[i] = '\0';
    DestroyStack(Optr);
    return true;
}

double compvalue(char *postexp)
{
    double a, b, c, d, e;  //运算数a，b，计算结果c，d用于缓存进栈的数字,e保存最后的结果
    SqStack *Opnd;    //定义操作数栈
    InitStack(Opnd);  //初始化操作数栈
    while (*postexp != '\0')
    {
        switch (*postexp)
        {
        case '+':  //取出两个数进行计算并将计算结果进栈。
            Pop(Opnd, a);
            Pop(Opnd, b);
            c = b + a;
            Push(Opnd, c);
            break;
        case '-':
            Pop(Opnd, a);
            Pop(Opnd, b);
            c = b - a;
            Push(Opnd, c);
            break;
        case '*':
            Pop(Opnd, a);
            Pop(Opnd, b);
            c = b * a;
            Push(Opnd, c);
            break;
        case '/':
            Pop(Opnd, a);
            Pop(Opnd, b);
            if (a != 0)
            {
                c = b / a;
                Push(Opnd, c);
                break;
            }
            else
            {
                printf("除零错误！\n");
                exit(0);
            }
        default://将数字字符转化成对应数字再进栈
            d = 0;
            while (*postexp >= '0' && *postexp <= '9')
            {
                d = d * 10 + (*postexp) - '0';
                postexp++;
            }
            Push(Opnd, d);
            break;
        }
        ++postexp; //继续读取下一个字符。
    }
    GetTop(Opnd, e);
    DestroyStack(Opnd);
    return e;
}
int main()
{
    char str[MaxSize];
    char poststr[MaxSize];
    printf("请输入中缀表达式：\n");
    scanf("%s", str);

    trans(str, poststr);   //运算式转换

    printf("转化后的后缀表达式如下：\n");
    printf("%s\n", poststr);

    printf("运算结果如下：\n");
    printf("%g\n",compvalue(poststr));
    return 0;
}
//2019年7月8日完成。












