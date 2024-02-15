#include<stdio.h>
int main()
{
	int num,bitmask,num2;
	printf("Enter a number:");
	scanf("%d",&num);
	bitmask=1<<3|1<<4|1<<5;
	num2=num^bitmask;
	printf("%d",num2);
}

