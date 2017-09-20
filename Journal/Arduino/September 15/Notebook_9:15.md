# advanced_robotics 9/14/2017


* Duration
	* 22:00-00:30
* Task
	* Adafruit Lesson 3
		* Didn't see the change in assignment so I took the Lesson 3 task further on my own
* Summary
	* I remebered what Mr. D had said about expanding on the more general tasks, so I decided to turn my simple RGB LED into a matching game. I knew how to set up the RGB but I had to look up how to arrange the LCD Display pins into the Arduino. After that it was a matter of parcing the code to understand what was actually being done with each line. Once I knew what was going on in the sample code I was able to take the parts I wanted from each and combine them. Then all I had to do was give the code a "random" order to randomize the colors on the LED and on the LCD.

* Successes
	* Understanding what was being written on both sample codes so I could scrap them for what I wanted
	* Getting a matching game working
* Issues
	* Had trouble getting the LCD display to show the values I wanted
		* Multiple errors compounded
			* Couldn't get the pot to work- one from the kit faulty
			* Words on LCD kept printing on top of each other 
			* 
	* Had to find out how to randomize the values being sent to the LCD and RGB
	* To get the game to work I had to get change the if statement from `randNumberC==randNumberD && buttonState == LOW` to `randNumberC==randNumberD && buttonState != HIGH`
* Next task
	* Next Homework Assignment

* Pictures and Videos
	* 