const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;

const int numReadings = 100;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int clockPin = 11;
int dataPin = 12;
int latchPin = 13;


void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
  {
    readings[thisReading] = 0;
  }
}

void loop()
{
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
  {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    readIndex = thisReading;
    readings[readIndex] = distance;
    total = total + readings[readIndex];

  }

  // calculate the average:
  average = total / numReadings;
  outputBytes();
  // send it to the computer as ASCII digits
  Serial.println(average);
  delay(100);
  readIndex = 0;
  total = 0;
  return average;
}

void outputBytes()
{
      digitalWrite(latchPin, LOW);    
      shiftOut(dataPin, clockPin, LSBFIRST, average);
      digitalWrite(latchPin, HIGH);  
      delay(100);    
  
}

