//求Fibonacci数列的第n项
int Fib1(int n)
{
	if(1 == n||2 == n)
		return 1;
	return (Fib1(n-1)+Fib1(n-2));
}