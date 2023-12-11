/* 
 * File:   application.c
 * Author: I62418
 *
 * Created on November 29, 2023, 10:55 AM
 */

/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "application.h"

/******************************************************************************/
/*                                                                            */
/*                       USER DEFINED LOCAL VARIABLES                         */
/*                                                                            */
/******************************************************************************/
volatile uint8_t  timer4OverflowFlag = 0;           
volatile uint32_t refreshCount       = 0;
volatile uint16_t timer4OvfCnt       = 0;

volatile uint8_t flagRSignal;
volatile uint8_t flagBSignal;
volatile uint16_t timerCounterValue;

extern volatile uint8_t ZCD_Int_flag[3];            
extern volatile uint8_t PhaseLossFlag[3];           // For 3 ZCD solution (64 pin controller)

DataStreamerFrame_u dataStreamerFrame_u;

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DEFINITIONS                       */
/*                                                                            */
/******************************************************************************/
void application(void)
{
    if(timer4OverflowFlag  == FLAG_SET)
    {
	   timer4OverflowFlag = FLAG_RESET;       
	   read3PhaseSignal();                      // Read three-phase signal using ADC 
       createDataStreamProtocolAndSend();       // Create data to data streamer protocol format and send to data visualizer via USART
       phaseLossDetectionStatus();              // Phase loss detection 
       phaseReversalDetection();                // Phase reversal detection   
       calculateVrms();                         // Calculate Vrms (***Note - timeOverflow counter is reseted in this function)
    }
    
    if(refreshCount >= REFRESH_COUNT)
	{
	   refreshCount = FLAG_RESET;
	   emulatorTaskProcess(RECOVER_S);          // Refreshing simulated 3 phase signal for stabilized signal on screen	
	}
	
	if(UART2__IsRxReady())
	{
		for (int i=0;i<=1;i++)                  // Reading two bytes from the data visualizer
		{
			RxData[i] = UART2_Read();
		}
		refreshCount = FLAG_RESET;              // Resetting the refresh count when user is operating the system
		timer4OverflowFlag = FLAG_RESET;        // Explicitly reseting to avoid case 7 when simulation command received
		emulatorTaskProcess(RxData[1]);                  
	}
}

void threePhaseAmplitudeMax(void)
{
	uint8_t i,j = 0;	
	for (i=1;i<=3;i++)                          // Increase R Y B phase amplitude 
	{
		for (j=0;j<=AMPL_INC_LIMIT;j++)
		{
			AD5227Select(i);
			AD5227DigipotInc();
		}
	}
}

