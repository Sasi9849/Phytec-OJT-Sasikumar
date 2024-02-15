#include<stdio.h>
int main()
{
	char a[20]=("c programming");
	int i,j,len=0;
	printf("string =%s",a);
	char x;
	for(i=0;a[i]!='\0';i++)
	{
		len++;
	}
	for(i=0;i<(len/2);i++)
	{
		for(j=len-1;i>j;j--)
			{
		
		
			x=a[i];
			a[i]=a[j];
			a[j]=x;}
		a[j]='\0';
	}

		printf("revstr=%s",a);
	
}
