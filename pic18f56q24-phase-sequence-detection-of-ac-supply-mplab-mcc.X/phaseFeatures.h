#ifndef XC_PHASEFEATURES_H
#define	XC_PHASEFEATURES_H

/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include "application.h"

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DECLARATION                       */
/*                                                                            */
/******************************************************************************/

/**
 * void updateRphaseStatus(void)
 * 
 * @brief API to get the status of R-Phase.
 * 
 * @param None.
 * @return None.
 */
void updateRphaseStatus(void);

/**
 * void updateGphaseStatus(void)
 * 
 * @brief API to get the status of G-Phase.
 * 
 * @param None.
 * @return None.
 */
void updateGphaseStatus(void);

/**
 * void updateBphaseStatus(void)
 * 
 * @brief API to get the status of B-Phase.
 * 
 * @param None.
 * @return None.
 */
void updateBphaseStatus(void);

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
 * void phaseLossDetectionStatus(void)
 * 
 * @brief API to identify phase loss on R G B phases.
 * 
 * @param None.
 * @return None.
 */
void phaseLossDetectionStatus(void);

/**
 * void calculateVrms(void)
 * 
 * @brief API to calculate the Vrms for the requested phase.
 * 
 * @param None.
 * @return return calculated RMS voltage. 
 */
void calculateVrms(void);

/**
 * float calculateLineVtg(void)
 * 
 * @brief API to calculate the Line Voltage for the G-phase.
 * 
 * @param None.
 * @return None. 
 */
void calculateLineVtg(void);

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

#endif	/* XC_PHASEFEATURES_H */