
#include "msp.h"
#define S1 BIT1
#define DELAY 500

int i;
int count;


// * main.c

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    P1->DIR = 0x00;
    P1->REN = S1;
    P1->OUT = S1;
    P1->IE = S1;
    P1->IES = 0x00;
    P1->IFG = 0x00;

    NVIC->ISER[1] = 0x00000008;
    _enable_interrupts();

    while(1);

}

void PORT1_IRQHandler(void){
    if(P1->IFG & S1) count++;
    for (i=0;i<DELAY;i++){}
    P1->IFG &= ~S1;
}
