/* 
 * File:   application_AD5227.c
 * Author: I62418
 *
 * Created on November 29, 2023, 8:31 AM
 */ 

/******************************************************************************/
/*                                                                            */
/*                               HEADER FILES                                 */
/*                                                                            */
/******************************************************************************/
#include "application_AD5227.h"
#include "mcc_generated_files/system/system.h"
#include "application_AD9833.h"

/******************************************************************************/
/*                                                                            */
/*                USER DEFINED LOCAL FUNCTION DECLARATION                     */
/*                                                                            */
/******************************************************************************/
static void AD5227_CS1_set_level(uint8_t level);
static void AD5227_CS2_set_level(uint8_t level);
static void AD5227_CS3_set_level(uint8_t level);

/******************************************************************************/
/*                                                                            */
/*                    USER DEFINED FUNCTION DEFINITIONS                       */
/*                                                                            */
/******************************************************************************/
void AD5227Select(uint8_t selAD5227)
{
	wfclkSel_st.AD5227_sel = selAD5227;
}

void AD5227DigipotInc(void)
{
	uint8_t transferBuff[2];
	
	transferBuff[0] = 0x1F;
	
    AD5227_CS_LOW
    SPI1_Close();
    SPI1_Open(SPI1_DEFAULT);
    SPI1TCNT = 1;	
	SPI1_BufferWrite(transferBuff,1);
    SPI1_Close();
	AD5227_CS_HIGH
}

void AD5227DigipotDec(void)
{
	uint8_t transferBuff[2];
	
	transferBuff[0] = 0x07;
    
    AD5227_CS_LOW
    SPI1_Close();
    SPI1_Open(SPI1_DEFAULT);
    SPI1TCNT = 1;
	SPI1_BufferWrite(transferBuff,1);
    SPI1_Close();
	AD5227_CS_HIGH
}

void AD5227_chipSelect(uint8_t selAD5227, uint8_t level)
{
	switch(selAD5227)
	{
		case 1:
		AD5227_CS1_set_level(level);
		break;
		case 2:
		AD5227_CS2_set_level(level);
		break;
		case 3:
		AD5227_CS3_set_level(level);
		break;
	}
}

static void AD5227_CS1_set_level(uint8_t level)
{
    if(level)
    {
        AD5227_CS1_SetHigh();
    }
    else
    {
        AD5227_CS1_SetLow();
    }
}

static void AD5227_CS2_set_level(uint8_t level)
{
    if(level)
    {
        AD5227_CS2_SetHigh();
    }
    else
    {
        AD5227_CS2_SetLow();
    }
}

static void AD5227_CS3_set_level(uint8_t level)
{
    if(level)
    {
        AD5227_CS3_SetHigh();
    }
    else
    {
        AD5227_CS3_SetLow();
    }
}