
int clockPin = 11;
int dataPin = 12;
int latchPin = 13;


void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

/*void loop() {
  //count up routine
  for (int j = 0; j < 256; j++) {
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);   
    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }
} */


 
void loop(){
   
    outputBytes(); // our basic output which writes 8-bits to show how a shift register works.
    //outputIntegers(); // sends an integer value as data instead of bytes, effectively counting in binary.
}
/* 
void outputIntegers(){
     for (int i=0;i<256;i++){
        digitalWrite(latch, LOW);    
        Serial.println(i);  // Debug, sending output to the serial monitor
        shiftOut(data, clock, MSBFIRST, i);
        digitalWrite(latch, HIGH);  
        delay(100);    
     }
}
 */
void outputBytes(){
    /* Bytes, or 8-bits, are represented by a B followed by 8 0 or 1s.
        In this instance, consider this to be like an array that we'll use to control
        the 8 LEDs. Here I've started the byte value as 00000001
    */    
       
    byte dataValues = B00000001; // change this to adjust the starting pattern
   
    /* In the for loop, we begin by pulling the latch low,
        using the shiftOut Arduino function to talk to the shift register,
        sending it our byte of dataValues representing the state of the LEDs
        then pull the latch high to lock those into place.
       
        Finally, we shift the bits one place to the left, meaning the next iteration
        will turn on the next LED in the series.
       
        To see the exact binary value being sent, check the serial monitor.
    */
   
    for (int i=0;i<8;i++){
      digitalWrite(latchPin, LOW);    
      Serial.println(dataValues, BIN);  // Debug, sending output to the serial monitor
      shiftOut(dataPin, clockPin, MSBFIRST, dataValues);
      digitalWrite(latchPin, HIGH);  
      dataValues = dataValues << 1; // Shift the bits one place to the left -  change to >> to adjust direction
      delay(1000);    
    }
 
}
