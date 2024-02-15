#include<stdio.h>
int main()
{
	int num,num2,num3,i=31;
	printf("Enter a number");
	scanf("%d",&num);
	while(i>=0)
	{
		num2=1<<i;
		num3=num&num2;
		if(num3==0)
			printf("0");
		else 
			printf("1");
		i--;
	}
}
