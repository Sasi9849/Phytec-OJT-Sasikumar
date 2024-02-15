#include<stdio.h>
int main()
{
	int i,j=29;
	 int s=0;
	for (i=1;i<=j-1;i++)
	{
		if(j%i==0)
		{
			s=s+i;
			printf("%d\n",i);
			//printf("%d\n",s);
}
}
			if(s==j)
			{
				printf("perfect number");
			}
		
	
}

