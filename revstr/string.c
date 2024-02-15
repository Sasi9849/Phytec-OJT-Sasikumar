	
#include<stdio.h>
#include<string.h>
#include"head.h"
int main()
{
	char a[100];
	printf("Enter a string\n");
	gets(a);
	strspace(a);
	return 0;
	//printf("string split:",a);
}
