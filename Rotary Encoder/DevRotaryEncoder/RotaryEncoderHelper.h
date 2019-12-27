/******************************************************************************
*--------------------------------- SOURCE FILE -------------------------------*
*---------------------------- RotaryEncoderHelper.h --------------------------*
*DESCRIPTION:This header contains function definitions, as well as structure--*
*DESCRIPTION:typedef initializations to aid, in conjunction with the source---*
*DESCRIPTION:file, in the use of a rotary encoders.---------------------------*
*-----------------------------------------------------------------------------*
*Authors:Evan Czechowicz & Taylor Haag----------------------------------------*
******************************************************************************/

#ifndef ROTARYENCODERHELPER_H_
#define ROTARYENCODERHELPER_H_


//STRUCTURE DEFINITIONS//
typedef struct t_Encoder{
	uint8_t DetectionStatus;
	int DialStack;
	int ButtonStack;
}m_Encoder;

//ENUM DEFINITIONS//
enum EncoderStates{
	EncoderDefault,
	RightTurnInit,
	LeftTurnInit
};

//FUNCTION DEFINITIONS//
void UpdateEncoder(m_Encoder *Encoder, uint8_t *FlagA, uint8_t *FlagB);
void AssignEncoderDefaults(m_Encoder *Encoder);

#endif /* ROTARYENCODERHELPER_H_ */
