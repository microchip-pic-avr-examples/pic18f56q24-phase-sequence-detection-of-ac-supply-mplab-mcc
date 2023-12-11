#ifndef XC_APPLICATION_H
#define	XC_APPLICATION_H

/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include <xc.h>
#include <math.h>
#include "mcc_generated_files/system/system.h"
#include "application_AD5227.h"
#include "application_AD9833.h"

/******************************************************************************/
/*                                                                            */
/*                            USER DEFINED MACROS                             */
/*                                                                            */
/******************************************************************************/

/* ADC FACTORS */
#define ADC_STEPS_PER_VOLTAGE   (0.00322f)          // 10-bit ADC Step value = (3.3V/1024)
#define ADC_OFFSET_VALUE        (550)               // Practically generated signal offset

/* DATA STREAMER PARAMETERS */
#define START_OF_FRAME          (0x03)              // Data Streamer Start Of Frame (SOF)
#define END_OF_FRAME            (0xFC)              // Data Streamer End Of Frame (EOF)

/* APPLICATION BASED MACROS */
#define EMPTY_BUFFER            (0)

#define FLAG_SET                (1)
#define FLAG_RESET              (0)

#define CHANNEL_B               (0)
#define CHANNEL_G               (1)
#define CHANNEL_R               (2)
#define CHANNEL_COUNT           (3)

#define AMPL_DEC_LIMIT          (9)
#define AMPL_INC_LIMIT          (20)

#define PHASE_LOSS              (0)
#define NO_PHASE_LOSS           (1)

#define DS_BUFFER_SIZE          (12)

#define NO_REV                  (0x00)
#define PHASE_REV               (0x01)

#define PHASE_SHIFT_MIN_TIME    (0.003)
#define PHASE_SHIFT_MAX_TIME    (0.008)

/******************************************************************************/
/*                                                                            */
/*                          USER DEFINED STRUCTURES                           */
/*                                                                            */
/******************************************************************************/

/* DATA STREAMER FIELDS */
typedef struct{
	uint8_t start_of_frame;         // 1B
	uint16_t RsignalData;           // 2B
	uint16_t YsignalData;           // 2B
	uint16_t BsignalData;           // 2B
	uint8_t phaseReversalFlag;      // 1B
	uint8_t phaseLossFlag[3];       // 3B
	uint8_t Opfreq;                 // 1B
	uint8_t end_of_frame;           // 1B
}DataStreamer_st;

/* DATA STREAMER FRAME CREATION */
typedef union {
	uint8_t  DataStreamer_buffer[12]; 
    DataStreamer_st dataStreamer_st;	
}DataStreamerFrame_u;

/* SIGNAL STATES */
enum SIGNAL_STAGES { 
    RECOVER_S = 0,           
	RMV_R_S = 1,
	RMV_Y_S = 2,
    RMV_B_S,
	PHASE_RVRSL_S
};

/******************************************************************************/
/*                                                                            */
/*                          USER DEFINED VARIABLES                            */
/*                                                                            */
/******************************************************************************/
uint8_t freqSelection = DeFHz;              // frequency to be selected for the signal
uint8_t RxData[2] = {EMPTY_BUFFER};         // Reading data byte from the data visualizer custom dashboard

uint16_t numberofSamples = 0;               // Number of samples in the wave
uint16_t targetedSamples = 35;              // Number of samples in two cycles
uint16_t ADC_Results_L[4] = {EMPTY_BUFFER}; // Buffer to save register value of ADRESL

float Vrms[3] = {0.00};                     // Buffer containing Root Mean Square value of each phase
float frequencyValue = DEFAULT_FREQ1;       // Frequency of input signal
float line_voltage[3] = {EMPTY_BUFFER};     // Line voltage of each phase

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DECLARATION                       */
/*                                                                            */
/******************************************************************************/

/**
 * void application(void)
 * 
 * @brief API to run the application. It is scheduled to reproduce the simulated 3 phase signal,
 *        phase loss logic, phase reversal logic, refresh the emulator signal, and receive user
 *        command and execute the commands.
 * 
 * @param None.
 * @return None.
 */
void application(void);

/**
 * void getRphaseStatus(void)
 * 
 * @brief API to get the status of R-Phase.
 * 
 * @param None.
 * @return None.
 */
void getRphaseStatus(void);

/**
 * void getGphaseStatus(void)
 * 
 * @brief API to get the status of G-Phase.
 * 
 * @param None.
 * @return None.
 */
void getGphaseStatus(void);

/**
 * void getBphaseStatus(void)
 * 
 * @brief API to get the status of B-Phase.
 * 
 * @param None.
 * @return None.
 */
