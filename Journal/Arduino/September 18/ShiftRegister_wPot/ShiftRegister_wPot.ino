/*
Adafruit Arduino - Lesson 8. Analog Inputs - LEDs
*/
 
int potPin = 0;

int clockPin = 11;
int dataPin = 12;
int latchPin = 13;

 
int leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}
 
void loop() 
{
  int reading  = analogRead(potPin);
  int numLEDSLit = reading / 114;  //1023/114= 9
  leds = 0;
  for (int i = 0; i < numLEDSLit; i++)
  {
    bitSet(leds, i); 
  }
  updateShiftRegister();
}
 
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
