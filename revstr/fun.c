
#include<stdio.h>
#include<string.h>
void strspace(char* a)
{
	int i,len;
	len=strlen(a);
	for (i=0;i<=len;i++)
	{
		if (a[i]==(' '))
		{
			a[i]=',';
		}
	}
printf("split words are : %s",a);
}
