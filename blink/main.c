#include"led.h"
#include"delay.h"
#include "stm32f4xx.h"
int main() {
	gpio();
/* set pin to output mode */
	while(1) { /* turn on LED */
		ledon();
		delayMs(500);
		ledoff();/* turn off LED */
		delayMs(500);
	}
}
