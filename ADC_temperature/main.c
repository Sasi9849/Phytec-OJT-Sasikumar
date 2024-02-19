#include "stm32f4xx.h"
float temperature;

void ADC_Init() {
    RCC->APB2ENR |= 1<<8;
    ADC->CCR |= 1<<23;
    ADC1->CR2 |= 1;
}
uint16_t conversion() {
    ADC1->SQR3 = 1<<4;
    ADC1->CR2 |= 1<<30;
    while (!(ADC1->SR & ADC_SR_EOC)){}
    return ADC1->DR;
}

float Calculate(uint16_t tempValue) {
    const float v25 = 0.76f;//voltage at 25 degrees
    const float Avg_Slope = 0.0025f;//avg slope of internal temp sensor
    float VSENSE = (tempValue / 4095.0f) * 3.3f;  //vref=3.3
    float temperature = ((VSENSE-0.76f) / Avg_Slope) + 25.0f;
    return temperature;
}
int main() {
    ADC_Init();

    while (1) {
    	uint16_t tempValue = conversion();
        temperature = Calculate(tempValue);
    }


}
