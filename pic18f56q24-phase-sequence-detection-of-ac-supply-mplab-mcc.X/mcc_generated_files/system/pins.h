/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define IO_RA0_TRIS                 TRISAbits.TRISA0
#define IO_RA0_LAT                  LATAbits.LATA0
#define IO_RA0_PORT                 PORTAbits.RA0
#define IO_RA0_WPU                  WPUAbits.WPUA0
#define IO_RA0_OD                   ODCONAbits.ODCA0
#define IO_RA0_ANS                  ANSELAbits.ANSELA0
#define IO_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_RA0_GetValue()           PORTAbits.RA0
#define IO_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_RA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_RA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_RA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_RA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_RA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define IO_RA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 aliases
#define IO_RA1_TRIS                 TRISAbits.TRISA1
#define IO_RA1_LAT                  LATAbits.LATA1
#define IO_RA1_PORT                 PORTAbits.RA1
#define IO_RA1_WPU                  WPUAbits.WPUA1
#define IO_RA1_OD                   ODCONAbits.ODCA1
#define IO_RA1_ANS                  ANSELAbits.ANSELA1
#define IO_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_RA1_GetValue()           PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_RA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA4 aliases
#define AD9833_FSN1_TRIS                 TRISAbits.TRISA4
#define AD9833_FSN1_LAT                  LATAbits.LATA4
#define AD9833_FSN1_PORT                 PORTAbits.RA4
#define AD9833_FSN1_WPU                  WPUAbits.WPUA4
#define AD9833_FSN1_OD                   ODCONAbits.ODCA4
#define AD9833_FSN1_ANS                  ANSELAbits.ANSELA4
#define AD9833_FSN1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define AD9833_FSN1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define AD9833_FSN1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define AD9833_FSN1_GetValue()           PORTAbits.RA4
#define AD9833_FSN1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define AD9833_FSN1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define AD9833_FSN1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define AD9833_FSN1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define AD9833_FSN1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define AD9833_FSN1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define AD9833_FSN1_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define AD9833_FSN1_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define AD5227_CS1_TRIS                 TRISAbits.TRISA5
#define AD5227_CS1_LAT                  LATAbits.LATA5
#define AD5227_CS1_PORT                 PORTAbits.RA5
#define AD5227_CS1_WPU                  WPUAbits.WPUA5
#define AD5227_CS1_OD                   ODCONAbits.ODCA5
#define AD5227_CS1_ANS                  ANSELAbits.ANSELA5
#define AD5227_CS1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define AD5227_CS1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define AD5227_CS1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define AD5227_CS1_GetValue()           PORTAbits.RA5
#define AD5227_CS1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define AD5227_CS1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define AD5227_CS1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define AD5227_CS1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define AD5227_CS1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define AD5227_CS1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define AD5227_CS1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define AD5227_CS1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RA6 aliases
#define IO_RA6_TRIS                 TRISAbits.TRISA6
#define IO_RA6_LAT                  LATAbits.LATA6
#define IO_RA6_PORT                 PORTAbits.RA6
#define IO_RA6_WPU                  WPUAbits.WPUA6
#define IO_RA6_OD                   ODCONAbits.ODCA6
#define IO_RA6_ANS                  ANSELAbits.ANSELA6
#define IO_RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_RA6_GetValue()           PORTAbits.RA6
#define IO_RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define IO_RA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define IO_RA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define IO_RA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define IO_RA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define IO_RA6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define IO_RA6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSELB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_WPU                  WPUBbits.WPUB3
#define IO_RB3_OD                   ODCONBbits.ODCB3
#define IO_RB3_ANS                  ANSELBbits.ANSELB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_RB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_RB3_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSELC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_ANS                  ANSELCbits.ANSELC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSELC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC4 aliases
#define AD9833_FSN2_TRIS                 TRISCbits.TRISC4
#define AD9833_FSN2_LAT                  LATCbits.LATC4
#define AD9833_FSN2_PORT                 PORTCbits.RC4
#define AD9833_FSN2_WPU                  WPUCbits.WPUC4
#define AD9833_FSN2_OD                   ODCONCbits.ODCC4
#define AD9833_FSN2_ANS                  ANSELCbits.
#define AD9833_FSN2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define AD9833_FSN2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define AD9833_FSN2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define AD9833_FSN2_GetValue()           PORTCbits.RC4
#define AD9833_FSN2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define AD9833_FSN2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define AD9833_FSN2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define AD9833_FSN2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define AD9833_FSN2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define AD9833_FSN2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define AD9833_FSN2_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define AD9833_FSN2_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RC6 aliases
#define AD9833_FSN3_TRIS                 TRISCbits.TRISC6
#define AD9833_FSN3_LAT                  LATCbits.LATC6
#define AD9833_FSN3_PORT                 PORTCbits.RC6
#define AD9833_FSN3_WPU                  WPUCbits.WPUC6
#define AD9833_FSN3_OD                   ODCONCbits.ODCC6
#define AD9833_FSN3_ANS                  ANSELCbits.
#define AD9833_FSN3_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define AD9833_FSN3_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define AD9833_FSN3_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define AD9833_FSN3_GetValue()           PORTCbits.RC6
#define AD9833_FSN3_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define AD9833_FSN3_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define AD9833_FSN3_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define AD9833_FSN3_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define AD9833_FSN3_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define AD9833_FSN3_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define AD9833_FSN3_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define AD9833_FSN3_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RE0 aliases
#define AD5227_CS3_TRIS                 TRISEbits.TRISE0
#define AD5227_CS3_LAT                  LATEbits.LATE0
#define AD5227_CS3_PORT                 PORTEbits.RE0
#define AD5227_CS3_WPU                  WPUEbits.WPUE0
#define AD5227_CS3_OD                   ODCONEbits.ODCE0
#define AD5227_CS3_ANS                  ANSELEbits.ANSELE0
#define AD5227_CS3_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define AD5227_CS3_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define AD5227_CS3_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define AD5227_CS3_GetValue()           PORTEbits.RE0
#define AD5227_CS3_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define AD5227_CS3_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define AD5227_CS3_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define AD5227_CS3_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define AD5227_CS3_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define AD5227_CS3_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define AD5227_CS3_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define AD5227_CS3_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set RF2 aliases
#define LED_TRIS                 TRISFbits.TRISF2
#define LED_LAT                  LATFbits.LATF2
#define LED_PORT                 PORTFbits.RF2
#define LED_WPU                  WPUFbits.WPUF2
#define LED_OD                   ODCONFbits.ODCF2
#define LED_ANS                  ANSELFbits.ANSELF2
#define LED_SetHigh()            do { LATFbits.LATF2 = 1; } while(0)
#define LED_SetLow()             do { LATFbits.LATF2 = 0; } while(0)
#define LED_Toggle()             do { LATFbits.LATF2 = ~LATFbits.LATF2; } while(0)
#define LED_GetValue()           PORTFbits.RF2
#define LED_SetDigitalInput()    do { TRISFbits.TRISF2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISFbits.TRISF2 = 0; } while(0)
#define LED_SetPullup()          do { WPUFbits.WPUF2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUFbits.WPUF2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONFbits.ODCF2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONFbits.ODCF2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELFbits.ANSELF2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELFbits.ANSELF2 = 0; } while(0)

