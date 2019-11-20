#include "msp.h"

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

/*Local File Includes*/
#include <PinInitializations.h>
#include <PinAssignments.h>

volatile unsigned int TurnRight = 0; // Deboounce state for button S1
volatile unsigned int TurnLeft = 0; // Deboounce state for button S1

volatile unsigned int RightFirst = 0; // Deboounce state for button S1
volatile unsigned int LeftFirst = 0; // Deboounce state for button S1

uint8_t RED = BIT0;
uint8_t YELLOW = (BIT0 | BIT1 );
uint8_t GREEN = (BIT0 | BIT2 );
uint8_t CYAN = (BIT1 | BIT2 );
uint8_t BLUE = (BIT2 | BIT3 );
uint8_t MAG = (BIT0 | BIT3 );
uint8_t WHITE = (BIT0 | BIT1 | BIT2 );


void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    uint8_t COLORS[] = {RED,YELLOW,GREEN,CYAN,BLUE,MAG,WHITE};
    uint8_t currentColor = 0;
    //Startup Routine
    EncoderInitialization();
    InterruptInitialization();
    P2->DIR |= 0x07;                       // P2.0 set as output

    //Main Loop Routine
    while (1)
    {
        if (TurnRight == 1)
        {
            P2->OUT = ~COLORS[currentColor];
            if(currentColor>=6)
            {
                currentColor = 0;
            }
            else
            {
                currentColor++;
            }
            P2->OUT = COLORS[currentColor];
            TurnRight = 0;
        }
        else if (TurnLeft == 1)
        {
            P2->OUT = ~COLORS[currentColor];
            if(currentColor>=6)
            {
                currentColor = 0;
            }
            else
            {
                currentColor--;
            }
            P2->OUT = COLORS[currentColor];
            TurnLeft = 0;
        }
    }
}

void PORT5_IRQHandler(void)
{
    uint8_t TEMPFLAG = P5->IFG;
    P5->IFG &= 0x00;

    //Process Orientation
    if ((TEMPFLAG & ENCODER_1A ) && !(TEMPFLAG & ENCODER_1B ) && (LeftFirst == 0))
    {
        RightFirst = 1;
    }
    else if ((TEMPFLAG & ENCODER_1B ) && !(TEMPFLAG & ENCODER_1A ) && (RightFirst == 0))
    {
        LeftFirst = 1;
    }

    //Fulfill Full Turn
    if (!(TEMPFLAG & ENCODER_1A ) && (TEMPFLAG & ENCODER_1B ) && (RightFirst == 1))
    {
        TurnRight = 1;
        RightFirst = 0;
    }
    else if (!(TEMPFLAG & ENCODER_1B ) && (TEMPFLAG & ENCODER_1A ) && (LeftFirst == 1))
    {
        TurnLeft = 1;
        LeftFirst = 0;
    }
}

