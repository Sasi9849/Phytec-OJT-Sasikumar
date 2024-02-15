#include<stdio.h>
int main()
{
	char a[10];
	static int d[10];
	static char b[10];
	static char c[10];
	printf("Enter the string: ");
	scanf("%s",a);
	int count=0;
	int count1=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i] >= 97 && a[i] <=122 )
		{
			c[count]=a[i];
			count++;
		}
		else
		{
			d[i]=i;
			b[count1]=a[i];
			count1++;
		}
	}
	int j=count-1,k=0,n=0;
	static char r[10];
	for(int i=0;i<10;i++)
	{
		if(d[i]==0)
		{
			r[k]=c[j];
			j--;
			k++;
		}
		else
		{
			r[k]=b[n];
			n++;
			k++;
		}
		

	}
	printf("%s",r);


}
