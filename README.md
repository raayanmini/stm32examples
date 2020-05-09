# stm32examples
STM32 Source Code for Raayan Micro Development Board

Hello World Program (Branch: Master)
-------------------------------------
Experiment 1:
Toggle RED LED every 100msec delay using HAL Delay
	Hint: HAL Library Syntax:
			HAL_GPIO_WritePin(USR_LED2_GPIO_Port, USR_LED2_Pin, GPIO_PIN_RESET);
			HAL_Delay(100);
			HAL_GPIO_WritePin(USR_LED2_GPIO_Port, USR_LED2_Pin, GPIO_PIN_RESET);
			HAL_Delay(100);
			HAL_GPIO_WritePin(USR_LED2_GPIO_Port, USR_LED2_Pin, GPIO_PIN_SET);


GPIO Ports Configure to Output(Branch Name: GPIO_OUTPUT)
-----------------------------------------------------------
Experiment 1:
Toggle RED LED ON time is 50ms and RED LED OFF time is 1300ms

Experiment 2:
Airplane wing Lights blinking Delays:
USER LED1 (GREEN): ON (50msec), OFF (50msec), ON (50msec), OFF (150msec) periodically.
USER LED2 (RED): ON (50msec), OFF (250msec), ON (50msec), OFF (500msec) periodically.


GPIO Ports Configure to Input with Polling: (Branch Name: GPIO_INPUT)
---------------------------------------------------------------------
Experiment 3: Whenever SW1 is pressed RED LED is ON, whenever SW2 is pressed GREEN LED is ON.
Assign breakpoints after if condition and click run button in debugger window. Whenever SW1/SW2 presses
program stops at any one of the breakpoint.

Experiment 4: Use “WAKEUP SWITCH” and declare “counter” global variable. Your program should increment
counter by one, every time switch is pressed. Note how the value of counter changes on each “WAKEUP SWITCH”
press. Use debugger and add Counter to “Watch Expression” window. Does the value of counter increment by one
always?
Note: Define counter as a global variable and in debug perspective use continuous refresh option (You will find
Continuous Refresh button on top of the Expression Window). You can use step debugging or breakpoints to check
the variable value.
Hint: To add variable to Expression Window, select and right click the variable name and select “Add Watch
Expression”. To view Expression Window, click on View button from Keil menu bar and select Expressions.

Experiment 5: Whenever WAKEUP SWITCH is Press toggle RED LED.

Experiment 6: Read WAKEUP SWITCH, if switch is press RED LED is ON otherwise RED LED is OFF. Note that RED
LED should remain ON for the duration switch is kept pressed i.e. RED LED should turn OFF when switch is
released.

Experiment 7: Whenever WAKEUP SWITCH Press turn ON BUZZER up to 250msec and Turn OFF BUZZER


GPIO Ports Configure to Input with Interrupt (Branch Name: GPIO_INTERRUPT):
--------------------------------------------------------------------------
Experiment 8: Write a program Request an interrupt on the Falling edge of WAKEUP Switch, whenever the user
button is pressed and increment a counter in the interrupt and RED LED is ON.

Experiment 9: Write an Embedded C Program Whenever SW1 press RED LED is ON, whenever SW2 press GREEN
LED is ON using Falling edge GPIO interrupt.

Experiment 10: Write an Embedded C Program to measure interrupt latency. By default RED LED (-ve Logic Level) is
ON. Whenever WAKEUP SWITCH (-ve Logic Level) is press RED LED is OFF