// get/set RF3 aliases
#define SW_TRIS                 TRISFbits.TRISF3
#define SW_LAT                  LATFbits.LATF3
#define SW_PORT                 PORTFbits.RF3
#define SW_WPU                  WPUFbits.WPUF3
#define SW_OD                   ODCONFbits.ODCF3
#define SW_ANS                  ANSELFbits.ANSELF3
#define SW_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define SW_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define SW_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define SW_GetValue()           PORTFbits.RF3
#define SW_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define SW_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define SW_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define SW_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define SW_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define SW_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define SW_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define SW_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

// get/set RF4 aliases
#define AD5227_CS2_TRIS                 TRISFbits.TRISF4
#define AD5227_CS2_LAT                  LATFbits.LATF4
#define AD5227_CS2_PORT                 PORTFbits.RF4
#define AD5227_CS2_WPU                  WPUFbits.WPUF4
#define AD5227_CS2_OD                   ODCONFbits.ODCF4
#define AD5227_CS2_ANS                  ANSELFbits.ANSELF4
#define AD5227_CS2_SetHigh()            do { LATFbits.LATF4 = 1; } while(0)
#define AD5227_CS2_SetLow()             do { LATFbits.LATF4 = 0; } while(0)
#define AD5227_CS2_Toggle()             do { LATFbits.LATF4 = ~LATFbits.LATF4; } while(0)
#define AD5227_CS2_GetValue()           PORTFbits.RF4
#define AD5227_CS2_SetDigitalInput()    do { TRISFbits.TRISF4 = 1; } while(0)
#define AD5227_CS2_SetDigitalOutput()   do { TRISFbits.TRISF4 = 0; } while(0)
#define AD5227_CS2_SetPullup()          do { WPUFbits.WPUF4 = 1; } while(0)
#define AD5227_CS2_ResetPullup()        do { WPUFbits.WPUF4 = 0; } while(0)
#define AD5227_CS2_SetPushPull()        do { ODCONFbits.ODCF4 = 0; } while(0)
#define AD5227_CS2_SetOpenDrain()       do { ODCONFbits.ODCF4 = 1; } while(0)
#define AD5227_CS2_SetAnalogMode()      do { ANSELFbits.ANSELF4 = 1; } while(0)
#define AD5227_CS2_SetDigitalMode()     do { ANSELFbits.ANSELF4 = 0; } while(0)

