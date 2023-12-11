/**
 * ZCD1 Generated Driver API Header File.
 * 
 * @file zcd1.h
 * 
 * @defgroup  zcd1 ZCD1
 * 
 * @brief This file contains the API prototypes for the ZCD1 driver.
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

#ifndef ZCD1_H
#define ZCD1_H

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
  Section: ZCD1 Module APIs
*/

/**
 * @ingroup zcd1
 * @brief Initializes the ZCD1 module. This is called only once before calling other ZCD1 APIs.
 * @param None.
 * @return None.
*/
void ZCD1_Initialize(void);

/**
 * @ingroup zcd1
 * @brief Returns the status of the ZCD pin if it is sinking or sourcing current depending on the selected output polarity.
 * @pre ZCD1_Initialize() is already called.
 * @param None.
 * @retval True - ZCD pin is sinking current (Non-inverted polarity) / ZCD pin is sourcing current (Inverted polarity).
 * @retval False - ZCD pin is sourcing current (Non-inverted polarity) / ZCD pin is sinking current (Inverted polarity).
*/
bool ZCD1_IsLogicLevel(void);

/**
 * @ingroup zcd1
 * @brief Implements the Interrupt Service Routine (ISR) for the ZCD1 interrupt.
 * @param None.
 * @return None.
*/
void ZCD1_ISR(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif  //ZCD1_H
/**
 End of File
*/
