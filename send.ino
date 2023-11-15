#include <RF24.h>
#include <SPI.h>
#define led 2

RF24 radio(9,10);
const byte addresses[][6] = {"00001","00002"};
boolean buttonState = 0;

void setup() 
{
  pinMode(2,OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[1]);  //00002
  radio.openReadingPipe(1,addresses[0]);  //00001
  radio.setPALevel(RF24_PA_MIN);
}

void loop() 
{
  delay(5);
  radio.stopListening();
  int potValue = analogRead(A5);
  int analogValue = map(potValue,0,1023,0,180);
  radio.write(&analogValue,sizeof(analogValue));
  delay(5);
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState,sizeof(buttonState));

  if (buttonState == HIGH)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
