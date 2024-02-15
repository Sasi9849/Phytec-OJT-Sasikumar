#include<stdio.h>
#include<string.h>
int main()
{
	char a[10]="sasi";
	char b[10];
	int i;
	for( i=0;a[i]!='\0';i++)
	{
		if (a[i]=='s') {
		
		
		

		
			a[i]='x';

		}
		
	}
	printf("%s",a);
}

