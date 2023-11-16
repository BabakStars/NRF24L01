#include <RF24.h>
#include <SPI.h>

RF24 radio1(9,10);
RF24 radio2(7,8);
RF24 radio3(2,4);

const byte rxAddr1[6] = "00001";
const byte rxAddr2[6] = "00010";
const byte rxAddr3[6] = "00020";

void setup() 
{
  radio1.begin();
  radio2.begin();
  radio3.begin();
  
  radio1.setRetries(15,15);
  radio2.setRetries(15,15);
  radio3.setRetries(15,15);
  
  radio1.openWritingPipe(rxAddr1);
  radio2.openWritingPipe(rxAddr2);
  radio3.openWritingPipe(rxAddr3);


}

void loop() 
{
  const char text[] = "1010101010101010";
  for(int j=51;j<73;j++)
  {
      radio1.setChannel(j);
      radio2.setChannel(j);
      radio3.setChannel(j);

      radio1.write(text,sizeof(text));
      radio2.write(text,sizeof(text));
      radio3.write(text,sizeof(text));

      
  }

  delay(1);
}
