#include<stdio.h>
int fun(int n)
{
	if(n==0)
		return 1;
	else{
	       return n*fun(n-1);
	}
}
int main()
{
	int b,a=5;
	b=fun(a);
	printf("%d",b);
}
