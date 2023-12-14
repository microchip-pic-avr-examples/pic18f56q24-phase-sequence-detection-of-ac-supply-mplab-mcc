/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include "datastreamer.h"

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DEFINITIONS                       */
/*                                                                            */
/******************************************************************************/
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
        dataStreamerFrame_u.dataStreamer_st.Opfreq = frequencyValue;
    }
    else if (freqSelection == F60Hz)
    {
        dataStreamerFrame_u.dataStreamer_st.Opfreq = frequencyValue;
    }
    sendString(dataStreamerFrame_u.DataStreamer_buffer,DS_BUFFER_SIZE);
}

void sendString(uint8_t *data, uint16_t length)
{
	uint16_t  index = 0;
	for (index = 0; index <= length; index++)
	{
        while(!UART2_IsTxReady());  
        UART2_Write(*data++);
	}
}

uint8_t emulatorTaskProcess(uint8_t status)
{
    switch(status)
    {
        case RECOVER_S:
            sineWaveGeneration(WfClickSG_1,frequencyValue,PHASE_SHIFT_0Deg);            // Recover signal to previous state 
            sineWaveGeneration(WfClickSG_2,frequencyValue,PHASE_SHIFT_120Deg);
            sineWaveGeneration(WfClickSG_3,frequencyValue,PHASE_SHIFT_240Deg);
        break;
        case RMV_R_S:                                                                   // Remove R line from the 3-phase 
            sineWaveGeneration(WfClickSG_3,ZERO_FREQ,PHASE_SHIFT_0Deg);    
        break;
        case RMV_Y_S:                                                                   // Remove Y line from the 3-phase
            sineWaveGeneration(WfClickSG_2,ZERO_FREQ,PHASE_SHIFT_0Deg);
        break;
        case RMV_B_S:                                                                   // Remove B line from the 3-phase 
            sineWaveGeneration(WfClickSG_1,ZERO_FREQ,PHASE_SHIFT_0Deg);
        break;
        case PHASE_RVRSL_S:                                                             // Changing the third line for phase reversal simulation 
            sineWaveGeneration(WfClickSG_1,frequencyValue,PHASE_SHIFT_240Deg);
            sineWaveGeneration(WfClickSG_2,frequencyValue,PHASE_SHIFT_120Deg);
            sineWaveGeneration(WfClickSG_3,frequencyValue,PHASE_SHIFT_0Deg);
        break;
        default: 
            return 1;
        break;
    }
    return 0;
}