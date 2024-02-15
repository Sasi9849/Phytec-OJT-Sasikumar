#include<stdio.h>
int uppercase(char a[20] )
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if (a[i]>=97 &&a[i]<=122){
			a[i]=a[i]-32;
		}
	}
}
int lowercase(char a[20])
{
	int i;
	for(i=0;a[i];i++)
	{
		if (a[i]>=65 && a[i]<=90)
		{
			a[i]=a[i]+32;
		}
	}
}
int opposite(char a[20])
{
	int i;
	for(i=0;a[i];i++)
	{
		if (a[i]>=65 && a[i]<=90)
		{
			a[i]=a[i]+32;
		}
		else if (a[i]>=97 && a[i]<=122)
		{
			a[i]=a[i]-32;
		}
	}
}
int main()
{
	int choice;
	char a[20];
	gets(a);
	printf("%s",a);
	printf("1 :change the entire sentence with upper case \n");
	printf("2 :change the entire sentence with lower case \n");
	printf("3 :change to its  opposite \n");
	printf("enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		uppercase(a);
		printf("string in upper case:%s",&a[0]);
		break;
	case 2:
		lowercase(a);
		printf("String in lower case:%s",a);
		break;
	case 3:
		opposite(a);
		printf("String in opposite:%s",a);
		break;
	default:
		printf("Enter correct choice");
		break;
	}
}


