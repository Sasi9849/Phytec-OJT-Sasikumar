
#include<stdio.h>
unsigned int reversenibbles(int num)
{
	unsigned int reverse=0;
	reverse |=((num&0x0000000f)<<28);
	reverse |=((num&0x000000f0)<<20);
	reverse |=((num&0x00000f00)<<12);
	reverse |=((num&0x0000f000)<<4);
	reverse |=((num&0x000f0000)>>4);
	reverse |=((num&0x00f00000)>>12);
	reverse |=((num&0x0f000000)>>20);
	reverse |=((num&0xf0000000)>>28);
	return reverse;
}
