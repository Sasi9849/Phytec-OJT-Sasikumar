#include "stm32f4xx.h"

// Function to initialize USART2 for half-duplex communication with interrupts
void USART2_Init(void) {
    RCC->APB1ENR |= 0x20000;  // Enable USART2 clock
    USART2->BRR = 0x0683;  // Set the baud rate to 9600 (assuming APB1 clock is 16 MHz)

    // Configure USART2 pins (PA2 as TX, PA3 as RX)
    GPIOA->MODER |= 0x00A0;  // Set PA2 as alternate function
    GPIOA->AFR[0] |= 0x00FF;// Set PA2's alternate function to USART2
   // GPIOA->MODER |= GPIO_MODER_MODER3_1;  // Set PA3 as alternate function
   // GPIOA->AFR[0] |= (7 << (3 * 4)); // Set PA3's alternate function to USART2

    USART2->CR1 = 0x000C;  // Enable transmitter and receiver
    USART2->CR1 |= (1<<5);  // Enable RXNE interrupt
    USART2->CR1 |= 0x2000;   // Enable USART2

    // Enable USART2 interrupts in NVIC
    NVIC_EnableIRQ(USART2_IRQn);
}

// Function to initialize USART6 for half-duplex communication with interrupts
void USART6_Init(void) {
    RCC->APB2ENR |= 0x00000020;  // Enable USART6 clock
    USART6->BRR = 0x0683;  // Set the baud rate to 9600 (assuming APB2 clock is 16 MHz)

    // Configure USART6 pins (PC6 as TX, PC7 as RX)
    	GPIOA->MODER &= ~0x03C00000;
    	GPIOA->MODER |= 0x02800000;
    	GPIOA->AFR[1] &= ~0x0FF0;
    	GPIOA->AFR[1] |= 0x00088000 ;// Set PC7's alternate function to USART6

    USART6->CR1 = 0x000C;  // Enable transmitter and receiver
    USART6->CR1 |= (1<<5);  // Enable RXNE interrupt
    USART6->CR1 |= 0x2000;   // Enable USART6

    // Enable USART6 interrupts in NVIC
    NVIC_EnableIRQ(USART6_IRQn);
}

// Function to send data v,;/ ia USART2
void USART2_SendChar(uint8_t data) {
    while (!(USART2->SR & USART_SR_TXE));  // Wait for the data register to be empty
    USART2->DR = data;  // Send the data
}

// Function to receive data via USART2
uint8_t USART2_ReceiveChar(void) {
    return USART2->DR;  // Return the received data
}

// Function to send data via USART6
void USART6_SendChar(uint8_t data) {
    while (!(USART6->SR & USART_SR_TXE));  // Wait for the data register to be empty
    USART6->DR = data;  // Send the data
}

// Function to receive data via USART6
uint8_t USART6_ReceiveChar(void) {
    return USART6->DR;  // Return the received data
}

// USART2 Interrupt Service Routine
void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_RXNE) {
        // Data received on USART2, process it as needed
        uint8_t data = USART2_ReceiveChar();

        // Process the received data if needed
        // ...

        // Echo the received data back to USART6 for testing
        USART6_SendChar(data);
    }
}

// USART6 Interrupt Service Routine
void USART6_IRQHandler(void) {
    if (USART6->SR & USART_SR_RXNE) {
        // Data received on USART6, process it as needed
        uint8_t data = USART6_ReceiveChar();

        // Process the received data if needed
        // ...

        // Echo the received data back to USART2 for testing
        USART2_SendChar(data);
    }
}

int main(void) {
    USART2_Init();
    USART6_Init();

    while (1) {
        // Your main program loop can do other tasks or simply wait.
        // The communication will be handled by the interrupt service routines.
    }
}
