#include"head.h"
#include<stdio.h>
int main()
{
	unsigned int rev,num=0x00008888;
	rev=reversenibbles(num);
	printf("number is 0x%x:\n",num);
	printf("reverse number is 0x%x:\n",rev);
}
