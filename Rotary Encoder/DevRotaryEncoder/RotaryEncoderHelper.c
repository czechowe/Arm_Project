/******************************************************************************
*--------------------------------- SOURCE FILE -------------------------------*
*---------------------------- RotaryEncoderHelper.c --------------------------*
*DESCRIPTION:This source file contains several functions to aid in the use of-*
*DESCRIPTION:Rotary Encoder. Including processing, error checking and total---*
*DESCRIPTION:Turns.-----------------------------------------------------------*
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
#include<RotaryEncoderHelper.h>

void AssignEncoderDefaults(m_Encoder *Encoder)
{
	Encoder->DetectionStatus = EncoderDefault;
	Encoder->DialStack = 0;
	Encoder->ButtonStack = 0;
}

void UpdateEncoder(m_Encoder *Encoder, uint8_t *FlagA, uint8_t *FlagB)
{
						/*** Proper Operation Updates ***/
	if((Encoder->DetectionStatus == EncoderDefault) && (*FlagA == 1) && (*FlagB == 0))
	{
		Encoder->DetectionStatus = RightTurnInit;
		*FlagA = 0;
	}
	else if((Encoder->DetectionStatus == EncoderDefault) && (*FlagA == 0) && (*FlagB ==1))
	{
		Encoder->DetectionStatus = LeftTurnInit;
		*FlagB = 0;
	}
	else if((Encoder->DetectionStatus == RightTurnInit) &&  (*FlagA == 0) && (*FlagB == 1))
	{
		Encoder->DialStack++;
		Encoder->DetectionStatus = EncoderDefault;
		*FlagB = 0;
	}
	else if((Encoder->DetectionStatus == LeftTurnInit) &&  (*FlagA == 1) && (*FlagB == 0))
	{
		Encoder->DialStack--;
		Encoder->DetectionStatus = EncoderDefault;
		*FlagA = 0;
	}

							/*** Error checking and correcting ***/

	//These situations indicates either bounce or a missed trigger from the other sensing pin on encoder
	if((Encoder->DetectionStatus == LeftTurnInit) &&  (*FlagA == 0) && (*FlagB == 1))
	{
		Encoder->DetectionStatus = EncoderDefault;
	}
	else if((Encoder->DetectionStatus == RightTurnInit) &&  (*FlagA == 1) && (*FlagB == 0))
	{
		Encoder->DetectionStatus = EncoderDefault;
	}
}


