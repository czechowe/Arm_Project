#include "msp.h"

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

/*Local File Includes*/
#include <PinInitializations.h>
#include <PinAssignments.h>
#include <RotaryEncoderHelper.h>
#include <CommonDefinitions.h>

/*Interupt Flags */
volatile uint8_t EncoderFlag_1A = 0; // Deboounce state for button S1
volatile uint8_t EncoderFlag_1B = 0; // Deboounce state for button S1

uint8_t RED = BIT0;
uint8_t YELLOW = (BIT0 | BIT1 );
uint8_t GREEN = (BIT0 | BIT2 );
uint8_t CYAN = (BIT1 | BIT2 );
uint8_t BLUE = (BIT2 | BIT3 );
uint8_t MAG = (BIT0 | BIT3 );
uint8_t WHITE = (BIT0 | BIT1 | BIT2 );


/*Test Functions, to be moved to files */


/* Local Functions */


void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

    uint8_t COLORS[] = {RED,YELLOW,GREEN,CYAN,BLUE,MAG,WHITE};

    //Local Variables
    uint8_t currentColor = 0;
    int deltaTracker = 0;


    //Encoder Declarations
    m_Encoder EncoderOne;
    AssignEncoderDefaults(&EncoderOne);

    //Startup Routine
    EncoderInitialization();
    InterruptInitialization();

    //LED ACTIIVATE!!!
    P2->DIR |= 0x07;                       // P2.0 set as output

    //Main Loop Routine
    while (1)
    {
    	deltaTracker = EncoderOne.DialStack;
    	UpdateEncoder(&EncoderOne, &EncoderFlag_1A, &EncoderFlag_1B);

        if (deltaTracker > EncoderOne.DialStack)
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
        }
        else if (deltaTracker < EncoderOne.DialStack)
        {
            P2->OUT = ~COLORS[currentColor];
            if(currentColor==0)
            {
                currentColor = 5;
            }
            else
            {
                currentColor--;
            }
            P2->OUT = COLORS[currentColor];
        }
        deltaTracker = EncoderOne.DialStack;
    }
}

void PORT5_IRQHandler(void)
{
    uint8_t TEMPFLAG = P5->IFG;
    P5->IFG &= 0x00;

    if(TEMPFLAG & ENCODER_1A)
    {
    	EncoderFlag_1A = 1;
    }
    else if(TEMPFLAG & ENCODER_1B)
    {
    	EncoderFlag_1B = 1;
    }

}

