#include<stdio.h>
int main()
{
	int a,b,c;
	char d[]="hbbdbdbau";
	char e[20];
	int j=0;
	for (int i=0;d[i]!='\0';i++)
	{
		if(d[i]==d[i+1]){ 
		}
		else
		{
			e[j]=d[i];
			j++;
		}
	}
	e[j]='\0';

	
	printf("%s",e);
}
