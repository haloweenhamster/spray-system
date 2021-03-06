/**
  ******************** (C) COPYRIGHT 2010 DJI **********************************
  *
  * @Project Name       ��xp60.uvproj
  * @File Name          : lpc17xx_wdt.h
  * @Environment        : keil mdk4.12/LPC1765/100M cclock
  * @Author&Date        : 2011-08-25 
  * @Version            : 1.00
  ******************************************************************************
  * @Description
  *	    lpc17xx wdt module,reference for nxp        
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LPC17XX_ADC_H__
#define __LPC17XX_ADC_H__

/* Includes ------------------------------------------------------------------- */
#include "..\drivers.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Private macros ------------------------------------------------------------- */
#define ADC0_PIN_PORT_0_3           (GPIO_PORT0_FAST)
#define ADC_CH0_PIN                 DEF_BIT_23        /*p0.23 FNCT2 -- AD0.0*/
#define ADC_CH1_PIN					DEF_BIT_24		  /*p0.24 FNCT2 -- AD0.1*/
#define ADC_CH2_PIN                 DEF_BIT_25        /*p0.25 FNCT2 -- AD0.2*/
#define ADC_CH3_PIN					DEF_BIT_26		  /*p0.26 FNCT2 -- AD0.3*/

#define ADC0_PIN_PORT_6_7           (GPIO_PORT0_FAST)
#define ADC_CH6_PIN                 DEF_BIT_03        /*p0.3  FNCT3 -- AD0.6*/
#define ADC_CH7_PIN					DEF_BIT_02		  /*p0.2  FNCT3 -- AD0.7*/

#define ADC0_PIN_PORT_4_5           (GPIO_PORT1_FAST)
#define ADC_CH4_PIN                 DEF_BIT_30        /*p1.30 FNCT3 -- AD0.4*/
#define ADC_CH5_PIN					DEF_BIT_31		  /*p1.31 FNCT3 -- AD0.5*/




/* -------------------------- BIT DEFINITIONS ----------------------------------- */
/*********************************************************************//**
 * Macro defines for ADC  control register
 **********************************************************************/
/**  Selects which of the AD0.0:7 pins is (are) to be sampled and converted */
#define ADC_CR_CH_SEL(n)	((1UL << n))
/**  The APB clock (PCLK) is divided by (this value plus one)
* to produce the clock for the A/D */
#define ADC_CR_CLKDIV(n)	((n<<8))
/**  Repeated conversions A/D enable bit */
#define ADC_CR_BURST		((1UL<<16))
/**  ADC convert in power down mode */
#define ADC_CR_PDN			((1UL<<21))
/**  Start mask bits */
#define ADC_CR_START_MASK	((7UL<<24))
/**  Select Start Mode */
#define ADC_CR_START_MODE_SEL(SEL)	((SEL<<24))
/**  Start conversion now */
#define ADC_CR_START_NOW	((1UL<<24))
/**  Start conversion when the edge selected by bit 27 occurs on P2.10/EINT0 */
#define ADC_CR_START_EINT0	((2UL<<24))
/** Start conversion when the edge selected by bit 27 occurs on P1.27/CAP0.1 */
#define ADC_CR_START_CAP01	((3UL<<24))
/**  Start conversion when the edge selected by bit 27 occurs on MAT0.1 */
#define ADC_CR_START_MAT01	((4UL<<24))
/**  Start conversion when the edge selected by bit 27 occurs on MAT0.3 */
#define ADC_CR_START_MAT03	((5UL<<24))
/**  Start conversion when the edge selected by bit 27 occurs on MAT1.0 */
#define ADC_CR_START_MAT10	((6UL<<24))
/**  Start conversion when the edge selected by bit 27 occurs on MAT1.1 */
#define ADC_CR_START_MAT11	((7UL<<24))
/**  Start conversion on a falling edge on the selected CAP/MAT signal */
#define ADC_CR_EDGE			((1UL<<27))

/*********************************************************************//**
 * Macro defines for ADC Global Data register
 **********************************************************************/
