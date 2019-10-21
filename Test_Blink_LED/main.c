#include "msp.h"

// define colors
uint32_t delay = 50000;
uint32_t RED = BIT0;
uint32_t YELLOW = BIT0;//(BIT0 | BIT1);
uint32_t GREEN = (BIT0 | BIT2);//BIT1;
uint32_t CYAN = (BIT0 | BIT2);//(BIT1 | BIT2);
uint32_t BLUE = (BIT0 | BIT2);//BIT2;
uint32_t MAG = (BIT0 | BIT2);
uint32_t WHITE = BIT0;//(BIT0 | BIT1 | BIT2);

int main(void) {
    volatile uint32_t i;

    WDT_A->CTL = WDT_A_CTL_PW |            // Stop WDT
                 WDT_A_CTL_HOLD;

    P2->DIR |= 0x07;                       // P2.0 set as output


    while (1)                             // continuous loop
    {
        P2->OUT = RED;                    // Blink LED
            for (i = delay; i > 0; i--);  // Delay
            P2->OUT = ~RED;               // Reset
        P2->OUT = YELLOW;                 // Blink LED
            for (i = delay; i > 0; i--);  // Delay
            P2->OUT = ~YELLOW;            // Reset
        P2->OUT = CYAN;                   // Blink LED
            for (i = delay; i > 0; i--);  // Delay
            P2->OUT = ~CYAN;              // Reset
        P2->OUT = GREEN;                  // Blink LED
            for (i = delay; i > 0; i--);  // Delay
            P2->OUT = ~GREEN;             // Reset
        P2->OUT = BLUE;                   // Blink LED
            for (i = delay; i > 0; i--);  // Delay
            P2->OUT = ~BLUE;              // Reset
        P2->OUT = MAG;                    // Blink LED
            for (i = delay; i > 0; i--);  // Delay
            P2->OUT = ~MAG;               // Reset
        P2->OUT = WHITE;                  // Blink LED
            for (i = delay; i > 0; i--);  // Delay
            P2->OUT = ~WHITE;             // Reset
    }
}
