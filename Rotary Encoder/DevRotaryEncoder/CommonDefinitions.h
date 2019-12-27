/******************************************************************************
*--------------------------------- HEADER FILE -------------------------------*
*---------------------------- CommonDefinitions.h ----------------------------*
*DESCRIPTION:This File is used as a consolidated header file, containing masks*
*DESCRIPTION:used for setting control registers on the MSP432. These masks ---*
*DESCRIPTION:have been given names corresponding to the function they serve.--*
*-----------------------------------------------------------------------------*
*Authors:Evan Czechowicz & Taylor Haag----------------------------------------*
******************************************************************************/

#ifndef COMMONDEFINITIONS_H_
#define COMMONDEFINITIONS_H_

/*************************** TIMER A REGISTER MASKS **************************/
						//*** CCTL REGISTER ***//
#define Timer_A_ResetSetMode ((uint16_t)0x00E0)

						//*** CTL REGISTER ***//
//Set Count Mode
#define Timer_A_STOP ((uint16_t)0x0000)
#define Timer_A_UpMode ((uint16_t)0x0010)
#define Timer_A_DownMode ((uint16_t)0x0020)
#define Timer_A_UpDownMode ((uint16_t)0x0030)
//Set Input Clock Divider
#define Timer_A_InputCLK_DivideOne ((uint16_t)0x0000)
#define Timer_A_InputCLK_DivideTwo ((uint16_t)0x0040)
#define Timer_A_InputCLK_DivideFour ((uint16_t)0x0080)
#define Timer_A_InputCLK_DivideEight ((uint16_t)0x00C0)
//Set Input Clock Source
#define Timer_A_Set_TAX_AsInputCLK ((uint16_t)0x0000)
#define Timer_A_Set_ACLK_AsInputCLK ((uint16_t)0x0100)
#define Timer_A_Set_SMCLK_AsInputCLK ((uint16_t)0x0200)
#define Timer_A_Set_INCLK_AsInputCLK ((uint16_t)0x0300)


/******************** NCIV Interrupt Stack Member Masks **********************/

					//*** ISER[0] Members***//
//#define EUSCI_A0_STK_ADRS 0x00010000
//#define EUSCI_A1_STK_ADRS 0x00020000
//#define EUSCI_A2_STK_ADRS 0x00040000
//#define EUSCI_A3_STK_ADRS 0x00080000
//#define EUSCI_B0_STK_ADRS 0x00100000
//#define EUSCI_B1_STK_ADRS 0x00200000
//#define EUSCI_B2_STK_ADRS 0x00400000
//#define EUSCI_B3_STK_ADRS 0x00800000


					//*** ISER[1] Members ***//
//#define P1_INTRPT_STK_ADRS 0x00000008
//#define P2_INTRPT_STK_ADRS 0x00000010
//#define P3_INTRPT_STK_ADRS 0x00000020
//#define P4_INTRPT_STK_ADRS 0x00000040
#define P5_INTRPT_STK_ADRS 0x00000080
//#define P6_INTRPT_STK_ADRS 0x00000100

#endif /* COMMONDEFINITIONS_H_ */
