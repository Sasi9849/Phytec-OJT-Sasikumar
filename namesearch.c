#include<stdio.h>
#include<string.h>
int main()
{
	char name[5][20],data[20];
	int c,x;
	printf("Enter the names of 5 people:");
	for (x=1;x<=5;x++)
	{
		printf("enter the name %d:",x);
		scanf("%s",name[x]);
	}
	printf("enter the name to be searched for \n");
	scanf("%s",data);
	for(x=1;x<5;x++){
		if (strcmp(data,name[x])==0)
		{
			c=1;
			break;
		}
	}
	if (c==1)
		printf("name found");
	else
	{
		printf("not found");
	}
	
}
