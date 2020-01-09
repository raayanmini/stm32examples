/*******************************************/
Please add below code to your main.c
/*******************************************/

/* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		HAL_GPIO_WritePin(GPIOB, Buzzer_Pin , GPIO_PIN_SET);		//Buzzer is ON
		HAL_Delay(100);												//Add 100-mSec Delay
		HAL_GPIO_WritePin(GPIOB, Buzzer_Pin , GPIO_PIN_RESET);		//Buzzer is OFF
		HAL_Delay(200);												//Add 200-mSec Delay
		
		//	Alternate code for same operation. Disable above code & enable below code.
		// HAL_GPIO_TogglePin(GPIOB, Buzzer_Pin );					//Toggle IO-Line	
		// HAL_Delay(100);											//Add some delay
  }
  /* USER CODE END 3 */