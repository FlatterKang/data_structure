//递归函数求阶乘
int fun(int n)  //递归求阶乘(尾递归)
{
    if (1 == n)
        return n;
    else
        return n * fun(n - 1);
}