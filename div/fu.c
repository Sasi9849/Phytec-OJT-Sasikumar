#include<stdio.h>
int div()
{

	int a,b;
	float div=0;
	printf("Enter two elements:\n");
	scanf("%d %d",&a,&b);
	div=a/(float)b;
	printf("div=%f",div);
	return 0;
}