/** When DONE is 1, this field contains result value of ADC conversion */
#define ADC_GDR_RESULT(n)		(((n>>4)&0xFFF))
/** These bits contain the channel from which the LS bits were converted */
#define ADC_GDR_CH(n)			(((n>>24)&0x7))
/** This bit is 1 in burst mode if the results of one or
 * more conversions was (were) lost */
#define ADC_GDR_OVERRUN_FLAG	((1UL<<30))
/** This bit is set to 1 when an A/D conversion completes */
#define ADC_GDR_DONE_FLAG		((1UL<<31))

/** This bits is used to mask for Channel */
#define ADC_GDR_CH_MASK		((7UL<<24))
/*********************************************************************//**
 * Macro defines for ADC Interrupt register
 **********************************************************************/
/** These bits allow control over which A/D channels generate
 * interrupts for conversion completion */
#define ADC_INTEN_CH(n)			((1UL<<n))
/** When 1, enables the global DONE flag in ADDR to generate an interrupt */
#define ADC_INTEN_GLOBAL		((1UL<<8))

/*********************************************************************//**
 * Macro defines for ADC Data register
 **********************************************************************/
/** When DONE is 1, this field contains result value of ADC conversion */
#define ADC_DR_RESULT(n)		(((n>>4)&0xFFF))
/** These bits mirror the OVERRRUN status flags that appear in the
 * result register for each A/D channel */
#define ADC_DR_OVERRUN_FLAG		((1UL<<30))
/** This bit is set to 1 when an A/D conversion completes. It is cleared
 * when this register is read */
#define ADC_DR_DONE_FLAG		((1UL<<31))

/*********************************************************************//**
 * Macro defines for ADC Status register
**********************************************************************/
/** These bits mirror the DONE status flags that appear in the result
 * register for each A/D channel */
#define ADC_STAT_CH_DONE_FLAG(n)		((n&0xFF))
/** These bits mirror the OVERRRUN status flags that appear in the
 * result register for each A/D channel */
#define ADC_STAT_CH_OVERRUN_FLAG(n)		(((n>>8)&0xFF))
/** This bit is the A/D interrupt flag */
#define ADC_STAT_INT_FLAG				((1UL<<16))

/*********************************************************************//**
 * Macro defines for ADC Trim register
**********************************************************************/
/** Offset trim bits for ADC operation */
#define ADC_ADCOFFS(n)		(((n&0xF)<<4))
/** Written to boot code*/
#define ADC_TRIM(n)		    (((n&0xF)<<8))

/* ------------------- CHECK PARAM DEFINITIONS ------------------------- */
/** Check ADC parameter */
#define PARAM_ADCx(n)    (((CPU_INT32U *)n)==((CPU_INT32U *)LPC_ADC))

/** Check ADC state parameter */
#define PARAM_ADC_START_ON_EDGE_OPT(OPT)    ((OPT == ADC_START_ON_RISING)||(OPT == ADC_START_ON_FALLING))

/** Check ADC state parameter */
#define PARAM_ADC_DATA_STATUS(OPT)    ((OPT== ADC_DATA_BURST)||(OPT== ADC_DATA_DONE))

/** Check ADC rate parameter */
#define PARAM_ADC_RATE(rate)	((rate>0)&&(rate<=200000))

/** Check ADC channel selection parameter */
#define PARAM_ADC_CHANNEL_SELECTION(SEL)	((SEL == ADC_CHANNEL_0)||(ADC_CHANNEL_1)\
||(SEL == ADC_CHANNEL_2)|(ADC_CHANNEL_3)\
||(SEL == ADC_CHANNEL_4)||(ADC_CHANNEL_5)\
||(SEL == ADC_CHANNEL_6)||(ADC_CHANNEL_7))

/** Check ADC start option parameter */
#define PARAM_ADC_START_OPT(OPT)    ((OPT == ADC_START_CONTINUOUS)||(OPT == ADC_START_NOW)\
||(OPT == ADC_START_ON_EINT0)||(OPT == ADC_START_ON_CAP01)\
||(OPT == ADC_START_ON_MAT01)||(OPT == ADC_START_ON_MAT03)\
||(OPT == ADC_START_ON_MAT10)||(OPT == ADC_START_ON_MAT11))

