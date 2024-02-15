#include<stdio.h>
int main()
{
	int a[20],size;
	printf("Enter siz of the array");
	scanf("%d",&size);
	printf("Enter 10 numbers\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}

	int i,j,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<size;i++)
	{
	printf("numbers after sorting:%d\n",a[i]);
	}
	
}
