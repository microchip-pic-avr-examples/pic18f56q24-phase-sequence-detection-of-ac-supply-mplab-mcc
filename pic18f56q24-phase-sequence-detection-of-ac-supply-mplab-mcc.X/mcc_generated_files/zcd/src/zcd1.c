/**
 * ZCD1 Generated Driver File.
 * 
 * @file zcd1.c
 * 
 * @ingroup  zcd1
 * 
 * @brief This file contains the API implementation for the ZCD1 driver.
 *
 * @version ZCD1 Driver Version 2.11.0
*/
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/**
   Section: Included Files
*/

#include <xc.h>
#include "../zcd1.h"
#include "../../system/system.h"

volatile uint8_t ZCD_Int_flag[3];                               // Application variables 
volatile uint8_t PhaseLossFlag[3];                              // For 3 ZCD solution (64 pin controller)

extern volatile uint8_t flagRSignal;
extern volatile uint16_t timerCounterValue[3];                  // uint16_t array for 64 pin controller timer calculation

/**
  Section: ZCD1 Module APIs
*/

void ZCD1_Initialize(void)
{
    // Set the ZCD1 to the options selected in the User Interface
  
    //ZCDINTN disabled; ZCDINTP enabled; ZCDPOL not inverted; ZCDEN enabled; 
    ZCD1CON = 0x82;

    // Clearing IF flag before enabling the interrupt
    PIR2bits.ZCD1IF = 0;

    // Enabling ZCD1 interrupt
    PIE2bits.ZCD1IE = 1;
}

bool ZCD1_IsLogicLevel(void)
{
    // Return ZCD logic level depending on the output polarity selected
    return (ZCD1CONbits.ZCD1OUT);
}
 
void ZCD1_ISR(void)
{
    // Clear the ZCD1 interrupt flag
    PIR2bits.ZCD1IF = 0;
    // User handled code
    TMR2_Write(0);
    ZCD_Int_flag[0]  = 1;
	PhaseLossFlag[0] = 1;
    flagRSignal = 0;
}

/**
 End of File
*/