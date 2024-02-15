#include<stdio.h>
static int b;
int main()
{
	int a,j;
        static int i;
	printf("Enter the number:");
	scanf("%d",&a);
	for(i=2;i<a;i++)
	{
		for ( j=1;j<i;j++)
		{
			if (i%j==0)
			{
				b++;
		//	break;

		
			}
	
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

		
			
		
