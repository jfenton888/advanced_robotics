
int clockPin = 11;
int dataPin = 12;
int latchPin = 13;
int speakerPin = 2;

 
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop()
{
  outputBytes();
}
void outputBytes()
{
  byte leds = B00000001;

  for (int i = 0; i < 8; i++)
  {
    delay(1000);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
    leds = leds << 1; // Shift the bits one place to the left -  change to >> to adjust direction
    int pitch = 262 + i * 32.75;
    tone(speakerPin, pitch);
  }
}
