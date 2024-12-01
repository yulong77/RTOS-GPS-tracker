/**
  ******************************************************************************************** 
  *@file   : STM32F407_I2C_LCD16x02_Driver.c
  *@author : Yulong
  *@brief  : LCD driver source file for interfacing 16x02 LCD on STM32Fxx MCU using I2C Serial 
	         Interface Module
  ********************************************************************************************
*/	

#include "stm32f4xx_hal.h"
#include "STM32F407_I2C_LCD16x02_Driver.h"

/* I2C Handle */
I2C_HandleTypeDef myI2Chandle;


/********************* Private function for I2C initialization *************************/

/* Configure GPIOs */
/*
static void GPIO_Config(void)
{
	//Enable Ports clocks
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	//Init tyoeDef
	GPIO_InitTypeDef myPinInit;

	//I2C pins config
	myPinInit.Pin = GPIO_PIN_6 |GPIO_PIN_7;
	myPinInit.Mode = GPIO_MODE_AF_OD;
	myPinInit.Pull = GPIO_PULLUP;
	myPinInit.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	myPinInit.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &myPinInit);

	//Systick interrupt enable for HAL_Delay function
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
	
}
*/


/*Configure I2C Peripheral */
static void I2C_Config(void)
{
	//Enable I2C peripheral clock
	__HAL_RCC_I2C1_CLK_ENABLE();
	
	myI2Chandle.Instance = I2C1;
	myI2Chandle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	myI2Chandle.Init.ClockSpeed = 100000;
	myI2Chandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
	myI2Chandle.Init.DutyCycle = I2C_DUTYCYCLE_2;
	myI2Chandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
	myI2Chandle.Init.NoStretchMode = I2C_NOSTRETCH_DISABLED;
	myI2Chandle.Init.OwnAddress1 = 0;
	myI2Chandle.Init.OwnAddress2 = 0;
	HAL_I2C_Init(&myI2Chandle);
}
/**********************************************************************************/


/********************************* LCD APIs ***************************************/
/**
 * @brief Send Command to LCD
 * @param cmd : LCD commands 
 * @retval None
 */
void LCD_Send_Cmd(uint8_t cmd)
{
	uint8_t data_u, data_l;
	uint8_t data_u_tx[2], data_l_tx[2];

	/*Store upper nibble*/
	data_u = (cmd & 0xF0);

	/*Store lower nibble*/
	data_l = ((cmd << 4) & 0xF0);

	/* Construct upper byte-> compatible for LCD*/
	data_u_tx[0] = data_u|BACKLIGHT|PIN_EN;
	data_u_tx[1] = data_u|BACKLIGHT;
	
	/* Construct lower byte-> compatible for LCD*/
	data_l_tx[0] = data_l|BACKLIGHT|PIN_EN;
	data_l_tx[1] = data_l|BACKLIGHT;

	/* Transmit upper nibble using I2C APIs*/
	if(HAL_I2C_IsDeviceReady(& myI2Chandle, I2C_SLAVE_ADDRESS, 1, 10) == HAL_OK)
		HAL_I2C_Master_Transmit(& myI2Chandle,I2C_SLAVE_ADDRESS, data_u_tx, 2, 100); 
	
	/*Provide a delay */
	HAL_Delay(5);

	/* Transmit lower nibble using I2C APIs*/
	if(HAL_I2C_IsDeviceReady(& myI2Chandle, I2C_SLAVE_ADDRESS, 1, 10) == HAL_OK)
		HAL_I2C_Master_Transmit(& myI2Chandle,I2C_SLAVE_ADDRESS, data_l_tx, 2, 100);	

	/*Provide a delay */
	HAL_Delay(5);
}



/**
 * @brief Send Data to LCD
 * @param data: Data to be sent to LCD
 * @retval None
 */
