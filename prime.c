#include<stdio.h>
int main()
{
	int a,i,j;
	printf("Enter the number:");
	scanf("%d",&a);
	for(i=2;i<a;i++)
	{
               int b=0;
		for ( j=1;j<i;j++)
		{
			if (i%j==0)
			{
				b++;
		//	break;

		
			}
	
		}
	
		if(b==1)
		{
			printf("%d\n",i);
		}
	//	else
	//	{
//			printf("%d",i);
//	
	
	}	
	
}

		
			