// get/set RF5 aliases
#define WC_OE1_TRIS                 TRISFbits.TRISF5
#define WC_OE1_LAT                  LATFbits.LATF5
#define WC_OE1_PORT                 PORTFbits.RF5
#define WC_OE1_WPU                  WPUFbits.WPUF5
#define WC_OE1_OD                   ODCONFbits.ODCF5
#define WC_OE1_ANS                  ANSELFbits.ANSELF5
#define WC_OE1_SetHigh()            do { LATFbits.LATF5 = 1; } while(0)
#define WC_OE1_SetLow()             do { LATFbits.LATF5 = 0; } while(0)
#define WC_OE1_Toggle()             do { LATFbits.LATF5 = ~LATFbits.LATF5; } while(0)
#define WC_OE1_GetValue()           PORTFbits.RF5
#define WC_OE1_SetDigitalInput()    do { TRISFbits.TRISF5 = 1; } while(0)
#define WC_OE1_SetDigitalOutput()   do { TRISFbits.TRISF5 = 0; } while(0)
#define WC_OE1_SetPullup()          do { WPUFbits.WPUF5 = 1; } while(0)
#define WC_OE1_ResetPullup()        do { WPUFbits.WPUF5 = 0; } while(0)
#define WC_OE1_SetPushPull()        do { ODCONFbits.ODCF5 = 0; } while(0)
#define WC_OE1_SetOpenDrain()       do { ODCONFbits.ODCF5 = 1; } while(0)
#define WC_OE1_SetAnalogMode()      do { ANSELFbits.ANSELF5 = 1; } while(0)
#define WC_OE1_SetDigitalMode()     do { ANSELFbits.ANSELF5 = 0; } while(0)

// get/set RF6 aliases
#define WC_OE2_TRIS                 TRISFbits.TRISF6
#define WC_OE2_LAT                  LATFbits.LATF6
#define WC_OE2_PORT                 PORTFbits.RF6
#define WC_OE2_WPU                  WPUFbits.WPUF6
#define WC_OE2_OD                   ODCONFbits.ODCF6
#define WC_OE2_ANS                  ANSELFbits.ANSELF6
#define WC_OE2_SetHigh()            do { LATFbits.LATF6 = 1; } while(0)
#define WC_OE2_SetLow()             do { LATFbits.LATF6 = 0; } while(0)
#define WC_OE2_Toggle()             do { LATFbits.LATF6 = ~LATFbits.LATF6; } while(0)
#define WC_OE2_GetValue()           PORTFbits.RF6
#define WC_OE2_SetDigitalInput()    do { TRISFbits.TRISF6 = 1; } while(0)
#define WC_OE2_SetDigitalOutput()   do { TRISFbits.TRISF6 = 0; } while(0)
#define WC_OE2_SetPullup()          do { WPUFbits.WPUF6 = 1; } while(0)
#define WC_OE2_ResetPullup()        do { WPUFbits.WPUF6 = 0; } while(0)
#define WC_OE2_SetPushPull()        do { ODCONFbits.ODCF6 = 0; } while(0)
#define WC_OE2_SetOpenDrain()       do { ODCONFbits.ODCF6 = 1; } while(0)
#define WC_OE2_SetAnalogMode()      do { ANSELFbits.ANSELF6 = 1; } while(0)
#define WC_OE2_SetDigitalMode()     do { ANSELFbits.ANSELF6 = 0; } while(0)

// get/set RF7 aliases
#define WC_OE3_TRIS                 TRISFbits.TRISF7
#define WC_OE3_LAT                  LATFbits.LATF7
#define WC_OE3_PORT                 PORTFbits.RF7
#define WC_OE3_WPU                  WPUFbits.WPUF7
#define WC_OE3_OD                   ODCONFbits.ODCF7
#define WC_OE3_ANS                  ANSELFbits.ANSELF7
#define WC_OE3_SetHigh()            do { LATFbits.LATF7 = 1; } while(0)
#define WC_OE3_SetLow()             do { LATFbits.LATF7 = 0; } while(0)
#define WC_OE3_Toggle()             do { LATFbits.LATF7 = ~LATFbits.LATF7; } while(0)
#define WC_OE3_GetValue()           PORTFbits.RF7
#define WC_OE3_SetDigitalInput()    do { TRISFbits.TRISF7 = 1; } while(0)
#define WC_OE3_SetDigitalOutput()   do { TRISFbits.TRISF7 = 0; } while(0)
#define WC_OE3_SetPullup()          do { WPUFbits.WPUF7 = 1; } while(0)
#define WC_OE3_ResetPullup()        do { WPUFbits.WPUF7 = 0; } while(0)
#define WC_OE3_SetPushPull()        do { ODCONFbits.ODCF7 = 0; } while(0)
#define WC_OE3_SetOpenDrain()       do { ODCONFbits.ODCF7 = 1; } while(0)
#define WC_OE3_SetAnalogMode()      do { ANSELFbits.ANSELF7 = 1; } while(0)
#define WC_OE3_SetDigitalMode()     do { ANSELFbits.ANSELF7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/