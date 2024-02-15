#include<stdio.h>
int main()
{
	int a[10]={3,6,8,8,10,12,15,15,15,20};
	int lastdup=0;
	int  count=0;
	for (int i=0;i<10;i++)

	{
		if (a[i]==a[i+1]&&a[i]!=lastdup){
		for (int j=i+2;j<10;j++)

		{

			if (a[i]!=a[j]){
				count =j-i;
				printf("duplicates : %d\n",a[i]);
			printf("count %d\n",count);
			break;
			}
			
		}
		}
			lastdup=a[i];
	}
}
