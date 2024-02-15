#include<stdio.h>
int main()
{
	int arr[5];
	int i,sum=0;
	int arr1[5];
	printf("enter num  1 values");
	for(i=0;i<5;i++){
		scanf("%d",&arr[i]);
		sum=sum+arr[i];
	}
	
	printf("sum=%d",sum);
	/*printf("enter num1 values");
	for(i=0;i<5;i++){
		scanf("%d",&arr1[i]);
	}
	for(i=0;i<5;i++)
	{
		sum=arr[i]+arr1[i];
	}
	printf("sum=%d",sum);
	for(i=0;i<5;i++){
		printf("result(%d)=%d",i,sum);
	}*/
}


