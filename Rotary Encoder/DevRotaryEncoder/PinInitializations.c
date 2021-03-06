/******************************************************************************
*--------------------------------- SOURCE FILE -------------------------------*
*---------------------------- PinInitializations.c ---------------------------*
*DESCRIPTION:This source file is used to serve as a location for all setup and*
*DESCRIPTION:initialization functions. This is specifically relating to-------*
*DESCRIPTION:configuration for specific pin functions, interrupt init.,-------*
*DESCRIPTION:as well as timer and clock settings.-----------------------------*
*-----------------------------------------------------------------------------*
*Authors:Evan Czechowicz & Taylor Haag----------------------------------------*
******************************************************************************/

/* Standard Includes */
#include "msp.h"
#include <stdint.h>
#include <stdbool.h>

/*Local Header Includes*/
#include<PinAssignments.h>
#include<CommonDefinitions.h>

/*Respective Header Include*/
#include <PinInitializations.h>


/********************* INTIALIZATION FUNCTION DEFINITIONS ********************/
void EncoderInitialization(void)
{
    P5->SEL0 &= ~(ENCODER_1A | ENCODER_1B );      //SET AS GPIO
    P5->SEL1 &= ~(ENCODER_1A | ENCODER_1B );      //SET AS GPIO
    P5->DIR &= ~(ENCODER_1A | ENCODER_1B );      //SET AS INPUT
    P5->REN |= (ENCODER_1A | ENCODER_1B );   //ENABLE PULL & PULL DOWN RESISTORS
    P5->OUT &= ~(ENCODER_1A | ENCODER_1B );          //SET PULL UP RESISTOR
    P5->IE |= (ENCODER_1A | ENCODER_1B );          //ENABLE INTERUPT TRIGGER
    P5->IES |=  (ENCODER_1A | ENCODER_1B );       //SET LOW to HIGH EDGE TRIGGER
}

void InterruptInitialization(void)
{
    ClearInterruptFlags();  //Clear All Interrupt Flags

    //Only UNCOMMENT interrupt ports that are being used//

    //PORT INTERRUPT ACTIVATION
    //NVIC->ISER[1] |= P1_INTRPT_STK_ADRS;    //Enable Port 1 in NVIC
    //NVIC->ISER[1] |= P2_INTRPT_STK_ADRS;    //Enable Port 2 in NVIC
    //NVIC->ISER[1] |= P3_INTRPT_STK_ADRS;    //Enable Port 3 in NVIC
    //NVIC->ISER[1] |= P4_INTRPT_STK_ADRS;    //Enable Port 4 in NVIC
    NVIC->ISER[1] |= P5_INTRPT_STK_ADRS;    //Enable Port 5 in NVIC
    //NVIC->ISER[1] |= P6_INTRPT_STK_ADRS;    //Enable Port 6 in NVIC

    _enable_interrupts(); //Enable all interrupts
}

//THIS FUNCTIOIN MAY BE MOVED AT A LATER DATE
void ClearInterruptFlags(void)
{
    //ONLY UNCOMMENT A PORT FLAG CLEAR IF THAT PORT IS USING INTERUPTS

    //P1->IFG = 0x00;
    //P2->IFG = 0x00;
    //P3->IFG = 0x00;
    //P4->IFG = 0x00;
    P5->IFG = 0x00;
    //P6->IFG = 0x00;
    //P7->IFG = 0x00;
    //P8->IFG = 0x00;
    //P9->IFG = 0x00;
    //P10->IFG = 0x00;
}

