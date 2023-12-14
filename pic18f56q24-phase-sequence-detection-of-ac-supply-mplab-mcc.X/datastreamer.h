#ifndef XC_DATASTREAMER_H
#define	XC_DATASTREAMER_H

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
 * void createDataStreamProtocolAndSend(void)
 * 
 * @brief API to create data buffer for data streamer and transmit the buffer to data visualizer.
 * 
 * @param None.
 * @return None.
 */
void createDataStreamProtocolAndSend(void);

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
 * uint8_t emulatorTaskProcess(uint8_t status)
 * 
 * @brief API to process user commands for changing the characteristics of generated wave 
 *        for demonstrating the application functionalities. 
 * 
 * @param status - Status of sine wave.
 * @return 1 or 0 depending on the status.
 */
uint8_t emulatorTaskProcess(uint8_t status);

#endif	/* XC_DATASTREAMER_H */