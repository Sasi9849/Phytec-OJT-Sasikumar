#include<stdio.h>
int main()
{
	int a[]={6,7,8,9,11,12,15,16,17};
	int len=sizeof(a)/sizeof(int);
	int b,c,d=0,e,max,add=0,sum=0;
	/*max=a[n-1];
	b=max*(max+1);
	c=b/2;*/
	for (int i=6;i<=17;i++)
	{
		sum=sum+i;
	}
	for (int j=0;j<len;j++)
	{
		add=add+a[j];
	}
	d=sum-add;
	printf("missing element %d",d);
}
	
