#include <stdio.h>

long long fib (int n)
{
	int i; long long f[n+2];
	f[0]=0;
	f[1]=1;
	for (i=2; i<=n; i++)
		f[i]= f[i-1] + f[i-2];
	return f[n];
}

int main()
{
	int n;
	printf ("n= ");
	scanf("%d",&n);
	printf("Fibonacci= %lli", fib(n));
	return 0;
}
