const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;

const int numReadings = 40; //number of readings being used for the average

int readings[numReadings]; //creates an array with the same number of positions as we want numbers to comprise the average
int readIndex = 0; //will be used in place of numReadings, allows comparasin between the two
int total = 0; //will store the sum of numbers in the array at any given point
int average = 0;


int latchPin = 10;
int clockPin = 11;
int dataPin = 12;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) //calls each spot in the array one by one
  {
    readings[thisReading] = 0; //as each position is called it is set to 0
  }
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; //translates time between send and recieve to distance in cm

  if ((distance<200) && (distance>0))
  {
  total = total - readings[readIndex]; //at any specified point in the array, the old value from that spot is subtracted from the sum
  readings[readIndex] = distance; //a new value reading is placed in that same position
  total = total + readings[readIndex]; //the new reading is added into the sum
  readIndex = readIndex + 1; //move to the next position
  }

  if (readIndex >= numReadings)
  {
    readIndex = 0; //compares position of readIndex to maximum position
  }

  average = total / numReadings; //takes sum of #s in array divided by # of positions
  outputBytes(); // will print the value of the average in binary on leds using shift register
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("    Average: ");
  Serial.println(average);

  delay(50);  // slows down reading enough that binary can be read
}
void outputBytes()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, average);
  digitalWrite(latchPin, HIGH);
  delay(10);

}

