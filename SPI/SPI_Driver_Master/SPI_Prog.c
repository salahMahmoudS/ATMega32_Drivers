/*
 * SPI_Prog.c
 *
 *  Created on: Oct 5, 2019
 *      Author: salsa
 */

#include "std_types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "SPI_Reg.h"
#include "SPI_Priv.h"
#include "SPI_Config.h"
#include "SPI_Int.h"

u8 SSPin;
void SPI_voidInitialize(void)
{
#if (SPI_INTERRUPT_ENABLE == ENABLE)
	SET_BIT(SPCR,SPIE);
#elif (SPI_INTERRUPT_ENABLE == DISABLE)
CLEAR_BIT(SPCR,SPIE);
#else
#error "PLEASE SELECT ENABLE OR DISABLE"
#endif


#if (DATA_ORDER_MODE == LSB_FIRST)
SET_BIT(SPCR,DORD);
#elif (DATA_ORDER_MODE == MSB_FIRST)
CLEAR_BIT(SPCR,DORD);
#else
#error "WRONG MODE SELECTED"
#endif

#if (MASTER_MODE == MASTER)
SET_BIT(SPCR,MSTR);
#elif (MASTER_MODE == SLAVE)
CLEAR_BIT(SPCR,MSTR);
#else
#error "PLEASE SELECT MASTER OR SLAVE"
#endif

#if (CLOCK_PLOARITY_MODE == LEAD_FALLING_TRAILING_RISING)
SET_BIT(SPCR,CPOL);
#elif (CLOCK_PLOARITY_MODE ==LEAD_RISING_TRAILING_FALLING)
CLEAR_BIT(SPCR,CPOL);
#else
#error "WRONG MODE SELECTED"
#endif

#if (CLOCK_PHASE_MODE == LEAD_SETUP_TRAILING_SAMPLE)
SET_BIT(SPCR,CPHA);
#elif(CLOCK_PHASE_MODE == LEAD_SAMPLE_TRAILING_SETUP)
CLEAR_BIT(SPCR,CPHA);
#else
#error "WRONG MODE SELECTED"
#endif

#if (SCK_FREQUENCY == FOSC_4)
CLEAR_BIT(SPCR,SPI2X);
CLEAR_BIT(SPCR,SPR1);
CLEAR_BIT(SPCR,SPR0);
#elif (SCK_FREQUENCY == FOSC_16)
CLEAR_BIT(SPCR,SPI2X);
CLEAR_BIT(SPCR,SPR1);
SET_BIT(SPCR,SPR0);
#elif (SCK_FREQUENCY == FOSC_64_0)
CLEAR_BIT(SPCR,SPI2X);
SET_BIT(SPCR,SPR1);
CLEAR_BIT(SPCR,SPR0);

#elif (SCK_FREQUENCY == FOSC_128)
CLEAR_BIT(SPCR,SPI2X);
SET_BIT(SPCR,SPR1);
SET_BIT(SPCR,SPR0);

#elif (SCK_FREQUENCY == FOSC_2)
SET_BIT(SPCR,SPI2X);
CLEAR_BIT(SPCR,SPR1);
CLEAR_BIT(SPCR,SPR0);

#elif (SCK_FREQUENCY == FOSC_8)
SET_BIT(SPCR,SPI2X);
CLEAR_BIT(SPCR,SPR1);
SET_BIT(SPCR,SPR0);

#elif (SCK_FREQUENCY == FOSC_32)
SET_BIT(SPCR,SPI2X);
SET_BIT(SPCR,SPR1);
CLEAR_BIT(SPCR,SPR0);

#elif (SCK_FREQUENCY == FOSC_64_1)
SET_BIT(SPCR,SPI2X);
SET_BIT(SPCR,SPR1);
SET_BIT(SPCR,SPR0);

#else
#error "PLEASE SELECT RIGHT FREQUENCY"
#endif




#if (SPI_ENABLE == ENABLE)
	SET_BIT(SPCR,SPE);
#elif (SPI_ENABLE == DISABLE)
	CLEAR_BIT(SPCR,SPE);
#else
#error "PLEASE SELECT ENABLE OR DISABLE"
#endif

}

void SPI_voidReEnableMasterMode(void)
{
SET_BIT(SPCR,MSTR);
}

u8 SPI_u8ClearSPIF(void)
{
	volatile u8 temp = SPCR;
	u8 data = SPDR;
	return data;
}

u8 SPI_u8ClearWCOL (void)
{
	volatile u8 temp = SPCR;
	u8 data = SPDR;
	return data;
}
u8 SPI_u8SendData(u8 slaveNo, u8 data)
{

switch (slaveNo)
{
case 0:
SSPin = SS0_PIN;
break;
case 1:
SSPin = SS1_PIN;
break;
case 2:
SSPin = SS2_PIN;
break;
case 3:
SSPin = SS3_PIN;
break;
default:
break;
}

DIO_voidWriteOnPin(DIO_PIN_11,DIO_LOW);
SPDR = data;
while (CHECK_BIT(SPSR,SPIF) == 0);
return SPDR;
}

u8 SPI_u8RecieveData()
{
	while(CHECK_BIT(SPSR,SPIF) ==0);
	return SPDR;
}

