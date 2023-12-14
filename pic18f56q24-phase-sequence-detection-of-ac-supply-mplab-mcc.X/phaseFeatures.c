/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include "phaseFeatures.h"

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DEFINITIONS                       */
/*                                                                            */
/******************************************************************************/

void updateRphaseStatus(void)
{
    uint8_t phaseRstatus;
    if(phaseRSignalCounter > CYCLE_COUNT)
    {
        phaseRSignalCounter = PH_DETECT_CYCLE_COUNT;
        phaseRstatus = PHASE_LOSS;                   // R-Phase Loss
    }
    else
    {
        phaseRstatus = NO_PHASE_LOSS;                // No R-Phase Loss
    }
    dataStreamerFrame_u.dataStreamer_st.phaseLossFlag[CHANNEL_R] = phaseRstatus;
}

void updateGphaseStatus(void)
{
    uint8_t phaseGstatus;
	if (!(timer4OvfCnt <= targetedSamples))
	{
        if(Vrms[CHANNEL_G] <= MIN_RMS_VOLTAGE)
        {
            phaseGstatus = PHASE_LOSS;               // G-Phase loss
        }
        else
        {
            phaseGstatus = NO_PHASE_LOSS;            // No G-Phase loss 
        }
        dataStreamerFrame_u.dataStreamer_st.phaseLossFlag[CHANNEL_G] = phaseGstatus;
	}
}

void updateBphaseStatus(void)
{
    uint8_t phaseBstatus;
    if(phaseBSignalCounter > CYCLE_COUNT)
    {
        phaseBSignalCounter = PH_DETECT_CYCLE_COUNT;
        phaseBstatus = PHASE_LOSS;                   // B-Phase Loss
    }
    else
    {
        phaseBstatus = NO_PHASE_LOSS;                // No B-Phase Loss
    }
    dataStreamerFrame_u.dataStreamer_st.phaseLossFlag[CHANNEL_B] = phaseBstatus;
}

void read3PhaseSignal(void)
{
	uint16_t i;

    for (i= 0;i<CHANNEL_COUNT;i++)                                            // Read signal for reproducing the simulated 3-phase input and Vrms calculation 
    {
        ADC_Results_L[i] = ADCC_GetSingleConversion(i);  
        ADCC_StopConversion();
    }
    calculateLineVtg();
}

void sineWaveGeneration(uint8_t clickSelect, float inputFreq, float inputPhase)
{
    uint32_t freq = 0;
    uint16_t phase = 0;
	
	freq  = waveformAproxFreqcalculation(inputFreq);       // Generate sine wave with provided characteristics input 
	phase = waveformAproxPhasecalculation(inputPhase);
	
    AD9833Select(clickSelect);
	AD9833Reset();
	AD9833SetFrequency(AD9833_REG_FREQ0, freq); 
	AD9833SetPhase(AD9833_REG_PHASE0,phase);
	AD9833ClearReset();
	AD9833Setup(AD9833_FSEL0, AD9833_PSEL0, AD9833_OUT_SINUS);	 
}

void phaseLossDetectionStatus(void)
{
    updateRphaseStatus();
    updateGphaseStatus();
    updateBphaseStatus();
}

void calculateVrms(void)
{
    float voltage = 0.0;
   
  	if ((timer4OvfCnt >= CALC_Vrms_CYCLE ))
  	{
		timer4OvfCnt = COUNTER_RESET;
        voltage = (line_voltage[CHANNEL_G]/numberofSamples);        // Averaging the cumulative raw ADC value  
        line_voltage[CHANNEL_G] = 0;
        Vrms[CHANNEL_G] = (uint16_t)sqrt(voltage);    
        numberofSamples = 0;
    }
}

void calculateLineVtg(void)
{
    if (timer4OvfCnt <= targetedSamples)
    {
        if (ADC_Results_L[CHANNEL_G] > ADC_OFFSET_VALUE)
        {
            numberofSamples++;
            line_voltage[CHANNEL_G] += pow((ADC_STEPS_PER_VOLTAGE * ADC_Results_L[CHANNEL_G]),2);
        }	
    }
}

uint8_t phaseReversalDetection(void)
{
	volatile float phaseShiftTime = 0.0;
	uint8_t statusflag;
	phaseShiftTime = (float)(timer2CounterValue * TIMER_TIME_PER_CLOCK);
    
    /*  Check the RMS voltage to detect the phase loss by checking the voltage */
	if((phaseShiftTime > PHASE_SHIFT_MIN_TIME) && (phaseShiftTime < PHASE_SHIFT_MAX_TIME)) 
	{
		dataStreamerFrame_u.dataStreamer_st.phaseReversalFlag = NO_PHASE_REV;
		statusflag = FLAG_RESET;                                                   // No reversal identified
	}
	else
	{
		dataStreamerFrame_u.dataStreamer_st.phaseReversalFlag = PHASE_REV;
		statusflag = FLAG_SET;                                                     // Phase reversed between L1 and L3
	}
    return statusflag;
}

