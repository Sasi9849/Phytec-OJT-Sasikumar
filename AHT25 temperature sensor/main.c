#include "stm32f4xx.h"
#define SLAVE_ADDR 0x70 /* 1101 000. DS1337 */

void delayMs(int n);
void I2C1_init(void);
int I2C1_byteWrite(char saddr, char maddr);
int I2C1_byteRead(char saddr, char maddr, uint8_t* data);
int i2c_receive();

volatile int tmp;
volatile int temp;
volatile int tempp;
float temperature, humidity;

void I2C1_init(void) {
    RCC->AHB1ENR |= 2; /* Enable GPIOB clock */
    RCC->APB1ENR |= 0x00200000; /* Enable I2C1 clock */

    /* configure PB8, PB9 pins for I2C1 */
    GPIOB->AFR[1] &= ~0x000000FF; /* PB8, PB9 I2C1 SCL, SDA */
    GPIOB->AFR[1] |= 0x00000044;
    GPIOB->MODER &= ~0x000F0000; /* PB8, PB9 use alternate function */
    GPIOB->MODER |= 0x000A0000;
    GPIOB->OTYPER |= 0x00000300; /* output open-drain */
    GPIOB->PUPDR &= ~0x000F0000; /* with pull-ups */
    GPIOB->PUPDR |= 0x00050000;

    I2C1->CR1 = 0x8000; /* software reset I2C1 */
    I2C1->CR1 &= ~0x8000; /* out of reset */
    I2C1->CR2 = 0x0010; /* peripheral clock is 16 MHz */
    I2C1->CCR = 80; /* standard mode, 100kHz clock */
    I2C1->TRISE = 17; /* maximum rise time */
    I2C1->CR1 |= 0x0001; /* enable I2C1 module */
}

int I2C1_byteWrite(char saddr, char maddr) {
    while (I2C1->SR2 & 2); /* wait until bus not busy */
    I2C1->CR1 |= 0x100; /* generate start */
    while (!(I2C1->SR1 & 1));
    I2C1->DR = saddr << 1;
    while (!(I2C1->SR1 & 2));
    tmp = I2C1->SR2;
    while (!(I2C1->SR1 & 0x80)); /* wait until data register empty */
    I2C1->DR = maddr; /* send memory address */
    temp = I2C1->SR2;

    while (!(I2C1->SR1 & 4)); /* wait until transfer finished */
    I2C1->CR1 |= 0x200; /* generate stop */

    // Wait until the stop condition is completed
    while (I2C1->CR1 & 0x200);

    return 0;
}

int I2C1_byteRead(char saddr, char maddr, uint8_t* data) {
    while (I2C1->SR2 & 2); /* wait until bus not busy */
    I2C1->CR1 |= 0x100; /* generate start */
    while (!(I2C1->SR1 & 1)); /* wait until start flag is set */
    I2C1->DR = saddr << 1 | 1; /* transmit slave address + Read */

    for (int i = 0; i < 6; i++) {
        data[i] = i2c_receive();
    }

    I2C1->CR1 |= 0x200; /* generate stop after data received */
    while (!(I2C1->SR1 & 0x40)); /* Wait until RXNE flag is set */
    I2C1->CR1 |= 0x200; // Read data from DR
}

int i2c_receive() {
    // Wait until data is received
    while (!(I2C1->SR1 & I2C_SR1_RXNE));

    return I2C1->DR;
}

void read_sensor_values(float *temperature, float *humidity) {
    uint8_t data[6];
    uint8_t cmd = 0xAC; // AHT25_MEASURE_CMD;
    I2C1_byteWrite(SLAVE_ADDR, 0xAC);
    delayMs(100);
    I2C1_byteRead(0x71, 0xAC, data);

    *humidity = ((float)((data[1] << 12) | (data[2] << 4) | (data[3] >> 4))) / 1048576.0 * 100.0;
    *temperature = ((float)(((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5])) / 1048576.0 * 200.0 - 50.0;
}

void delayMs(int n) {
    int i;
    for (; n > 0; n--)
        for (i = 0; i < 3195; i++);
}

int main(void) {
    // Configure the system clock
    // ...

    // Initialize I2C1
    I2C1_init();

    while (1) {
        read_sensor_values(&temperature, &humidity);
        // Do something with temperature and humidity data
    }

    return 0;
}
