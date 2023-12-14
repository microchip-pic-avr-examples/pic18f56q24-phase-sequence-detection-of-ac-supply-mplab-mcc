/**
 * ZCD2 Generated Driver File.
 * 
 * @file zcd2.c
 * 
 * @ingroup  zcd2
 * 
 * @brief This file contains the API implementation for the ZCD2 driver.
 *
 * @version ZCD2 Driver Version 2.11.0
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
#include "../zcd2.h"
#include "../../system/system.h"
#include "../../../application.h"

/**
  Section: ZCD2 Module APIs
*/

void ZCD2_Initialize(void)
{
    // Set the ZCD2 to the options selected in the User Interface
  
    //ZCDINTN disabled; ZCDINTP enabled; ZCDPOL not inverted; ZCDEN enabled; 
    ZCD2CON = 0x82;

    // Clearing IF flag before enabling the interrupt
    PIR2bits.ZCD2IF = 0;

    // Enabling ZCD2 interrupt
    PIE2bits.ZCD2IE = 1;
}

bool ZCD2_IsLogicLevel(void)
{
    // Return ZCD logic level depending on the output polarity selected
    return (ZCD2CONbits.ZCD2OUT);
}
 
void ZCD2_ISR(void)
{
    // Clear the ZCD2 interrupt flag
    PIR2bits.ZCD2IF = 0;
    
    ZCD2_UserInterruptHandler();
}

/**
 End of File
*/