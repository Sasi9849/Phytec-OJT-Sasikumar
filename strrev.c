#include <stdio.h>
#include <string.h>
int main()
{
	int i,j;
	char str[10];
	//for(i=0;i<10;i++)
	//	scanf("%c",&str[i]);
	gets(str);
	int l=strlen(str);
	for(i=l-1;i>=0;i--)
	printf("%c",str[i]);

}

