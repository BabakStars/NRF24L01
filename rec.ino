#include <RF24.h>
#include <SPI.h>

RF24 radio(9,10);
const byte rxAddr[6] = "00001";
int DATA[3];

void setup() 
{
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0,rxAddr);
  radio.startListening();

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop()
{
  while(radio.available())
  {
    radio.read(DATA,sizeof(DATA));
    Serial.println(DATA[1]);
    Serial.println(DATA[2]);
    Serial.println(DATA[3]);
    digitalWrite(2,!DATA[0]);
    digitalWrite(3,!DATA[1]);
    digitalWrite(4,!DATA[2]);
  }
}