void getBphaseStatus(void);

/**
 * void read3PhaseSignal(void)
 * 
 * @brief API to read 3 phase signals (R Y B) through ADC channels.
 * 
 * @param None.
 * @return None.
 */
void read3PhaseSignal(void);

/**
 * void threePhaseAmplitudeMax(void)
 * 
 * @brief API to increase the amplitude of the 3 phase signals (R G B).
 * 
 * @param None.
 * @return None.
 */
void threePhaseAmplitudeMax(void);

/**
 * void threePhaseAmplitudeMin(void)
 * 
 * @brief API to decrease the amplitude of the 3 phase signals (R G B).
 * 
 * @param None.
 * @return None.
 */
void threePhaseAmplitudeMin(void);

/**
 * void defaultSignalGeneration(void)
 * 
 * @brief API to generate default signals for 3 Phase Sequence Detection (PSD) input.
 * 
 * @param None.
 * @return None.
 */
void defaultSignalGeneration(void);

/**
 * void readSwToSelectFrequency(void)
 * 
 * @brief API to read switch press event to accept user input for selecting signal frequency (50/60 Hz).
 * 
 * @param None.
 * @return None.
 */
void readSwToSelectFrequency(void);

/**
 * void phaseLossDetectionStatus(void)
 * 
 * @brief API to identify phase loss on R G B phases.
 * 
 * @param None.
 * @return None.
 */
void phaseLossDetectionStatus(void);

/**
 * void createDataStreamProtocolAndSend(void)
 * 
 * @brief API to create data buffer for data streamer and transmit the buffer to data visualizer.
 * 
 * @param None.
 * @return None.
 */
void createDataStreamProtocolAndSend(void);

/**
 * void frequencySelectionCallBack(void)
 * 
 * @brief API to select the frequency of input signal for the PSD application.
 * 
 * @param userFreqSelection - user input for selecting the frequency
 * @return None.
 */
void frequencySelectionCallBack(uint8_t userFreqSelection);

/**
 * void sendString(uint8_t *data,uint16_t length)
 * 
 * @brief API to send string via UART.
 * 
 * @param data   - data string to transmit 
 *        length - size of the string 
 * @return None.
 */
void sendString(uint8_t *data,uint16_t length);

/**
 * void sineWaveGeneration(uint8_t clickSelect, float inputFreq, float inputPhase)
 * 
 * @brief API to generate sine wave on selected SPI module
 * 
 * @param clickSelect - SPI client (waveform click) number
 *        inputFreq   - frequency of the signal
 *        inputPhase  - phase of the signal
 * @return None.
 */
void sineWaveGeneration(uint8_t clickSelect, float inputFreq, float inputPhase);

/**
 * float calculateVrms(void)
 * 
 * @brief API to calculate the Vrms for the requested phase.
 * 
 * @param None.
 * @return return calculated RMS voltage. 
 */
float calculateVrms(void);

/**
 * uint8_t phaseReversalDetection(void)
 * 
 * @brief API to calculate the time between the two phases and update the phase reversal flag 
 *        field in the data streamer buffer.
 * 
 * @param None.
 * @return 0 - No Phase Reversal
 *         1 - Phase reversal detected
 */
uint8_t phaseReversalDetection(void);

/**
 * uint8_t emulatorTaskProcess(uint8_t status)
 * 
 * @brief API to process user commands for changing the characteristics of generated wave 
 *        for demonstrating the application functionalities. 
 * 
 * @param status - Status of sine wave.
 * @return 1 or 0 depending on the status.
 */
uint8_t emulatorTaskProcess(uint8_t status);

/**
 * uint16_t waveformAproxPhasecalculation(float phase)
 * 
 * @brief API to calculate the phase value to be set in phase bit field of the AD9833 register.
 * 
 * @param phase - phase to be shifted.
 * @return phase value to be set in the control register.
 */
uint16_t waveformAproxPhasecalculation(float phase);

/**
 * uint32_t waveformAproxFreqcalculation(float frequency)
 * 
 * @brief API to calculate the frequency value to be set in frequency bit field of the AD9833 register.
 * 
 * @param frequency - frequency to be set.
 * @return frequency value to be set in the control register.
 */
uint32_t waveformAproxFreqcalculation(float frequency);

/**
 * void TMR4_UserInterruptHandler(void)
 * 
 * @brief User defined TMR4 interrupt handler.
 * 
 * @param None.
 * @return None.
 */
void TMR4_UserInterruptHandler(void);

#endif	/* XC_APPLICATION_H */