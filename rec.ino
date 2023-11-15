#include <RF24.h>
#include <SPI.h>
#include <Servo.h>
#define button 4

RF24 radio(9,10);
const byte addresses[][6] = {"00001","00002"};
Servo myServo;
boolean buttonState = 0;

void setup() 
{
  pinMode(button,INPUT_PULLUP);
  myServo.attach(5);
  radio.begin();
  radio.openWritingPipe(addresses[0]);  //00001
  radio.openReadingPipe(1,addresses[1]);  //00002
  radio.setPALevel(RF24_PA_MIN);
  myServo.write(90);
}

void loop()
{
  delay(5);
  radio.startListening();
  if (radio.available())
  {
    while (radio.available())
    {
      int anglev = 0;
      radio.read(&anglev,sizeof(anglev));
      myServo.write(anglev);
    }
    delay(5);
    radio.stopListening();
    buttonState = digitalRead(button);
    radio.write(&buttonState,sizeof(buttonState));
  }
}
