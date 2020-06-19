

#include "stm32f4xx_hal.h"
#include "Lcd.h"

#include <stdio.h>
#include <math.h>


/* Function used from the CooCox RM_LCD library */

/*************7*******************************************************************************/
void RM_LCD_Write_High_Nibble( unsigned char data )
{
	if ( data & 0x10 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT4,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT4 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT4,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT4 );
	}
	if ( data & 0x20 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT5,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT5 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT5,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT5 );
	}
	if ( data & 0x40 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT6,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT6 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT6,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT6 );
	}
	if ( data & 0x80 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT7,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT7 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT7,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT7 );
	}

    /* set the EN signal */
    RM_LCD_EN_On();

    /* wait */
    RM_LCD_EN_high_delay();

    /* reset the EN signal */
    RM_LCD_EN_Off();
}


#if RM_LCD_CONF_BUS == RM_LCD_FUNC_BUS_4BIT

void RM_LCD_Write_Low_Nibble( unsigned char data )
{
	if ( data & 0x01 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT4,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT4 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT4,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT4 );
	}
	if ( data & 0x02 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT5,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT5 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT5,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT5 );
	}
	if ( data & 0x04 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT6,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT6 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT6,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT6 );
	}
	if ( data & 0x08 ) {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT7,GPIO_PIN_SET);	//GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT7 );
	} else {
		HAL_GPIO_WritePin(RM_LCD_DATAPORT,RM_LCD_DATABIT7,GPIO_PIN_RESET);	//GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT7 );
	}

    /* set the EN signal */
    RM_LCD_EN_On();

    /* wait */
    RM_LCD_EN_high_delay();

    /* reset the EN signal */
    RM_LCD_EN_Off();
}

/* 4bit bus version */
void RM_LCD_Write_Info( unsigned char Info )
{
	/* send the data bits - high nibble first */
	RM_LCD_Write_High_Nibble( Info );
	RM_LCD_Write_Low_Nibble( Info );
}
#endif /* RM_LCD_CONF_BUS == RM_LCD_FUNC_BUS_4BIT */







#if RM_LCD_CONF_BUS == RM_LCD_FUNC_BUS_8BIT

/* 8bit bus version */
void RM_LCD_Write_Info( unsigned char Info )
{
	/* set the data bits */
	if ( data & 0x01 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT0 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT0 );
	}
	if ( data & 0x02 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT1 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT1 );
	}
	if ( data & 0x04 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT2 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT2 );
	}
	if ( data & 0x08 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT3 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT3 );
	}
	if ( data & 0x10 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT4 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT4 );
	}
	if ( data & 0x20 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT5 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT5 );
	}
	if ( data & 0x40 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT6 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT6 );
	}
	if ( data & 0x80 ) {
		GPIO_SetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT7 );
	} else {
		GPIO_ResetBits( RM_LCD_DATAPORT, RM_LCD_DATABIT7 );
	}

    /* tell the lcd that we have a command to read in */
    RM_LCD_EN_On();

    /* wait long enough so that the lcd can see the command */
    RM_LCD_EN_high_delay();

    /* reset the ce line */
    RM_LCD_EN_Off();
    RM_LCD_init_end_delay();

}
#endif /* RM_LCD_CONF_BUS == RM_LCD_FUNC_BUS_8BIT */


/********************************************************************************************/
void RM_LCD_Write_CMD( unsigned char CMD )
{
	RM_LCD_RS_OFF();
	RM_LCD_Write_Info( CMD );
}
/********************************************************************************************/



/********************************************************************************************/
void RM_LCD_Write_DATA( unsigned char DATA )
{
	RM_LCD_RS_ON();
	RM_LCD_Write_Info( DATA );
}
/********************************************************************************************/






