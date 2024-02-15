#include<stdio.h>
int f(int n,int r)
{
	int z;
	if (n==r || r==0)
		return 1;
	else
	{
		z=f(n-1,r-1)+f(n-1,r);
		return z;
	}
}
int main()
{
	printf("%d",f(5,2));
}

