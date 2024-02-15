#include<stdio.h>
int main()
{
	int a=6,i;
	static int k=1;
	for(i=a;i>0;i--)
	{
		k=k*i;
	}
	printf("%d",k);
}
	
