
#ifndef _LCD_H_
#define _LCD_H_

#include "stm32f4xx_hal.h"


/***************************************************************
 *
 * CONFIGURATION
 *
 ***************************************************************/

#define RM_LCD_CONF_BUS							RM_LCD_FUNC_BUS_4BIT
#define RM_LCD_CONF_LINES						RM_LCD_FUNC_LINES_2
#define RM_LCD_CONF_FONT						RM_LCD_FUNC_FONT_5x8

#define RM_LCD_DISP_LENGTH					16
#define RM_LCD_DISP_ROWS						2
#define RM_LCD_CONF_SCROLL_MS				20

/* RM_LCD Data lines - use the same port for all the lines */
#define RM_LCD_DATAPORT							GPIOB
#define RM_LCD_DATABIT4							GPIO_PIN_0
#define RM_LCD_DATABIT5							GPIO_PIN_1
#define RM_LCD_DATABIT6							GPIO_PIN_2
#define RM_LCD_DATABIT7							GPIO_PIN_3

/* RM_LCD Control lines - use the same port for all the lines */
#define RM_LCD_RS_PORT							GPIOB
#define RM_LCD_RS_BIT								GPIO_PIN_4


#define RM_LCD_RW_PORT							GPIOB
#define RM_LCD_RW_BIT								GPIO_PIN_5

#define RM_LCD_EN_PORT							GPIOB
#define RM_LCD_EN_BIT								GPIO_PIN_8

/* defines the peripheral clocks that need to be enabled for the above pins */
#define RM_LCD_RCC_AHBPeriph					RCC_AHBPeriph_GPIOB		//or something like "RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOD"





/***************************************************************
 *
 * CONSTANTS
 *
 ***************************************************************/

/* COMMANDS */
#define RM_LCD_CMD_RESET            	0x30     	/*!< Resets display - used in init 3x */
#define RM_LCD_CMD_CLEAR            	0x01     	/*!< Clears display */
#define RM_LCD_CMD_RETURN_HOME      	0x02     	/*!< Sets DDRAM pointer to 0 */
#define RM_LCD_CMD_ENTRY_MODE       	0x04     	/*!< Sets how the pointer is updated after a character write */
#define RM_LCD_CMD_DISPLAY          	0x08     	/*!< Display settings */
#define RM_LCD_CMD_SHIFT            	0x10     	/*!< Cursor and display movement */
#define RM_LCD_CMD_FUNCTION         	0x20     	/*!< Screen type setup */
#define RM_LCD_CMD_CGRAM_ADDR       	0x40     	/*!< Sets CGRAM address */
#define RM_LCD_CMD_DDRAM_ADDR       	0x80     	/*!< Sets DDRAM address */

/* ENTRY_MODE Command parameters */
#define RM_LCD_ENTRY_SHIFT_DISP 			0x01	 		/*!< Shift display */
#define RM_LCD_ENTRY_SHIFT_CURS 			0x00	 		/*!< Shift cursor */
#define RM_LCD_ENTRY_ADDR_INC   			0x02     	/*!< Increments pointer */
#define RM_LCD_ENTRY_ADDR_DEC   			0x00	 		/*!< Decrements pointer */

/* DISPLAY Command parameters */
#define RM_LCD_DISP_ON       				0x04      /*!< Enables the display */
#define RM_LCD_DISP_OFF      				0x00      /*!< Disables the display */
#define RM_LCD_DISP_CURS_ON  				0x02      /*!< Enables cursor */
#define RM_LCD_DISP_CURS_OFF 				0x00      /*!< Disables cursor */
#define RM_LCD_DISP_BLINK_ON					0x01      /*!< Enables cursor blinking */
#define RM_LCD_DISP_BLINK_OFF  			0x00      /*!< Disables cursor blinking */

/* SHIFT Command parameters */
#define RM_LCD_SHIFT_DISPLAY    			0x08      /*!< Shifts the display or shifts the cursor if not set */
#define RM_LCD_SHIFT_CURSOR    			0x00      /*!< Shifts the display or shifts the cursor if not set */
#define RM_LCD_SHIFT_RIGHT      			0x04      /*!< Shift to the right */
#define RM_LCD_SHIFT_LEFT      			0x00      /*!< Shift to the left  */

