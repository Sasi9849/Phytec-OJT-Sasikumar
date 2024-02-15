#include<stdio.h>
void display()
{
	char date;
	printf("enter a char:");
	scanf("%c",&date);
	if (date>=65 && date<=90){
		printf("given input is uppercase");
		printf("input in lowercase %c \n",date+32);
	}
	else if (date>=97 && date<=122){
		printf("input given is lower case");
		printf("input in upper case %c \n",date-32);
		printf("size of data=%ld\n",sizeof(date));}
}
