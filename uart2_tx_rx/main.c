#include "main.h"
void USART2_init(void);
void USART2_write(int c);
void delayMs(int);
char USART2_read(void);

int main (void)
{
	char c;
	USART2_init();
	while (1)
	{
		c = USART2_read();
		USART2_write(c);
	}
}
/* initialize UART2 to transmit at 9600 Baud */

void USART2_init(void)
{
	RCC->AHB1ENR |= 1; /* Enable GPIOA clock */
	RCC->APB1ENR |= 0x20000; /* Enable UART2 clock */
	/* Configure PA2, PA3 for UART2 TX, RX */
	GPIOA->MODER &= ~0x00F0;
	GPIOA->MODER |= 0x00A0; /* enable alternate function for PA0, PA1 */
	GPIOA->AFR[0] &= ~0x00FF;
	GPIOA->AFR[0] |= 0x7700; /* alt8 for UART2 */
	USART2->BRR = 0x0683; /* 9600 baud @ 16 MHz */
	USART2->CR1 = 0x000C; /* enable Tx, Rx, 8-bit data */
	USART2->CR2 = 0x0000; /* 1 stop bit*/
	USART2->CR3 = 0x0000; /* no flow control */
	USART2->CR1 |= 0x2000; /*enable UART2 */
}
/* Write a character to UART2 */
void USART2_write (int ch)
{
while (!(USART2->SR & 0x0080)) {}  // wait until Tx buffer empty
USART2->DR = (ch & 0xFF);
}
/* Read a character from UART2 */
char USART2_read(void)
{
while (!(USART2->SR & 0x0020)) {} // wait until char arrives
return USART2->DR;
}
