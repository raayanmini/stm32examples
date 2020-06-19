#include "main.h"
#include <stdio.h>
#include "Lcd.h"

/************************************/
unsigned char *Fetch ;
unsigned int temp=20,hum=40;
volatile unsigned char Rx_Buff[200];
volatile unsigned char Rx_Buff_Time[200];
volatile unsigned int  Rx_Count;
extern volatile int Count;
extern 	int Rx_Flag;
int Loop_break_count;
int Time_Flag;
int temp1;
/************************************/

extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc1;

/************************************/
void AT_Cmd(void);
void At_Reset_Cmd(void);
void At_SetWifi_Mode(void);
void At_Connet_To_Wifi(void);
void At_Mux_Mode(void);
void At_Ap_Mode_Selection(void);

/*************;***********************
Stage 1: Check AT command status
************************************/
void AT_Cmd(void){
	
    HAL_UART_Transmit(&huart1, (uint8_t *)"AT\r\n",5,1000);
 		HAL_Delay(300);
	
 while(!Rx_Flag){
		HAL_UART_Transmit(&huart1, (uint8_t *)"AT\r\n",5,1000);
 		HAL_Delay(300);
	  RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"1");
	  RM_LCD_Write_Str(1,1,"*");
}
		RM_LCD_Clear();
   	RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"1");
	  RM_LCD_Write_Str(1,1,"*");
		Rx_Flag=0;
		At_Reset_Cmd();
}

/*************;***********************
Rest ESP8266 module
************************************/
void At_Reset_Cmd(void){
	
      HAL_UART_Transmit(&huart1,(uint8_t *)"AT+RST\r\n",9,1000); 
	 		HAL_Delay(300);	
	    At_SetWifi_Mode();
	
}

/*************;***********************
Stage 2: Set AP Mode
************************************/
void At_SetWifi_Mode(void){
			
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CWMODE=3\r\n",14,1000);
		HAL_Delay(300); 		HAL_Delay(300);
	while(!Rx_Flag){
   
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CWMODE=3\r\n",14,1000);
 		HAL_Delay(300);
		RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"2");
	  RM_LCD_Write_Str(1,1,"**");

}
		RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"2");
	  RM_LCD_Write_Str(1,1,"**");
		Rx_Flag=0;
		At_Connet_To_Wifi();
}

/*************;***********************
Stage 3: Connect Wi-Fi Access Point
************************************/
void At_Connet_To_Wifi(void){

		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CWJAP=\"MiA3\",\"12345678\"\r\n",45,1000);
		HAL_Delay(300); 		HAL_Delay(300);

 while(!Rx_Flag){
 		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CWJAP=\"MiA3\",\"12345678\"\r\n",45,1000);
 		HAL_Delay(300);
	 	RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"3");
	  RM_LCD_Write_Str(1,1,"***");
}
		Rx_Flag=0;
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIFSR\r\n",11,1000);
		HAL_Delay(300); 		HAL_Delay(300);
		while(!Rx_Flag){
    HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIFSR\r\n",11,1000);
 		HAL_Delay(300);
 }
		RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"4");
	  RM_LCD_Write_Str(1,1,"****");
		Rx_Flag=0;
		At_Mux_Mode();

}

/************************************
Stage 4: Enable CIPMux
************************************/
void At_Mux_Mode(void){

		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPMUX=0\r\n",14,1000);
		HAL_Delay(300); 		HAL_Delay(300);
		while(!Rx_Flag){  
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPMUX=0\r\n",14,1000);
 		HAL_Delay(300);
		RM_LCD_Clear();
    RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"4");
	  RM_LCD_Write_Str(1,1,"****");
 }
		RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"4");
	  RM_LCD_Write_Str(1,1,"****");
		Rx_Flag=0;
		At_Ap_Mode_Selection();
}


/************************************
Stage 5: Enable CIPMODE
************************************/
void At_Ap_Mode_Selection(void){
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CWLAP\r\n",11,1000);
		HAL_Delay(300); 		HAL_Delay(300);
		while(!Rx_Flag){
    HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CWLAP\r\n",11,1000);
 		HAL_Delay(300);
 }	
		Rx_Flag=0;
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPMODE=0\r\n",15,1000);
		HAL_Delay(300); 		HAL_Delay(300);
 	  
		while(!Rx_Flag){
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPMODE=0\r\n",15,1000);
		HAL_Delay(300);
		RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"5");
	  RM_LCD_Write_Str(1,1,"*****");
 }
		Rx_Flag=0;
		RM_LCD_Clear();
		RM_LCD_Write_Str(3,0,"INITIALIZTION");
    RM_LCD_Write_Str(13,1,"5");
	  RM_LCD_Write_Str(1,1,"*****");
}
/************************************
Wi-Fi initalaization to 5 stages.
Stage 1: Check AT command status
Stage 2: Set AP Mode
Stage 3: Connect Wi-Fi Access Point
Stage 4: Enable CIPMux
Stage 5: Enable CIPMODE
************************************/
void Wifi_Init(void){ 
	Rx_Count=0;
	Rx_Flag=0;

    Loop_break_count=0;
   __HAL_UART_ENABLE_IT(&huart1,UART_IT_RXNE); 
    AT_Cmd();
}
 
