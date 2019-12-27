#include "msp.h"

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

/*Full - Scope Project File Includes*/
#include <PinInitializations.h>
#include <PinAssignments.h>
#include <CommonDefinitions.h>

#define TOF_DIST_I2C_ADRS 0x52

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//SET DATA AND CLOCK LINES
	P1->SEL0 |= (I2C_SDA1 | I2C_SCL1);
	P1->SEL1 &= ~(I2C_SDA1 | I2C_SCL1);



}