/* FUNCTION Command parameters */
#define RM_LCD_FUNC_BUS_8BIT  				0x10      /*!< 8 bit bus */
#define RM_LCD_FUNC_BUS_4BIT  				0x00      /*!< 4 bit bus */
#define RM_LCD_FUNC_LINES_4   				(0x08+0x54)      /*!< 4 lines */
#define RM_LCD_FUNC_LINES_3   				(0x08+0x14)      /*!< 3 lines */
#define RM_LCD_FUNC_LINES_2   				0x08      /*!< 2 lines */
#define RM_LCD_FUNC_LINES_1   				0x00      /*!< 1 line */
#define RM_LCD_FUNC_FONT_5x10 				0x04      /*!< 5x10 font */
#define RM_LCD_FUNC_FONT_5x8  				0x00      /*!< 5x8 font */

/* Busy Flag - actually not used */
#define RM_LCD_BUSY_FLAG        			0x80      /*!< Busy flag */



/***************************************************************
 *
 * FUNCTIONS
 *
 ***************************************************************/

#define RM_LCD_GPIO_Pin_RS 			RM_LCD_RS_BIT
#define RM_LCD_GPIO_Pin_RW			RM_LCD_RW_BIT 
#define RM_LCD_GPIO_Pin_EN			RM_LCD_EN_BIT

#define RM_LCD_RS_ON()		          HAL_GPIO_WritePin(RM_LCD_RS_PORT, RM_LCD_RS_BIT, GPIO_PIN_SET) 
#define RM_LCD_RS_OFF()	           	HAL_GPIO_WritePin(RM_LCD_RS_PORT, RM_LCD_RS_BIT, GPIO_PIN_RESET)
#define RM_LCD_RW_On()		          HAL_GPIO_WritePin(RM_LCD_RW_PORT, RM_LCD_RW_BIT, GPIO_PIN_SET)
#define RM_LCD_RW_Off()	            HAL_GPIO_WritePin(RM_LCD_RW_PORT, RM_LCD_RW_BIT, GPIO_PIN_RESET)
#define RM_LCD_EN_On()		          HAL_GPIO_WritePin(RM_LCD_EN_PORT, RM_LCD_EN_BIT, GPIO_PIN_SET)
#define RM_LCD_EN_Off()	            HAL_GPIO_WritePin(RM_LCD_EN_PORT, RM_LCD_EN_BIT, GPIO_PIN_RESET)

#define RM_LCD_EN_high_delay()     	HAL_Delay(1);		//1ms
#define RM_LCD_init_delay()        	HAL_Delay(16);	//16ms
#define RM_LCD_init_delay2()       	HAL_Delay(5);		//5ms
#define RM_LCD_init_delay3()       	HAL_Delay(1);		//1ms
#define RM_LCD_init_end_delay()    	HAL_Delay(2);		//2ms

#define RM_LCD_clear()                       	  RM_LCD_Write_CMD( RM_LCD_CMD_CLEAR )
#define RM_LCD_home()                        	  RM_LCD_Write_CMD( RM_LCD_CMD_RETURN_HOME )
#define RM_LCD_entry( inc_dec, shift )          RM_LCD_Write_CMD( ( RM_LCD_CMD_ENTRY_MODE | inc_dec | shift ) & 0x07 )
#define RM_LCD_display( on_off, cursor, blink ) RM_LCD_Write_CMD( ( RM_LCD_CMD_DISPLAY | on_off | cursor | blink ) & 0x0F )
#define RM_LCD_shift( inc_dec, shift )          RM_LCD_Write_CMD( ( RM_LCD_CMD_SHIFT | inc_dec | shift ) & 0x1F )
#define RM_LCD_function( bus, lines, font )     RM_LCD_Write_CMD( ( RM_LCD_CMD_FUNCTION | bus | lines | font ) & 0x3F )
#define RM_LCD_cgram_addr( addr )               RM_LCD_Write_CMD( RM_LCD_CMD_CGRAM_ADDR | ( addr & 0x3F ) )
#define RM_LCD_ddram_addr( addr )               RM_LCD_Write_CMD( RM_LCD_CMD_DDRAM_ADDR | ( addr & 0x7F ) )
#define RM_LCD_write_char( c )                  RM_LCD_Write_DATA( c & 0xff )


void RM_LCD_Write_High_Nibble(unsigned char data);
void RM_LCD_Write_Low_Nibble(unsigned char data);
void RM_LCD_Write_Info(unsigned char Info);
void RM_LCD_Write_CMD(unsigned char CMD);
void RM_LCD_Write_DATA(unsigned char DATA);

void RM_LCD_Init(void);
void RM_LCD_Put_Char(unsigned char c);
void RM_LCD_Goto(unsigned char x, unsigned char y);
void RM_LCD_PutStr(char *str);
void RM_LCD_Clear(void);
void RM_LCD_Write_Str(unsigned char x, unsigned char y, char *Ptr);



#endif



