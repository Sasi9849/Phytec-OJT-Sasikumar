#include "stm32f4xx.h"
void USART2_init(void);
void LED_blink(int value);
void delayMs(int);
/*------------------------------------------------------------------
---------MAIN function
*-------------------------------------------------------------------
---------*/ int main (void) {
__disable_irq(); /* global disable IRQs */
RCC->AHB1ENR |= 1; /* enable GPIOA clock */
GPIOA->MODER &=~0x00000C00; /* clear pin mode */
GPIOA->MODER |= 0x00000400; /* set
pin to output mode */
USART2_init(); /* initialize USART2 */
USART2->CR1 |= 0x0020; /* enable Rx interrupt */
NVIC_EnableIRQ(USART2_IRQn); /* enable interrupt in NVIC */
__enable_irq(); /* global enable IRQs */
while(1) { /* Loop forever */ }
}
/*------------------------------------------------------------------
---------Initialize UART pins, Baudrate
*-------------------------------------------------------------------
---------*/ void USART2_init (void) {
RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
RCC->APB1ENR |= 0x20000; /* Enable USART2 clock */
GPIOA->MODER &=~0x00C0;GPIOA->MODER |= 0x0080; /* enable alternate function for PA3 */
/* Configure PA2 for USART2 TX */
GPIOA->AFR[0] &= ~0xF000;
GPIOA->AFR[0] |= 0x7000; /* alt7 for USART2 */

USART2->BRR = 0x008B; /* 115200 baud @ 16 MHz */
USART2->CR1 =0x0004; /* enable Rx, 8-bit data */
USART2->CR2 = 0x0000; /* 1 stop
bit */ USART2->CR3 = 0x0000; /* no flow control */
USART2->CR1 |=0x2000; /* enable USART2 */
}
void USART2_IRQHandler(void) { char c;
if (USART2->SR & 0x0020) {
c = USART2->DR; /* Read a character from USART2 */
LED_blink(c); /*
blink the LED */
}
}
/* turn on or off the LEDs according to the value */ void
LED_blink(int value) {
value %= 16; /* cap the max count at 15 */
for (; value > 0; value--) {
GPIOA->BSRR = 0x00000020; /* turn on LED */
delayMs(200);
GPIOA->BSRR = 0x00200000; /* turn off LED */
delayMs(200);
}
delayMs(800);
}
void delayMs(int n) {
int i;
for (; n > 0; n--)
for (i = 0; i < 2000; i++) ; }