/************************************
update time to LCD
************************************/
 void Rx_Time(void){
	 	RM_LCD_Write_CMD(0x80);	 
		RM_LCD_Write_DATA(Rx_Buff_Time[3]);
    RM_LCD_Write_DATA(Rx_Buff_Time[4]);
		RM_LCD_Write_DATA(Rx_Buff_Time[5]);
    RM_LCD_Write_DATA(Rx_Buff_Time[6]);
		RM_LCD_Write_DATA(Rx_Buff_Time[7]);
	  RM_LCD_Write_DATA(Rx_Buff_Time[8]);
		RM_LCD_Write_DATA(Rx_Buff_Time[9]);
	  
}
/**************************************************** 
 Receive date & time from Internet and updated to LCD 
*****************************************************/
 void Wifi_Rx_Time(void){
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSTATUS\r\n",15,1000);
		HAL_Delay(1000); HAL_Delay(1000);HAL_Delay(1000);
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n",43,1000);
		HAL_Delay(1000);HAL_Delay(1000);
		while(!Rx_Flag)
			{
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n",43,1000);
		HAL_Delay(1000);HAL_Delay(1000);	 
		}
		Rx_Flag=0;	 
		HAL_Delay(1000);
		HAL_Delay(1000);
		Time_Flag=1;	 	 	 
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSEND=83\r\n",16,1000);
		HAL_Delay(300);
		Rx_Flag=0;
		HAL_UART_Transmit(&huart1,(uint8_t *)"GET /apps/thinghttp/send_request?api_key=FYK7MM0RIXBFL0H7\r\n",60,1000);
		HAL_Delay(1000); 	
		Time_Flag=0;	
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPCLOSE\r\n",15,1000);
		Rx_Time();
		HAL_Delay(1000); 		HAL_Delay(1000); 		HAL_Delay(1000);
 }
/**********************************************
Transmit LM35 temperature value to cloud server
***********************************************/
 void Wifi_Tx(void){
		char Fetch[55]; 
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSTATUS\r\n",15,1000);
		HAL_Delay(1000); HAL_Delay(1000);HAL_Delay(1000);
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n",43,1000); 	
		HAL_Delay(1000);HAL_Delay(1000);
		while(!Rx_Flag)
			{
					HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSTART=\"TCP\",\"142.93.218.33\",80\r\n",43,1000);
					HAL_Delay(1000);		
		 }
		Rx_Flag=0;	 	 
		HAL_Delay(1000);
		HAL_Delay(1000);
		Time_Flag=1;	 	 	 
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPSEND=48\r\n",16,1000);
		HAL_Delay(300);
		Rx_Flag=0;
		sprintf(Fetch,"GET /page.php?temp=%d&hum=99&dev=17\r\n\r\n",temp1);// temperature value send to cloud server.
		HAL_UART_Transmit(&huart1,(uint8_t *)Fetch,49,1000);
		HAL_Delay(1000); 	
		Time_Flag=0;
		HAL_UART_Transmit(&huart1,(uint8_t *)"AT+CIPCLOSE\r\n",15,1000);
		HAL_Delay(1000);
 
 } 
 
/************************************/
void 	Usart_Recv_Task( unsigned char Temp){
		
		Rx_Buff[Rx_Count++]=Temp;
		if(Rx_Count>199)
		Rx_Count=0; 
		
}
/************************************/

void Usart_Recv_Timecheck(void){
	int i;
	for(i=0;i<200;i++){
	if((Rx_Buff[i]=='+')&&(Rx_Buff[i+1]=='I')&&(Rx_Buff[i+2]=='P')&&(Rx_Buff[i+3]=='D')){
	i=i+3;
		}	
	}
}
		char Temp_Value[20];



/* Read LM35 data and store in to temp1 global variable */
void Read_LM35(void){
		HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,10);
		temp1=HAL_ADC_GetValue(&hadc1);
		temp1=(temp1/12);
		sprintf(Temp_Value, "%d", temp1);
	  RM_LCD_Clear();
		RM_LCD_Goto(2,1);
		RM_LCD_PutStr("TEMP: ");
		RM_LCD_PutStr(Temp_Value);
		RM_LCD_Put_Char(0xDF);
		RM_LCD_Put_Char('C');
		HAL_Delay(300);
		HAL_Delay(1000);

}
