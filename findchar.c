#include<stdio.h>
#include<string.h>
int findchar(char source[], char findchar)
{
	int i;
	for(i=0;source[i]!='\0';i++)
	{
		if (source[i]==findchar)
			return 0;
		else
			return 1;
}
}
int main()
{
	char a[50]="Ramu is a good bao";
	char b;
	int find;
	printf("Character to be found :");
	scanf("%c",&b);
	find=findchar(a,b);
	if(find==0)
		printf("character is present");
	else
		printf("character is not found");
}

