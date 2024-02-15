#include<stdio.h>
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for (i=0;i<((n+1)/2-1);i++)
	{
		printf(" ");
		for(j=i;j<(n+1)/2;j++)
		{
			printf("*");
		}
	//	printf("*");
	printf("\n");
	}
	for(i=(n+1)/2;i<=n;i++)
	{
		if(i==4)
		{
			printf("*");
		}
		else
		{
			printf(" ");
			for(j=i;j>=(n+1)/2;j--)
			{
				printf("*");
			}
		}
	printf("\n");
	}
}

