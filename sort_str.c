#include<stdio.h>
#include<string.h>
int main()
{
	char a[20][30];
	int size;
	printf("enter size of arrray\n");
	scanf("%d",&size);
	printf("Enter n number of names\n");
	int k;
	char temp[20];
	__fpurge();
	for(int i=0;i<size;i++)
	{
		//fgets(a[i],50,stdin);
		scanf("%s",&a[i]);
	}

	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			k=strcmp(a[j],a[j+1]);
			if(k>0)
			{
			       	strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
		}
	}
	for(int i=0;i<size;i++)
	{
		printf("enter names after sorting:%s\n",&a[i]);
	}
}

