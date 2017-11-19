# advanced_robotics 9/17/2017


* Task
	* Finish
* Summary
	* I spent all night working on it and made a new motor deck and re made everything related to the motors to try to get them taking a pin out
	* I took multiple approaches to ry to get the motors defined within my code
		* One way was by not even calling them motors and running them as standerd pwm outputs but that proved unsuccessful
		* I also tried to take what the crazyflie already had for motors and coppy it, making another set of files with a different name for everywhere motors were called on, but this proved impossible 
		* I finally added onto their preexisting code for the motors and defined more motors within that framework(my worry being that it would screw with the other motors if I did but it was the only option)
	* I then had to find out what to call the PWM ports in the code because none of the code I found, either in their preexisting code or other people's, called the ports the same names as are on the expansion deck so I had to go into their hardware specs to match the names. 
	* Motors in the code need to be defined with many different aspects that help define what they are, not something that wa easy to write for

>		* static const MotorPerifDef CONN_M5 ={
    .drvType       = BRUSHED, 
     .gpioPerif     = RCC_AHB1Periph_GPIOA,
    .gpioPort      = GPIOA,
    .gpioPin       = GPIO_Pin_3,
    .gpioPinSource = GPIO_PinSource3,
    .gpioOType     = GPIO_OType_OD,
    .gpioAF        = GPIO_AF_TIM5,
    .timPerif      = RCC_APB1Periph_TIM5,
    .tim           = TIM5,
    .timPolarity   = TIM_OCPolarity_High,
    .timDbgStop    = DBGMCU_TIM5_STOP,
    .timPeriod     = MOTORS_PWM_PERIOD,
    .timPrescaler  = MOTORS_PWM_PRESCALE,
    .setCompare    = TIM_SetCompare4,
    .getCompare    = TIM_GetCapture4,
    .ocInit        = TIM_OC4Init,
    .preloadConfig = TIM_OC4PreloadConfig,
    };
    // Connector M6, PA2, TIM2_CH3
    static const MotorPerifDef CONN_M6 =
    {
    .drvType       = BRUSHED,
    .gpioPerif     = RCC_AHB1Periph_GPIOA,
    .gpioPort      = GPIOA,
    .gpioPin       = GPIO_Pin_2,
    .gpioPinSource = GPIO_PinSource2,
    .gpioOType     = GPIO_OType_OD,
    .gpioAF        = GPIO_AF_TIM2,
    .timPerif      = RCC_APB1Periph_TIM2,
    .tim           = TIM2,
    .timPolarity   = TIM_OCPolarity_High,
    .timDbgStop    = DBGMCU_TIM2_STOP,
    .timPeriod     = MOTORS_BL_PWM_PERIOD,
    .timPrescaler  = MOTORS_BL_PWM_PRESCALE,
    .setCompare    = TIM_SetCompare3,
    .getCompare    = TIM_GetCapture3,
    .ocInit        = TIM_OC3Init,
    .preloadConfig = TIM_OC3PreloadConfig,
    };

	
* What do I have working
	* When I turn the done on now it will run the motor forever that I have added using my code(kind of a win)
	* If that motor is not plugged in it will initialize the other motors just like it would have before
	* its formated to have 6 motors now
* Failure
	* it doesnt take inputs from the controller now
* Next task
	* Get it working correctly
* Useful links
	* <https://forum.bitcraze.io/viewtopic.php?t=2005#p10187> 
* Pictures and Videos
	* 