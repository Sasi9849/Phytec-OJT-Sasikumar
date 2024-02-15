#include<stdio.h>
int main()
{
	int a[10]={3,7,4,9,12,6,1,11,2,10};
	static int b[10];
	for(int i=0;i<10;i++)
	{
		b[a[i]]++;
	}
	for(int i=0;i<10;i++)
	{
		if (b[i]==0)
			printf("missing element is %d\n",i);
	}
}
