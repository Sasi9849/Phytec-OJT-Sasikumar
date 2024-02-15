#include<stdio.h>
int main()
{
	int num=20,res;
	unsigned bitmask=16;
	res = num&bitmask;
	if (res==0)
		printf("off");
	else 
		printf("On");
}
