/******************************************************************************
*--------------------------------- HEADER FILE -------------------------------*
*----------------------------- PinAssignments.h ------------------------------*
*DESCRIPTION:This File is used as a mapping header file for assigning relevant*
*DESCRIPTION:names to specific processor pins, so that when setting and config*
*DESCRIPTION:-uring a pin the code becomes easier and more logical to read.---*
*DESCRIPTION:This file also acts as a way to keep track of and reserve pins---*
*DESCRIPTION:for specific and singular uses, so that they are not attempted to*
*DESCRIPTION:be reset/allocated elsewhere.------------------------------------*
*-----------------------------------------------------------------------------*
*Authors:Evan Czechowicz & Taylor Haag----------------------------------------*
******************************************************************************/

#ifndef PINASSIGNMENTS_H_
#define PINASSIGNMENTS_H_

/******************************PIN ASSIGNMENTS********************************/

/*****PORT1*****/
//#define BIT0 // NOT AVAILABLE
//#define BIT1 // NOT AVAILABLE
//#define BIT2 // PREDEFINED FOR USB INTEFACE DONT USE
//#define BIT3 // PREDEFINED FOR USB INTEFACE DONT USE
//#define BIT4 // NOT AVAILABLE
//#define BIT5
#define I2C_SDA1 BIT6
#define I2C_SCL1 BIT7

/*****PORT2*****/
//#define BIT0 // NOT AVAILABLE
//#define BIT1 // NOT AVAILABLE
//#define BIT2 // NOT AVAILABLE
//#define BIT3
//#define BIT4
//#define BIT5
//#define BIT6
//#define BIT7

/*****PORT3*****/
//#define BIT0
//#define BIT1 // NOT AVAILABLE
//#define BIT2
//#define BIT3
//#define BIT4 // NOT AVAILABLE
//#define BIT5
//#define BIT6
//#define BIT7

/*****PORT4*****/
//#define BIT0
//#define BIT1
//#define BIT2
//#define BIT3
//#define BIT4
//#define BIT5
//#define BIT6
//#define BIT7

/*****PORT5*****/
#define ENCODER_1A BIT0
#define ENCODER_1B BIT1
//#define BIT2
//#define BIT3
//#define BIT4 //DECLARED RESERVED
//#define BIT5 //DECLARED RESERVED
//#define BIT6
//#define BIT7

/*****PORT6*****/
//#define BIT0
//#define BIT1
//#define BIT2
//#define BIT3
//#define BIT4
//#define BIT5
//#define BIT6
//#define BIT7

/*****PORT7*****/
//#define BIT0
//#define BIT1
//#define BIT2
//#define BIT3
//#define BIT4
//#define BIT5
#define ServoSignalOne BIT6
//#define BIT7

/*****PORT8*****/
//#define BIT0
//#define BIT1 // NOT AVAILABLE
//#define BIT2
//#define BIT3
//#define BIT4
//#define BIT5
//#define BIT6
//#define BIT7

/*****PORT9*****/
//#define BIT0
//#define BIT1
//#define BIT2
//#define BIT3
//#define BIT4
//#define BIT5
//#define BIT6
//#define BIT7

/*****PORT10*****/
//#define BIT0
//#define BIT1
//#define BIT2
//#define BIT3
//#define BIT4
//#define BIT5

/*****PORTJ*****/
//#define BIT0
//#define BIT1
//#define BIT2
//#define BIT3
//#define BIT4
//#define BIT5


#endif /* PINASSIGNMENTS_H_ */
