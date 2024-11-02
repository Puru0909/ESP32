#include <Ps3Controller.h>
uint8_t a[10];

void setup()
{
    Serial2.begin(115200, SERIAL_8O2, 16, 17);
    Ps3.begin("22:22:22:22:22:22");
    

 a[0] = 1;
 a[9] = 4;
}


void loop()
{
  // Check if the cross button is pressed
  a[1]=Ps3.data.analog.button.up;
  a[2]=Ps3.data.analog.button.down;
  a[3]=Ps3.data.analog.button.left;
  a[4]=Ps3.data.analog.button.right;
  a[5]=Ps3.data.analog.button.square;
  a[6]=Ps3.data.analog.button.cross;
  a[7]=Ps3.data.analog.button.circle;
  a[8]=Ps3.data.analog.button.triangle;
  // a[9]=Ps3.data.button.select;
  // a[10]=Ps3.data.button.start;
  
  for (uint8_t i=0;i<10;i++){
    Serial2.write(a[i]);
  }
    
}