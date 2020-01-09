/*******************************************/
Please add below code to your main.c
/*******************************************/

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		HAL_GPIO_WritePin(User_Led_1_GPIO_Port, User_Led_1_Pin, GPIO_PIN_RESET); 	// 	IO line goes Low (Led is  ON)
		HAL_Delay(1000);															//	Add 1-Second Delay	
		HAL_GPIO_WritePin(User_Led_1_GPIO_Port, User_Led_1_Pin, GPIO_PIN_SET);		// 	IO line goes High (Led is  OFF)
		HAL_Delay(1000);															//	Add 1-Second Delay
  }
