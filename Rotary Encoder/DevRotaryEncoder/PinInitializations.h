/******************************************************************************
*--------------------------------- HEADER FILE -------------------------------*
*---------------------------- PinInitializations.h ---------------------------*
*DESCRIPTION:This header file is used to serve as a location for all setup and*
*DESCRIPTION:initialization functions. This is specifically relating to-------*
*DESCRIPTION:configuration for specific pin functions, interrupt init.,-------*
*DESCRIPTION:as well as timer and clock settings.-----------------------------*
*-----------------------------------------------------------------------------*
*Authors:Evan Czechowicz & Taylor Haag----------------------------------------*
******************************************************************************/

#ifndef PININITIALIZATIONS_H_
#define PININITIALIZATIONS_H_

//Clock Initialization Functions
void InitExternMasterClk();

//Interrupt Helper Functions
void ClearInterruptFlags(void);

//Initialization Function Declaration
void EncoderInitialization(void);
void InterruptInitialization(void);


#endif /* PININITIALIZATIONS_H_ */