/********************************************************************************************/
void RM_LCD_Init(void){
GPIO_InitTypeDef GPIO_InitStructure;	

GPIO_InitStructure.Pin = RM_LCD_DATABIT7 | RM_LCD_DATABIT6 | RM_LCD_DATABIT5 | RM_LCD_DATABIT4;
GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;									
GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
HAL_GPIO_Init(RM_LCD_DATAPORT, &GPIO_InitStructure);

GPIO_InitStructure.Pin = RM_LCD_RW_BIT  ;
GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;									
GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
HAL_GPIO_Init(RM_LCD_RW_PORT, &GPIO_InitStructure);
	
GPIO_InitStructure.Pin = RM_LCD_EN_BIT  ;
GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;									
GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
HAL_GPIO_Init(RM_LCD_EN_PORT, &GPIO_InitStructure);

	
	GPIO_InitStructure.Pin = RM_LCD_RS_BIT  ;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;									
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(RM_LCD_RS_PORT, &GPIO_InitStructure);

  /* clear control bits */
	RM_LCD_EN_Off();
	RM_LCD_RS_OFF();
	RM_LCD_RW_Off();
	
	/* wait initial delay for LCD to settle */
  /* reset procedure - 3 function calls resets the device */
  RM_LCD_init_delay();
  RM_LCD_Write_High_Nibble( RM_LCD_CMD_RESET );
  RM_LCD_init_delay2();
  RM_LCD_Write_High_Nibble( RM_LCD_CMD_RESET );
  RM_LCD_init_delay3();
  RM_LCD_Write_High_Nibble( RM_LCD_CMD_RESET );
		
	#if RM_LCD_CONF_BUS == RM_LCD_FUNC_BUS_4BIT
    /* 4bit interface */
  RM_LCD_Write_High_Nibble( RM_LCD_CMD_FUNCTION );
  #endif /* RM_LCD_CONF_BUS == RM_LCD_FUNC_BUS_4BIT */

  /* sets the configured values - can be set again only after reset */
  RM_LCD_function( RM_LCD_CONF_BUS, RM_LCD_CONF_LINES, RM_LCD_CONF_FONT );

  /* turn the display on with no cursor or blinking */
	RM_LCD_display( RM_LCD_DISP_ON, RM_LCD_DISP_CURS_OFF, RM_LCD_DISP_BLINK_OFF );
	
  /* clear the display */
  RM_LCD_clear();

  /* addr increment, shift cursor */
	RM_LCD_entry( RM_LCD_ENTRY_ADDR_INC, RM_LCD_ENTRY_SHIFT_CURS );
	
	

}



/**********************************/
void RM_LCD_Put_Char(unsigned char c)
{
	RM_LCD_Write_DATA(c & 0xff);
}
/**********************************/


/**********************************/
void RM_LCD_Goto(unsigned char x, unsigned char y)
{
  unsigned char copy_y=0;
	
  if(x > (RM_LCD_DISP_LENGTH-1))
		x = 0;

	if(y > (RM_LCD_DISP_ROWS-1))
		y = 0;

	switch(y)
  {
		case 0:  copy_y = 0x80; break;
		case 1:  copy_y = 0xc0; break;
		case 2:  copy_y = 0x94; break;
		case 3:  copy_y = 0xd4; break;
  }
	RM_LCD_Write_CMD(x + copy_y);
}
/**********************************/





/**********************************/
void RM_LCD_PutStr(char *str)
{
	__IO unsigned int i=0;

	do
	{
		if(*str == '%')
			{
				str++;
				int8_t cc=*str-'0';
				if(cc>=0 && cc<=7)
					{
						RM_LCD_Put_Char(cc);
					}
				else
					{
						RM_LCD_Put_Char('%');
						RM_LCD_Put_Char(*str);
					}
			}
		RM_LCD_Put_Char(str[i]);
		i++;
	}while(str[i]!='\0');
}
/**********************************/



/**********************************/
void RM_LCD_Clear(void){
	RM_LCD_Write_CMD(RM_LCD_CMD_CLEAR);
}
/**********************************/


/**********************************/
void RM_LCD_Write_Str(unsigned char x, unsigned char y, char *Ptr){
RM_LCD_Goto(x,y);	
RM_LCD_PutStr(Ptr);
}
/**********************************/


