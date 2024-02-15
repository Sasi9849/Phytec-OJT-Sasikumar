#include<stdio.h>
int main()
{
	int a=10;
	int b=20;
	int c=30;
	int *pint1,*pint2,*pint3;
	pint1=&a;
	pint2=&b;
	pint3=&c;
	printf("given numbers are %d %d %d\n",*pint1,*pint2,*pint3);
	

	*pint1=*pint1+*pint2;
	*pint2=*pint1-*pint2;
	*pint1=*pint1-*pint2;

//	printf("%d",d);	
	a=*pint1;
	printf("%d",a);
	
	*pint2=*pint2+*pint3;
	*pint3=*pint2-*pint3;
	*pint2=*pint2-*pint3;

	b=*pint2;
	printf("%d",b);
	
	
	c=*pint3;
	printf("%d",c);



}
