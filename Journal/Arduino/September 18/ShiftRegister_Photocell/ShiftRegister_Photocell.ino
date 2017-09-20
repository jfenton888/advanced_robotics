int brightness = 25; //adjustable based on brightness of surroundings
int lightPin = 0;
int latchPin = 10;
int clockPin = 11;
int dataPin = 12;
int motorPin = 3;
 
int leds = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}
 //photocell gives readings between 1023 and 0 but does usually 
 //reach max readings so to get a range of values between 1 and 8
 //in different settings the brightness divisor changes
void loop() 
{
  int reading  = analogRead(lightPin);
  Serial.println(reading);
  int numLEDSLit = reading / brightness;
  if (numLEDSLit > 8) numLEDSLit = 8;
  leds = 0;   // no LEDs lit to start
  for (int i = 0; i < numLEDSLit; i++)
  {
    leds = leds + (1 << i);  // sets the i'th bit
  }
  updateShiftRegister();
  int speed = numLEDSLit*23; //speed is x23 the number of LEDs on
  if (speed > 255) speed = 255;
    if (speed >= 0)
    {
      analogWrite(motorPin, speed);
    }
}
 
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
 
