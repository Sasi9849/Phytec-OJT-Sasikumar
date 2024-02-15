#include<stdio.h>
int main()
{
	int a[10]={12,2,13,1,4,42,3};
	int i,k;
	static int temp;
	for ( i=0;i<7;i++)
	{
		
		for ( k=i+1;k<7;k++)
	{
			if (a[i]>a[k]){
				temp =a[i];
				a[i]=a[k];
				a[k]=temp;
		//		printf("%d",temp);
			}
		}
	
	}
	for (int j=0;j<7;j++)
	{
		printf("%d\n",a[j]);
	}

}

