#ifndef AD5227_H_
#define AD5227_H_
 
/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include <stdio.h>
#include "stdint.h"

/******************************************************************************/
/*                                                                            */
/*                            USER DEFINED MACROS                             */
/*                                                                            */
/******************************************************************************/
#define AD5227_CS_LOW    AD5227_chipSelect(wfclkSel_st.AD5227_sel,false);     // AD5227_CS1_set_level(0)
#define AD5227_CS_HIGH   AD5227_chipSelect(wfclkSel_st.AD5227_sel,true);  	  // AD5227_CS1_set_level(1)	

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DECLARATION                       */
/*                                                                            */
/******************************************************************************/

/**
 * void AD5227DigipotDec(void)
 * 
 * @brief API to decrease the pk-pk voltage of the signal (AD5227 digital pot).
 * 
 * @param None.
 * @return None.
 */
void AD5227DigipotDec(void);

/**
 * void AD5227DigipotInc(void)
 * 
 * @brief API to increase the pk-pk voltage of the signal (AD5227 digital pot).
 * 
 * @param None.
 * @return None.
 */
void AD5227DigipotInc(void);

/**
 * void AD5227DigipotMax(uint8_t click)
 * 
 * @brief API to increase the voltage of selected click to maximum value.
 * 
 * @param click - client address (SPI client AD5227)
 * @return None.
 */
void AD5227DigipotMax(uint8_t click);

/**
 * void AD5227DigipotMin(uint8_t click)
 * 
 * @brief API to decrease the voltage of selected click to minimum value.
 * 
 * @param click - client address (SPI client AD5227)
 * @return None.
 */
void AD5227DigipotMin(uint8_t click);

/**
 * void AD5227Select(uint8_t selAD5227)
 * 
 * @brief API to select the SPI client device (AD9833 device)
 * 
 * @param click - click select
 * @return None.
 */
void AD5227Select(uint8_t selAD5227);

/**
 * void AD5227_chipSelect(uint8_t selAD5227, uint8_t level)
 * 
 * @brief API to select SPI client2 
 * 
 * @param selAD9833 - slave to be select
 *        level - number of bytes to be read
 * @return None.
 */
void AD5227_chipSelect(uint8_t selAD5227, uint8_t level);

#endif /* AD5227_H_ */