#include <RF24.h>
#include <SPI.h>

RF24 radio(9,10);
const byte rxAddr[6] = "00001";
int DATA[2];

void setup() 
{
  radio.begin();
  radio.setRetries(15,15);
  radio.openWritingPipe(rxAddr);

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
}

void loop() 
{
  DATA[0] = digitalRead(2);
  DATA[1] = digitalRead(3);
  DATA[2] = digitalRead(4);
  
  radio.write(DATA,sizeof(DATA));
  delay(10);
}
