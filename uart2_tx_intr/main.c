#include "stm32f4xx.h"

void USART2_init(void);
void USART2_TX(int data);
void LED_blink(int value);
void delayMs(int);

//volatile int dataToSend = 65;  // Global variable to store data to be transmitted

/*------------------------------------------------------------------
---------MAIN function
*-------------------------------------------------------------------
---------*/
int main(void) {
    __disable_irq();   /* global disable IRQs */

    RCC->AHB1ENR |= 1;   /* enable GPIOA clock */
    GPIOA->MODER &= ~0x00000C00;   /* clear pin mode */
    GPIOA->MODER |= 0x00000400;    /* set pin to output mode */

    USART2_init();    /* initialize USART2 */
    USART2->CR1 |= 0x0008;   /* enable Tx interrupt */
    NVIC_EnableIRQ(USART2_IRQn);   /* enable interrupt in NVIC */
    __enable_irq();   /* global enable IRQs */

    while(1) {
        // Trigger data transmission and LED blinking
        /*USART2_TX(dataToSend);
        delayMs(2000); // Add a delay to observe the LED blinking before sending more data*/
    }
}

/*------------------------------------------------------------------
---------Initialize UART pins, Baudrate
*-------------------------------------------------------------------
---------*/
void USART2_init(void) {
    RCC->AHB1ENR |= 1;   /* Enable GPIOA clock */
    RCC->APB1ENR |= 0x20000;   /* Enable USART2 clock */

    GPIOA->MODER &= ~0x00C0;
    GPIOA->MODER |= 0x0080;   /* enable alternate function for PA2 */

    /* Configure PA2 for USART2 TX */
    GPIOA->AFR[0] &= ~0x0F00;
    GPIOA->AFR[0] |= 0x0700;   /* alt7 for USART2 */

    USART2->BRR = 0x008B;   /* 115200 baud @ 16 MHz */
    USART2->CR1 = 0x0008;   /* enable Tx, 8-bit data */
    USART2->CR2 = 0x0000;   /* 1 stop bit */
    USART2->CR3 = 0x0000;   /* no flow control */
    USART2->CR1 |= 0x2000;  /* enable USART2 */
}

void USART2_TX(int  data) {
	LED_blink(data);
    //USART2->DR = data;   /* Write data to the USART2 data register */
   // while (!(USART2->SR & 0x0080));   /* Wait until transmission is complete */
     // Call LED_blink function after successful transmission
}

void USART2_IRQHandler(void) {
    if (USART2->SR & 0x0080) {
        /* Check if the transmit data register is empty */
        /* If it's empty, transmit the next character */
        USART2_TX(65);  // Transmit data when the TX register is empty
        delayMs(1000);
    }
}

/* turn on or off the LEDs according to the value */
void LED_blink(int value) {
    value %= 16;   /* cap the max count at 15 */
    for (; value > 0; value--) {
        GPIOA->BSRR = 0x00000020;   /* turn on LED */
        delayMs(200);
        GPIOA->BSRR = 0x00200000;   /* turn off LED */
        delayMs(200);
    }
    delayMs(800);
}

void delayMs(int n) {
    int i;
    for (; n > 0; n--)
        for (i = 0; i < 2000; i++);
}
