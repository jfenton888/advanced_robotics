int clockPin = 11;
int dataPin = 12;
int latchPin = 13;


byte leds = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  leds = 0;
}

void loop()
{

  /*updateShiftRegister();
    delay(500);
    for (int i = 0; i < 8; i++)
    {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
    }*/
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
}