void threePhaseAmplitudeMin(void)
{
	uint8_t i,j = 0;	
	for (i=1;i<=CHANNEL_COUNT;i++)              // Decrease R Y B phase amplitude 
	{
		for (j=0;j<=AMPL_DEC_LIMIT;j++)
		{
			AD5227Select(i);
			AD5227DigipotDec();
		}
	}
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

uint32_t waveformAproxFreqcalculation(float frequency)
{
	uint32_t calculation = 0;
	
	calculation =(uint32_t)(frequency * ( WAVEFORM_CONSTANT / WAVEFORM_OSC_FREQ ));	
	return calculation;
}

uint16_t waveformAproxPhasecalculation(float phase)
{
	uint16_t calculation = 0;
	
	calculation = (phase * BITS_PER_DEG);  	
	return calculation;
}

void defaultSignalGeneration(void)
{
	sineWaveGeneration(WfClickSG_1, DEFAULT_FREQ1, PHASE_SHIFT1);               // Default frequency generation 
	sineWaveGeneration(WfClickSG_2, DEFAULT_FREQ1, PHASE_SHIFT2);
	sineWaveGeneration(WfClickSG_3, DEFAULT_FREQ1, PHASE_SHIFT3);	
}

void readSwToSelectFrequency(void)
{
	uint8_t freq_toggle_flag = 0;
	
    while (timer4OvfCnt <= SWITCH_TIME_COUNT)                                   // Using timer1 and waiting for user to select the frequency
	{                                                                           // If user not select any frequency, default (50Hz) will be used
		if (SW_GetValue() == false)                                             // Read switch 
		{
			timer4OvfCnt     = FLAG_RESET;
			freq_toggle_flag = ~freq_toggle_flag;
			frequencySelectionCallBack(freq_toggle_flag);
			__delay_ms(500);
		}
	}
}

void frequencySelectionCallBack(uint8_t userFreqSelection)
{
	if (userFreqSelection)
	{
		freqSelection   = F60Hz;	
		frequencyValue  = DEFAULT_FREQ2;
        targetedSamples = NUMBER_OF_SAMPLES_60Hz;
	}
	else
	{
		freqSelection   = F50Hz;
		frequencyValue  = DEFAULT_FREQ1;
        targetedSamples = NUMBER_OF_SAMPLES_50Hz;
	}
	createDataStreamProtocolAndSend();
}

void read3PhaseSignal(void)
{
	uint16_t i = 0;

    for (i= 0;i<=2;i++)                                            // Read signal for reproducing the simulated 3-phase input and Vrms calculation 
    {
        ADC_Results_L[i] = ADCC_GetSingleConversion(i);  
        ADCC_StopConversion();
    }  
    if (targetedSamples >= timer4OvfCnt)
    {
        if (ADC_Results_L[CHANNEL_G] > ADC_OFFSET_VALUE)
        {
            numberofSamples++;
            line_voltage[CHANNEL_G] += pow((ADC_STEPS_PER_VOLTAGE * ADC_Results_L[CHANNEL_G]),2);
        }	
    }
}

float calculateVrms(void)
{
    float voltage = 0.0;
   
  	if ((timer4OvfCnt >= 38 ))
  	{
		timer4OvfCnt = FLAG_RESET;
        voltage = (line_voltage[CHANNEL_G]/numberofSamples);        // Averaging the cumulative raw ADC value  
        line_voltage[CHANNEL_G] = 0;
        Vrms[CHANNEL_G] = (uint16_t)sqrt(voltage);    
        numberofSamples = 0;
    }
   return (Vrms[CHANNEL_G]);
}

void createDataStreamProtocolAndSend(void)
{
    dataStreamerFrame_u.dataStreamer_st.start_of_frame = (char)START_OF_FRAME;       
    dataStreamerFrame_u.dataStreamer_st.end_of_frame   = (char)END_OF_FRAME;        
    
    /* Raw ADC data for reproducing data on data visualizer */
    dataStreamerFrame_u.dataStreamer_st.RsignalData    = ADC_Results_L[CHANNEL_B];
    dataStreamerFrame_u.dataStreamer_st.YsignalData    = ADC_Results_L[CHANNEL_G];
    dataStreamerFrame_u.dataStreamer_st.BsignalData    = ADC_Results_L[CHANNEL_R];

    if ((freqSelection == F50Hz) || (freqSelection == DeFHz))
    {
        dataStreamerFrame_u.dataStreamer_st.Opfreq = DEFAULT_FREQ1;
    }
    else if (freqSelection == F60Hz)
    {
        dataStreamerFrame_u.dataStreamer_st.Opfreq = DEFAULT_FREQ2;
    }
    sendString(dataStreamerFrame_u.DataStreamer_buffer,DS_BUFFER_SIZE);
}

void sendString(uint8_t *data,uint16_t length)
{
	uint16_t  index = 0;
	for (index = 0; index <= length; index++)
	{
        while(!UART2_IsTxReady());  
        UART2_Write(*data++);
	}
}

uint8_t phaseReversalDetection(void)
{
	volatile float phaseShiftTime = 0.0;
	
	phaseShiftTime = timerCounterValue * TIMER_TIME_PER_CLOCK;
    
    /*  Check the RMS voltage to detect the phase loss by checking the voltage */
	if((phaseShiftTime > PHASE_SHIFT_MIN_TIME) && (phaseShiftTime < PHASE_SHIFT_MAX_TIME)) 
	{
		dataStreamerFrame_u.dataStreamer_st.phaseReversalFlag = NO_REV;
		return 0;                                                                   // No reversal identified
	}
	else
	{
		dataStreamerFrame_u.dataStreamer_st.phaseReversalFlag = PHASE_REV;
		return 1;                                                                   // Phase reversed between L1 and L3
	}
}

uint8_t emulatorTaskProcess(uint8_t status)
{	                 
 switch(status)
 {
    case RECOVER_S:
		sineWaveGeneration(WfClickSG_1,DEFAULT_FREQ1,PHASE_SHIFT1);                 // Recover signal to previous state 
		sineWaveGeneration(WfClickSG_2,DEFAULT_FREQ1,PHASE_SHIFT2);
		sineWaveGeneration(WfClickSG_3,DEFAULT_FREQ1,PHASE_SHIFT3);
	break;
 	case RMV_R_S:                                                                   // Remove R line from the 3-phase 
		sineWaveGeneration(WfClickSG_3,ZERO_FREQ,PHASE_SHIFT1);    
	break;
	case RMV_Y_S:                                                                   // Remove Y line from the 3-phase
	    sineWaveGeneration(WfClickSG_2,ZERO_FREQ,PHASE_SHIFT1);
	break;
	case RMV_B_S:                                                                   // Remove B line from the 3-phase 
	    sineWaveGeneration(WfClickSG_1,ZERO_FREQ,PHASE_SHIFT1);
	break;
	case PHASE_RVRSL_S:                                                             // Changing the third line for phase reversal simulation 
		sineWaveGeneration(WfClickSG_1,DEFAULT_FREQ1,PHASE_SHIFT3);
		sineWaveGeneration(WfClickSG_2,DEFAULT_FREQ1,PHASE_SHIFT2);
		sineWaveGeneration(WfClickSG_3,DEFAULT_FREQ1,PHASE_SHIFT1);
	break;
	default: 
		return 1;
	break;
 }
return 0;
}

void phaseLossDetectionStatus(void)
{
    getRphaseStatus();
    getGphaseStatus();
    getBphaseStatus();
}

void getRphaseStatus(void)
{
    uint8_t phaseRstatus;
    if(flagRSignal > 30)
    {
        flagRSignal = 31;
        phaseRstatus = PHASE_LOSS;                   // R-Phase Loss
    }
    else
    {
        phaseRstatus = NO_PHASE_LOSS;                // No R-Phase Loss
    }
    dataStreamerFrame_u.dataStreamer_st.phaseLossFlag[CHANNEL_R] = phaseRstatus;
}

void getGphaseStatus(void)
{
    uint8_t phaseGstatus;
	if (!(targetedSamples >= timer4OvfCnt))
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

void getBphaseStatus(void)
{
    uint8_t phaseBstatus;
    if(flagBSignal > 30)
    {
        flagBSignal = 31;
        phaseBstatus = PHASE_LOSS;                   // B-Phase Loss
    }
    else
    {
        phaseBstatus = NO_PHASE_LOSS;                // No B-Phase Loss
    }
    dataStreamerFrame_u.dataStreamer_st.phaseLossFlag[CHANNEL_B] = phaseBstatus;
}

void TMR4_UserInterruptHandler(void)
{
    timer4OverflowFlag = 1;
    timer4OvfCnt++;
	refreshCount++;
    flagRSignal++;
    flagBSignal++;
}

void ZCD1_UserInterruptHandler(void)
{
    TMR2_Write(0);
    ZCD_Int_flag[0]  = 1;
	PhaseLossFlag[0] = 1;
    flagRSignal = 0;
}