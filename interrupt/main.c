#include "int.h"
int main(void)
{


	/*1.Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;

	/*2.Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
	pc13_exti_init();
	while(1)
	{

	}

}
static void exti_callback(void)
{
	printf("BTN Pressed...\n\r");
	GPIOA->ODR ^=LED;
}


void EXTI15_10_IRQHandler(void) {
	if((EXTI->PR & LINE13)!=0)
	{
		/*Clear PR flag*/
		EXTI->PR |=LINE13;
		//Do something...
		exti_callback();
	}

}

