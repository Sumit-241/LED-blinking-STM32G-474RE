#include "stm32g474xx.h"

void GPIO_CONFIG(void){
	//GPIO CLOCK  ENABLE
	RCC->AHB2ENR |= 1<<0;
	RCC->AHB2ENR |= 1<<2;

	//LED MODE - general i/o
	GPIOA->MODER &= ~(1<<11);


	//BUTTON MODE - input mode
	GPIOC->MODER &= ~(1<<27);
	GPIOC->MODER &= ~(1<<26);

    GPIOC->PUPDR |= (1<<27);


	GPIOA->OSPEEDR |= (1 << 11);

    //GPIOC->IDR |= 1<<13;
}
void delay(uint32_t time){
	while (time--);
}
int main(void){
	GPIO_CONFIG();

	while(1){

			if(((GPIOC->IDR & 0x2000) !=0 ) ){

				while (1){
					 GPIOA->BSRR  = (1<<5);
					 delay(100000);
					 GPIOA->BSRR = (1<<21);
					 delay(100000);

					 if((GPIOC->IDR & 0x2000) != 1){

						 //GPIOA->BSRR = (1<<21);
						 break;

					 }

				}
			}
	}
	return 0;
}
