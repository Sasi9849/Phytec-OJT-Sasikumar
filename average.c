#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	float f;
	printf("Enter four numbers:\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	e=a+b+c+d;
	f=e/(float)4;
	printf("average is %f:",f);
	return 0;
}
