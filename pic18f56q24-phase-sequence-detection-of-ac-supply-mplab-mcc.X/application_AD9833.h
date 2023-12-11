#ifndef _AD9833_H_
#define _AD9833_H_

/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include <stdio.h>
#include "stdint.h"

/******************************************************************************/
/*                                                                            */
/* 						  WAVEFORM GENERATOR (AD9833)                         */
/*                                                                            */
/******************************************************************************/
#define AD9833_REG_CMD		(0 << 14)                        // Register commands
#define AD9833_REG_FREQ0	(1 << 14)
#define AD9833_REG_FREQ1	(2 << 14)
#define AD9833_REG_PHASE0	(6 << 13)
#define AD9833_REG_PHASE1	(7 << 13)

#define AD9833_B28			(1 << 13)                        // Command Control Bits
#define AD9833_HLB			(1 << 12)
#define AD9833_FSEL0		(0 << 11)
#define AD9833_FSEL1		(1 << 11)
#define AD9833_PSEL0		(0 << 10)
#define AD9833_PSEL1		(1 << 10)
#define AD9833_PIN_SW		(1 << 9)
#define AD9833_RESET		(1 << 8)
#define AD9833_SLEEP1		(1 << 7)
#define AD9833_SLEEP12		(1 << 6)
#define AD9833_OPBITEN		(1 << 5)
#define AD9833_SIGN_PIB		(1 << 4)
#define AD9833_DIV2			(1 << 3)
#define AD9833_MODE			(1 << 1)

#define AD9833_OUT_SINUS	((0 << 5) | (0 << 1) | (0 << 3))    // Setup configuration commands
#define AD9833_OUT_TRIANGLE	((0 << 5) | (1 << 1) | (0 << 3))
#define AD9833_OUT_MSB		((1 << 5) | (0 << 1) | (1 << 3))
#define AD9833_OUT_MSB2		((1 << 5) | (0 << 1) | (0 << 3))

/******************************************************************************/
/*                                                                            */
/*                            USER DEFINED MACROS                             */
/*                                                                            */
/******************************************************************************/
#define ZERO_FREQ           (0)                              // Frequencies
#define DEFAULT_FREQ1       (50)
#define DEFAULT_FREQ2       (60)

#define PHASE_SHIFT1        (0)                              // Phase Shifts
#define PHASE_SHIFT2        (120)
#define PHASE_SHIFT3        (240)

#define NUMBER_OF_SAMPLES_50Hz  (35)
#define NUMBER_OF_SAMPLES_60Hz  (35)
#define MIN_RMS_VOLTAGE         (0.5)                        // Minimum voltage near to zero 
#define SWITCH_TIME_COUNT       (10000)                      //(20000 = 10sec)    
#define REFRESH_COUNT           (300000)                     // 5 mins 
#define BITS_PER_DEG            (2.84444f)                   //(1024/360)
#define TIMER_TIME_PER_CLOCK    (0.000128f)                  // CLock Freq/
#define WAVEFORM_OSC_FREQ       (25000000.0f)                // Waveform click oscillator frequency 
#define WAVEFORM_CONSTANT       (268435456.0f)               // Frequency Equation constant 

#define AD9833_CS_HIGH          AD9833_chipSelect(wfclkSel_st.AD9833_sel,true);  // For click 1 AD9833_FSN1_set_level(1)
#define AD9833_CS_LOW           AD9833_chipSelect(wfclkSel_st.AD9833_sel,false); // For click 1 AD9833_FSN1_set_level(0)

/******************************************************************************/
/*                                                                            */
/*                          USER DEFINED STRUCTURES                           */
/*                                                                            */
/******************************************************************************/
typedef struct waveformClickSelector 
{
	uint8_t AD9833_sel;                                     // Signal Generation 
	uint8_t AD5227_sel;                                     // Digital pot 
}WfclkSel_st;

enum WfClickSG_e { 
    WfClickSG_1 = 1,
	WfClickSG_2 = 2,
	WfClickSG_3 = 3
};

enum FREQ_sel { 
    DeFHz = 1,
	F50Hz = 1,
	F60Hz =2
};

WfclkSel_st wfclkSel_st;

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DECLARATION                       */
/*                                                                            */
/******************************************************************************/

/**
 * void AD9833Reset(void)
 * 
 * @brief API to reset the AD9833 signal generator by making the reset bit high.
 * 
 * @param None.
 * @return None.
 */
void AD9833Reset(void);

/**
 * void AD9833ClearReset(void)
 * 
 * @brief API to clear the reset by making the rest bit low.
 * 
 * @param None.
 * @return None.
 */
void AD9833ClearReset(void);

/**
 * void AD9833Select(uint8_t selAD9833)
 * 
 * @brief API to select the SPI client device (AD9833 device).
 * 
 * @param selAD9833 - client to be selected.
 * @return None.
 */
void AD9833Select(uint8_t selAD9833);

/**
 * void AD9833SetRegisterValue(unsigned short regValue)
 * 
 * @brief API to set the AD9833 register value.
 * 
 * @param regValue - value to be written to the AD9833 register.
 * @return None.
 */
void AD9833SetRegisterValue(unsigned short regValue);

/**
 * void AD9833_chipSelect(uint8_t selAD9833, uint8_t level)
 * 
 * @brief API to select SPI client1.
 * 
 * @param selAD9833 - client to be selected.
 *        bytesNumber - number of bytes to be read.
 * @return None.
 */
void AD9833_chipSelect(uint8_t selAD9833, uint8_t level);

/**
 * void AD9833SetPhase(unsigned short reg, unsigned short val)
 * 
 * @brief API to load the phase value in to AD9833 phase bit field of the register.
 * 
 * @param reg - register address
 *        val - phase value
 * @return None.
 */
void AD9833SetPhase(unsigned short reg, unsigned short val);

/**
 * void AD9833SetFrequency(unsigned short reg, unsigned long val)
 * 
 * @brief API to load the frequency value in to AD9833 frequency bit field of the register.
 * 
 * @param reg - register address
 *        val - frequency value
 * @return None.
 */
void AD9833SetFrequency(unsigned short reg, unsigned long val);

/**
 * void AD9833Setup(uint16_t freq, uint16_t phase, uint16_t type)
 * 
 * @brief API to setup the register for generating the signal.
 * 
 * @param freq - frequency value
 *         phase - phase value
 *         type - type of the waveform 
 * @return None.
 */
void AD9833Setup(uint16_t freq, uint16_t phase, uint16_t type);

#endif // _AD9833_H