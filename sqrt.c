#include<stdio.h>
int main()
{
	int a,count=0;
	scanf("%d",&a);
	for(int i=0;i<a;i++)
	{
		if (i*i==a){
			
		
			count++;
			//printf("perfect square");
			
		//	printf("not perfect square");
		
		}

	}
	if(count==1)
		printf("perfect");
	else
		printf("not perfect");
}
