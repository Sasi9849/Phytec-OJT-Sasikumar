#include"stm32f4xx.h"

void uart3_init(void);
void uart3_write(int ch);
char uart3_read(void);

int main(void)
{
	char c;
	uart3_init();
	while (1) {
	c = uart3_read();
	uart3_write(c);
	}

}

void uart3_init(void)
{
	RCC->AHB1ENR |= 1;
	RCC->APB2ENR |= 0x00000010;
	GPIOA->MODER &= ~0x003C0000;
	GPIOA->MODER |= 0x00280000;
	GPIOA->AFR[1] &= ~0x0FF0;
	GPIOA->AFR[1] |= 0x0770 ; /* alt8 for UART4 */
	USART1->BRR = 0x0683; /* 9600 baud @ 16 MHz */
	USART1->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
	USART1->CR2 = 0x0000; /* 1 stop bit*/
	USART1->CR3 = 0x0000; /* no flow control */
	USART1->CR1 |= 0x2000; /*enable UART4 */

}



void uart3_write(int ch) {
while (!(USART1->SR & 0x0080)) {} // wait until Tx buffer empty
USART1->DR = (ch & 0xFF);
}
/* Read a character from UART4 */
char uart3_read(void) {
while (!(USART1->SR & 0x0020)) {} // wait until char arrives
return USART1->DR;
}
