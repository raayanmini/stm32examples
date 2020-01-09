/*******************************************/
Please add below code to your main.c
/*******************************************/

/* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		if(HAL_GPIO_ReadPin(SW_ENTER_GPIO_Port,SW_ENTER_Pin)==GPIO_PIN_RESET){				//Read IO-Pin for low-level
			HAL_Delay(40);																															//Add some debounce delay
			if(HAL_GPIO_ReadPin(SW_ENTER_GPIO_Port,SW_ENTER_Pin)==GPIO_PIN_RESET){			//Read IO-Pin for low-level
				HAL_GPIO_WritePin(User_Led_1_GPIO_Port, User_Led_1_Pin, GPIO_PIN_RESET);	//Make led-ON
				while(HAL_GPIO_ReadPin(SW_ENTER_GPIO_Port,SW_ENTER_Pin)==GPIO_PIN_RESET);	//Wait till switch is released
				}	
			}
		
		HAL_GPIO_WritePin(User_Led_1_GPIO_Port, User_Led_1_Pin, GPIO_PIN_SET);				//Always Make led-OFF
  }
  /* USER CODE END 3 */