/** Check ADC interrupt type parameter */
#define PARAM_ADC_TYPE_INT_OPT(OPT)    ((OPT == ADC_ADINTEN0)||(OPT == ADC_ADINTEN1)\
||(OPT == ADC_ADINTEN2)||(OPT == ADC_ADINTEN3)\
||(OPT == ADC_ADINTEN4)||(OPT == ADC_ADINTEN5)\
||(OPT == ADC_ADINTEN6)||(OPT == ADC_ADINTEN7)\
||(OPT == ADC_ADGINTEN))

/**
 * @}
 */


/* Public Types --------------------------------------------------------------- */
/*********************************************************************//**
 * @brief ADC enumeration
 **********************************************************************/
/** @brief Channel Selection */
//typedef enum
//{
//	ADC_CHANNEL_0  = 0x01,      /*!<  Channel 0 */
//	ADC_CHANNEL_1  = 0x02,		/*!<  Channel 1 */
//	ADC_CHANNEL_2  = 0x04,		/*!<  Channel 2 */
//	ADC_CHANNEL_3  = 0x08,		/*!<  Channel 3 */
//	ADC_CHANNEL_4  = 0x10,		/*!<  Channel 4 */
//	ADC_CHANNEL_5  = 0x20,		/*!<  Channel 5 */
//	ADC_CHANNEL_6  = 0x40,		/*!<  Channel 6 */
//	ADC_CHANNEL_7  = 0x80		/*!<  Channel 7 */
//}ADC_CHANNEL_SELECTION;


/** @brief Channel Selection */
typedef enum
{
	ADC_CHANNEL_0  = 0, /*!<  Channel 0 */
	ADC_CHANNEL_1,		/*!<  Channel 1 */
	ADC_CHANNEL_2,		/*!<  Channel 2 */
	ADC_CHANNEL_3,		/*!<  Channel 3 */
	ADC_CHANNEL_4,		/*!<  Channel 4 */
	ADC_CHANNEL_5,		/*!<  Channel 5 */
	ADC_CHANNEL_6,		/*!<  Channel 6 */
	ADC_CHANNEL_7		/*!<  Channel 7 */
}ADC_CHANNEL_SELECTION;

/** @brief Type of start option */
typedef enum
{
	ADC_START_CONTINUOUS =0,	/*!< Continuous mode */
	ADC_START_NOW,				/*!< Start conversion now */
	ADC_START_ON_EINT0,			/*!< Start conversion when the edge selected
								 * by bit 27 occurs on P2.10/EINT0 */
	ADC_START_ON_CAP01,			/*!< Start conversion when the edge selected
								 * by bit 27 occurs on P1.27/CAP0.1 */
	ADC_START_ON_MAT01,			/*!< Start conversion when the edge selected
								 * by bit 27 occurs on MAT0.1 */
	ADC_START_ON_MAT03,			/*!< Start conversion when the edge selected
								 * by bit 27 occurs on MAT0.3 */
	ADC_START_ON_MAT10,			/*!< Start conversion when the edge selected
								  * by bit 27 occurs on MAT1.0 */
	ADC_START_ON_MAT11			/*!< Start conversion when the edge selected
								  * by bit 27 occurs on MAT1.1 */
} ADC_START_OPT;


/** @brief Type of edge when start conversion on the selected CAP/MAT signal */
typedef enum
{
	ADC_START_ON_RISING = 0,	/*!< Start conversion on a rising edge
								*on the selected CAP/MAT signal */
	ADC_START_ON_FALLING		/*!< Start conversion on a falling edge
								*on the selected CAP/MAT signal */
} ADC_START_ON_EDGE_OPT;

