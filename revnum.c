#include<stdio.h>
int main()
{
	int rev=0,a,b,c;
	scanf("%d",&a);
	c=a;
	while(a){
	b=a%10;
	rev=rev*10+b;
	a=a/10;
	}
	if(rev==c)
	{
		printf("palindrome");
	}
	else
		printf("non-palidrome");
	printf("%d",rev);
}

