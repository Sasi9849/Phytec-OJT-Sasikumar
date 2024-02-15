#include<stdio.h>
#define rate 20
int main()
{
	int start,end,reimbaracement,kmtraveled;
	printf("enter starting value and ending value:\n");
        scanf("%d%d",&start,&end);
	kmtraveled=end-start;
	reimbaracement=kmtraveled*rate;
	printf("kilometers travelled:%d\n",kmtraveled);
	printf("reimbaracement:%d",reimbaracement);
	return 0;
}
	
