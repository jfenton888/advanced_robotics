int brightness = 45; //adjustable based on brightness of surroundings
int lightPin = 0;
int latchPin = 10;
int clockPin = 11;
int dataPin = 12;
int motorPin = 3;
 
int leds = 0;

const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
 //photocell gives readings between 1023 and 0 but does usually 
 //reach max readings so to get a range of values between 1 and 8
 //in different settings the brightness divisor changes
void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
  int reading  = analogRead(lightPin);
  
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
    Serial.print("Brightness: ");
    Serial.print(reading);
    Serial.print("  Distance: ");
    Serial.println(distance);
}
 
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
 
