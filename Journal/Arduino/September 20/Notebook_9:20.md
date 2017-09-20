# advanced_robotics 9/19/2017


* Duration
	* 9/18: Class time+ 15:20-16:20 and 9/19 18:30-19:30
* Task
	* Get the ultrasonic to send less outliers using smoothing/moving average
		* Add ultrasonic sensor on top of shift register circuit
* Summary
	* We started the assignment in class by trying to add the ultrasonic sensor to the breadboard and arduino circuit. Once I had sample code downloaded and providing me with values on the Serial Monitor I had to figure out how to do it better. In my research I found that one way to get smoother readings is to find the average of the last x readings(done by adding the sum of the last x readings and dividing it by x). I did this by storing x readings in an array that began with all values at 0- each time a value was recieved it was put in the current position and then moves to the next one-when all positions have been filled it loops back to the beginnning and will always replace the oldest value in the array. The sum is constantly being taken, and right before a value is replaced in the array it is subtracted from the sum, effectively erasing its imprint on the code.
	* I also made another program that would completely replace every value from the old array each time it ran- meaning that the average being displayed a new average only when the 0th position was the oldest data point in the array. 
	* Because I thought it was too boring on its own, I made it so that the shift register LEDs would display the binary value of the average at that point

* Successes
	* Got both programs and displaying their values on the LEDS
	* Learned a lot about using arrays
	* Issues
	* took a while to understand exactly what was being said in the best moving average code ("this is why commenting matters")
* Next task
	* Next Homework Assignment

* Pictures and Videos
	* 