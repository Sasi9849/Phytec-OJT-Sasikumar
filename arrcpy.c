#include<stdio.h>
void arrcopy(int a[10],int position,int len)
{
	int i,j;
	int b[10];
	for(i=position,j=0;i<len;i++,j++)
			b[j]=a[i];
	int k;
	for(k=0;k<len-position;k++)
		printf("%d\n",b[k]);
}
int main()
{
	int len=0,a[10];
	printf("Enter 10 elements: ");
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
		len++;
	}
	int position;
	printf("Enter position :");
	scanf("%d",&position);
	arrcopy(a,position,len);
}