/** @brief* ADC type interrupt enum */
typedef enum
{
    ADC_ADINTDIS = 0,
	ADC_ADINTEN0 = 0x01,		/*!< Interrupt channel 0 */
	ADC_ADINTEN1 = 0x02,		/*!< Interrupt channel 1 */
	ADC_ADINTEN2 = 0x04,		/*!< Interrupt channel 2 */
	ADC_ADINTEN3 = 0x08,		/*!< Interrupt channel 3 */
	ADC_ADINTEN4 = 0x10,		/*!< Interrupt channel 4 */
	ADC_ADINTEN5 = 0x20,		/*!< Interrupt channel 5 */
	ADC_ADINTEN6 = 0x40,		/*!< Interrupt channel 6 */
	ADC_ADINTEN7 = 0x80,		/*!< Interrupt channel 7 */
	ADC_ADGINTEN = 0x0100,		/*!< Individual channel/global flag done generate an interrupt */
}ADC_TYPE_INT_OPT;

/** @brief ADC Data  status */
typedef enum
{
	ADC_DATA_BURST = 0,	    /*Burst bit*/
	ADC_DATA_DONE		    /*Done bit*/
}ADC_DATA_STATUS;

typedef struct
{
    CPU_INT32U gpio_pins;            
	CPU_INT16U gpio_opt;
	CPU_INT08U gpio_port;
	CPU_INT08U rvsd;
}ADC_PIN_CFG_Type;

typedef struct{
    CPU_INT32U            adc_rate;
	ADC_START_ON_EDGE_OPT adc_start_edge;
	ADC_TYPE_INT_OPT	  adc_int_opt;
	CPU_INT32U            adc_ch_sel;
	FunctionalState       adc_burst_en;
	FunctionalState       adc_pwd_en;
}ADC_CFG_Type;

/* Public Functions ----------------------------------------------------------- */
/* ADC0 init and get data */
void ADC0_Init(void);
CPU_INT16U ADC0_GetData(CPU_INT32U channel);
//CPU_INT32S ADC0_GetData(CPU_INT32U channel,CPU_INT16U *pvl);

/* Init/DeInit ADC peripheral ----------------*/
void ADC_Init(LPC_ADC_TypeDef *ADCx, uint32_t rate);
void ADC_DeInit(LPC_ADC_TypeDef *ADCx);

/* Enable/Disable ADC functions --------------*/
void ADC_BurstCmd(LPC_ADC_TypeDef *ADCx, FunctionalState NewState);
void ADC_PowerdownCmd(LPC_ADC_TypeDef *ADCx, FunctionalState NewState);
void ADC_StartCmd(LPC_ADC_TypeDef *ADCx, CPU_INT08U start_mode);
void ADC_ChannelCmd (LPC_ADC_TypeDef *ADCx, CPU_INT08U Channel, FunctionalState NewState);

/* Configure ADC functions -------------------*/
void ADC_EdgeStartConfig(LPC_ADC_TypeDef *ADCx, CPU_INT08U EdgeOption);
void ADC_IntConfig (LPC_ADC_TypeDef *ADCx, ADC_TYPE_INT_OPT IntType, FunctionalState NewState);

/* Get ADC information functions -------------------*/
CPU_INT16U ADC_ChannelGetData(LPC_ADC_TypeDef *ADCx, CPU_INT08U channel);
FlagStatus ADC_ChannelGetStatus(LPC_ADC_TypeDef *ADCx, CPU_INT08U channel, CPU_INT32U StatusType);
CPU_INT32U ADC_GlobalGetData(LPC_ADC_TypeDef *ADCx);
FlagStatus ADC_GlobalGetStatus(LPC_ADC_TypeDef *ADCx, CPU_INT32U StatusType);



unsigned int press0_sensor_get(void);
unsigned int press1_sensor_get(void);

unsigned int temperature0_sensor_get(void);
unsigned int temperature1_sensor_get(void);
unsigned int water_level_get(void);
void sensor_adc_init(void);
#ifdef __cplusplus
}
#endif

/*******************  (C) COPYRIGHT 2011 DJI ************END OF FILE***********/
#endif 

