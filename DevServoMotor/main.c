#include "msp.h"
//#include "driverlib.h"

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

/*Local File Includes*/
#include <PinInitializations.h>
#include <PinAssignments.h>
#include <RotaryEncoderHelper.h>
#include <CommonDefinitions.h>

//Local Function Declarations
void ClockInitialize48MHz();


//Local variables for testing motor movement
#define ServoFreq 30000


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	ClockInitialize48MHz();							//Start MSP at 48MHz
	ToneTimerSetup();
}

void ClockInitialize48MHz()
{
    // Configure Flash wait-state to 1 for both banks 0 & 1
    FLCTL->BANK0_RDCTL = (FLCTL->BANK0_RDCTL & ~(FLCTL_BANK0_RDCTL_WAIT_MASK)) |
            FLCTL_BANK0_RDCTL_WAIT_1;
    FLCTL->BANK1_RDCTL = (FLCTL->BANK0_RDCTL & ~(FLCTL_BANK0_RDCTL_WAIT_MASK)) |
            FLCTL_BANK1_RDCTL_WAIT_1;
    //Configure HFXT to use 48MHz crystal, source to MCLK & HSMCLK*
    PJ->SEL0 |= BIT2 | BIT3;                // Configure PJ.2/3 for HFXT function
    PJ->SEL1 &= ~(BIT2 | BIT3); CS->KEY = CS_KEY_VAL ;
    // Unlock CS module for register access
    CS->CTL2 |= CS_CTL2_HFXT_EN | CS_CTL2_HFXTFREQ_6 | CS_CTL2_HFXTDRIVE;
    while(CS->IFG & CS_IFG_HFXTIFG) CS->CLRIFG |= CS_CLRIFG_CLR_HFXTIFG;
    /* Select MCLK & HSMCLK = HFXT, no divider */
    CS->CTL1 = CS->CTL1 & ~(CS_CTL1_SELM_MASK | CS_CTL1_DIVM_MASK | CS_CTL1_SELS_MASK |
            CS_CTL1_DIVHS_MASK) | CS_CTL1_SELM__HFXTCLK | CS_CTL1_SELS__HFXTCLK
                    | 0b010 << 20  //set HSMCLK to /4
                    | 0b010 << 28; //set SMCLK to /4
    CS->KEY = 0;                            // Lock CS module from unintended accesses
}

void TimerSetup()
{
// Configure GPIO for PWM output
    // Configure GPIO for PWM output
    P7->DIR |= ServoSignalOne; // P7.6 set TA1.2
    P7->SEL0 |= ServoSignalOne;
    P7->SEL1 &= ~(ServoSignalOne);
    TIMER_A1->CCR[0] = ServoFreq; // PWM Period (# cycles of clock)
    TIMER_A1->CCTL[2] = Timer_A_ResetSetMode; // CCR1 reset/set mode 7
    TIMER_A1->CCR[2] = 3000;
    // CCR1 setting clock with source clock and a clock divider of 8
    TIMER_A1->CTL |= 0x02D0;
}

//        TIMER_A1->CCR[0] = ToneOne; // PWM Period (# cycles of clock)
//        TIMER_A1->CCR[2] = (ToneOne/Volume);
