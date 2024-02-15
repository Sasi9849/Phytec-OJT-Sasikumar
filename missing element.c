#include<stdio.h>
int main()
{
	int a[]={6,7,8,9,10,11,13,14,15,16,17};
	int n=sizeof(a)/sizeof(int);
	int max,min,g,b,c,k,diff,d,sum,len;
	max=a[n-1];
	g=max*(max+1);
	b=g/2;
	printf("%d\n",b);
	min=a[0]-1;
	c=min*(min+1);
	d=c/2;
	printf("%d\n",d);
	k=b-d;
	printf("%d\n",k);
	for (int i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	diff=k-sum;
	printf("missing element: %d",diff);
}

