
#define SENSORPIN 4

#define latchPin 13
#define dataPin 12
#define clockPin 11
#define OE 8 //using new pin on shift register as an output
             //if HIGH shift register operates normally
             //if LOW power to the shift register is cut

byte leds = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(OE, OUTPUT);   
   
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  Serial.begin(9600);
}

void loop(){
  int sensorState = digitalRead(SENSORPIN);
  digitalWrite(OE, HIGH);
  if (sensorState != LOW) //power is getting cut but the count it was at is not reset
  {
    digitalWrite(OE, LOW);
  }
 
updateShiftRegister();
   delay(500);
}

void updateShiftRegister()
{
  leds = leds + 1;
  leds = leds % 256;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
  Serial.print(leds);
}
