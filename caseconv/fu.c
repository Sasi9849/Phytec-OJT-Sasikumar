#include<stdio.h>
int num()
{
	int a,b;
	printf("Enter any number:");
	scanf("%d",&a);//4365
	while(a){
		b=a%10;
	switch (b)
	{
	case 1:
		printf("one");
		break;
	case 2:
		printf("two");
		break;
	case 3:
		printf("Three");
		break;
	case 4:
		printf("Four");
		break;
	case 5:
		printf("Five");
		break;
	case 6:
		printf("Six");
		break;
	case 7:
		printf("Seven");
		break;
	case 8:
		printf("Eight");
		break;
	case 9:
		printf("Nine");
		break;
	case 0:
		printf("Zero");
		break;}
	a=a/10;
	}
}
