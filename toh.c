#include<stdio.h>
int toh(int n,int a,int b,int c)
{
	if (n==1)
		printf("from %d to %d",a,c);
		return ;
	else 
	{
		toh(n-1,a,b,c);
		printf("from %d to %d",a,c);
		toh(n-1,b,c,a);
	}
}
int main()
{
	printf("%d",toh(3,1,2,3));
			
}
