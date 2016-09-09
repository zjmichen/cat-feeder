#include <Time.h>
#include <TimeAlarms.h>

int motorPin = 3;
int ledPin = 12;
int potPin = 5;

void setup() 
{
  setTime(0,0,1, 1, 1, 00);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  Alarm.alarmRepeat(0,0,0, feedAlarm);
  Alarm.alarmRepeat(12,0,0, feedAlarm);
  
  feed(getFeedDuration());
} 
 
 
void loop() 
{
}

void feed(int time)
{
  digitalWrite(ledPin, HIGH);
  analogWrite(motorPin, 255);
  delay(time);
  digitalWrite(ledPin, LOW);
  analogWrite(motorPin, 0);
}

int getFeedDuration()
{
  int val = analogRead(potPin);
  return val*30;
}

void feedAlarm() {
  feed(getFeedDuration()); 
}
