#include<stdio.h>
int main()
{
	int i,a,base=0;
	printf("enter the number");
	scanf("%d",&a);
	while(a)
	
	{
		int j=0;
		i=a%2;
//		j=j+i;
		
		printf("%d",i);
		a=a/2;

	}
}

