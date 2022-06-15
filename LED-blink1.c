#include "stm32g474xx.h"



void GPIO_config(void){

//ENABLE THE GPIO CLOCK
RCC->AHB2ENR |= (1<<0);//for led i.e port A
RCC->AHB2ENR |= (1<<2);//for user button i.e. port C

//SET THE PIN AS OUTPUT
GPIOA->MODER &= ~(1<<11);  //i/o mode

GPIOC->MODER &= ~(1<<27); //input mode
GPIOC->MODER &= ~(1<<26); //input mode  i.e 0 0 but it's default is 1 1

GPIOC->PUPDR |= (1<<27); //initialize to pull down i.e input it takes is 0volt
//Configure the output mode
// GPIOA->OTYPER = 0;
GPIOA->OSPEEDR |= (1 << 11);
}

int main(){
	GPIO_config();
	while(1){
		if(((GPIOC->IDR) & 0x2000) != 0)
			GPIOA->BSRR = (1<<5);
		else
			GPIOA->BSRR = (1<<21);
	}

	return 0;
}
