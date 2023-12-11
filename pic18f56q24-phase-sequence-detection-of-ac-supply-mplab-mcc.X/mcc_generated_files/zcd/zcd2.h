/**
 * ZCD2 Generated Driver API Header File.
 * 
 * @file zcd2.h
 * 
 * @defgroup  zcd2 ZCD2
 * 
 * @brief This file contains the API prototypes for the ZCD2 driver.
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

#ifndef ZCD2_H
#define ZCD2_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: ZCD2 Module APIs
*/

/**
 * @ingroup zcd2
 * @brief Initializes the ZCD2 module. This is called only once before calling other ZCD2 APIs.
 * @param None.
 * @return None.
*/
void ZCD2_Initialize(void);

/**
 * @ingroup zcd2
 * @brief Returns the status of the ZCD pin if it is sinking or sourcing current depending on the selected output polarity.
 * @pre ZCD2_Initialize() is already called.
 * @param None.
 * @retval True - ZCD pin is sinking current (Non-inverted polarity) / ZCD pin is sourcing current (Inverted polarity).
 * @retval False - ZCD pin is sourcing current (Non-inverted polarity) / ZCD pin is sinking current (Inverted polarity).
*/
bool ZCD2_IsLogicLevel(void);

/**
 * @ingroup zcd2
 * @brief Implements the Interrupt Service Routine (ISR) for the ZCD2 interrupt.
 * @param None.
 * @return None.
*/
void ZCD2_ISR(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  //ZCD2_H
/**
 End of File
*/
