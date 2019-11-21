/*
 * RotaryEncoderHelper.h
 *
 *  Created on: Nov 20, 2019
 *      Author: czech
 */

#ifndef ROTARYENCODERHELPER_H_
#define ROTARYENCODERHELPER_H_


//STRUCTURE DEFINITIONS//
typedef struct t_Encoder{
	uint8_t DetectionStatus;// = EncoderDefault;
	int DialStack;// = 0;
	uint8_t ButtonStack;//= 0;
}m_Encoder;

//FUNCTION DEFINITIONS//
void UpdateEncoder(m_Encoder *Encoder, uint8_t *FlagA, uint8_t *FlagB);
void AssignEncoderDefaults(m_Encoder *Encoder);

#endif /* ROTARYENCODERHELPER_H_ */
