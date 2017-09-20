#include <LiquidCrystal.h>


int redPin = 10;
int greenPin = 9;
int bluePin = 6;
const int  buttonPin = 13;


LiquidCrystal lcd(2, 4, 3, 5, 11, 12);

void setup() {
  randomSeed(analogRead(0));
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  

}

void loop() {
  int score=0;
  while(true)
  {
  int buttonState = digitalRead(buttonPin);
  int randNumberC=random(3);
  int randNumberD=random(3);
  int oldScore=score;
  lcd.setCursor(0, 1);
  lcd.print(score);
  lcd.setCursor(0,0);
   

  if (randNumberC==0)
  {
    setColor(255, 0, 0);  //light is red  
  }
  else if (randNumberC==1)
  {
    setColor(0, 255, 0);  //light is green
  }
  else
  {
    setColor(0, 0, 255);  // light is blue
  }
  
  randNumberD=random(3);
  if (randNumberD==0)
  {
   lcd.print("RED");  //display says red
    
  }
  else if (randNumberD==1)
  {
   lcd.print("GREEN"); //display says green
  }
  else
  {
   lcd.print("BLUE"); //display says blue
  }
 
  delay(2000);
  buttonState = digitalRead(buttonPin);
  
  if(randNumberC==randNumberD && buttonState != HIGH || randNumberC!=randNumberD && buttonState == HIGH)
  {
    lcd.clear();
    lcd.print("GAME OVER");
    lcd.setCursor(0, 1);
    lcd.print("TRY AGAIN");
    delay(5000);
    score=0;
  }
  if(randNumberC==randNumberD && buttonState == HIGH){
    score=oldScore+1;
  }
  lcd.clear();
  } 
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
