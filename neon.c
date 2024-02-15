#include<stdio.h>
int main()
{
	int c,d=0,a=10;
	int b=a*a;
	while(b)
	{
		c=b%10;
		//printf("%d\n",c);
		d=d+c;
		b=b/10;
		printf("%d",d);
	}
	if(a==d)
	{
		printf("neon");
	}
	else
		printf("no");
}

