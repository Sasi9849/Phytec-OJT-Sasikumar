#include<stdio.h>
int main()
{
	int a=14;
	int b=0;
	for(int i=2;i<=a/2;i++)
	{
		if(a%i==0){
			b++;
		}
	}
	if (b==0){
		printf("prime");
	}
	else
		printf("no_prime");
}