void LCD_Send_Data(uint8_t data)
{
	uint8_t data_u, data_l;
	uint8_t data_u_tx[2], data_l_tx[2];

	/*Store upper nibble*/
	data_u = (data & 0xF0);

	/*Store lower nibble*/
	data_l = ((data << 4) & 0xF0);

	/* Construct upper byte-> compatible for LCD*/
	data_u_tx[0] = data_u|BACKLIGHT|PIN_EN|PIN_RS;
	data_u_tx[1] = data_u|BACKLIGHT|PIN_RS;
	
	/* Construct lower byte-> compatible for LCD*/
	data_l_tx[0] = data_l|BACKLIGHT|PIN_EN|PIN_RS;
	data_l_tx[1] = data_l|BACKLIGHT|PIN_RS;

	/* Transmit upper nibble using I2C APIs*/
	if(HAL_I2C_IsDeviceReady(& myI2Chandle, I2C_SLAVE_ADDRESS, 1, 10) == HAL_OK)
		HAL_I2C_Master_Transmit(& myI2Chandle,I2C_SLAVE_ADDRESS, data_u_tx, 2, 100); 
	
	/*Provide a delay */
	//HAL_Delay(1);

	/* Transmit lower nibble using I2C APIs*/
	if(HAL_I2C_IsDeviceReady(& myI2Chandle, I2C_SLAVE_ADDRESS, 1, 10) == HAL_OK)
		HAL_I2C_Master_Transmit(& myI2Chandle,I2C_SLAVE_ADDRESS, data_l_tx, 2, 100);	
    
    /*Provide a delay */
    HAL_Delay(1);
}



/**
 * @brief  Initializes LCD
 * @retval None
 */
void LCD_Init(void)
{
	/* Configure GPIOs */
	//GPIO_Config();

	/*Configure I2C */
	I2C_Config();

	/* Wait for 15ms */
	HAL_Delay(50);
	
	/*Function Set - As per HD44780U*/
	LCD_Send_Cmd(LCD_FUNCTION_SET1);
	
	/*Function Set -As per HD44780U*/
	LCD_Send_Cmd(LCD_FUNCTION_SET2);
	
	/*Set 4bit mode and 2 lines */
	LCD_Send_Cmd(LCD_4BIT_2LINE_MODE);
	
	/*Display on, cursor off*/
	LCD_Send_Cmd(0x0C);
	
	/* SET Row1 and Col1 (1st Line) */
	LCD_Send_Cmd(0x80);
	
	/*Clear Display*/
	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	
	/* Wait for 5ms to ensure commands are processed */
	HAL_Delay(5);

}



/**
 * @brief Send Strings to LCD
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Send_String(char *str)
{
	while (*str)  
	{
		LCD_Send_Data(*str++);
	}
}



/**
 * @brief Clears screen first, then displays the given string
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Clear_Then_Display(char *str)
{
	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	LCD_Send_String(str);
}



/**
 * @brief Display the strings on Line1
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Send_String_On_Line1(char *str)
{
	LCD_Send_Cmd(LCD_SET_ROW1_COL1);
	LCD_Send_String(str);
}


/**
 * @brief Display the strings on Line2
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Send_String_On_Line2(char *str)
{
	LCD_Send_Cmd(LCD_SET_ROW2_COL1);
	LCD_Send_String(str);
}


/**
 * @brief Display long messages of any size on LCD
 * @param str: pointer to strings
 * @retval None
 */
void LCD_Display_Long_Message(char *string)
{
	int i =0, count =1, j=0;
	/*Clear display and Set position to Line1 start*/
	LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
	LCD_Send_Cmd(LCD_SET_ROW1_COL1);
	
	while(string[i] != '\0')
	{
		LCD_Send_Data(string[i]);
		
		/*If we reach 1st Line end, then goto 2nd line start*/
		if(j>=15 && (count%2 == 1))
		{
			count++;
			LCD_Send_Cmd(LCD_SET_ROW2_COL1);
		}
		
		/*If we reach second line end, clear display start from line1 again*/
		if(j>=31 && (count%2 == 0))
		{
			count++;
			j=0;
			LCD_Send_Cmd(LCD_CLEAR_DISPLAY);
			LCD_Send_Cmd(LCD_SET_ROW1_COL1);
		}
		
		HAL_Delay(100);
		i++;
		j++;
	}
}


