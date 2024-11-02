/*GY-25 test Code
 *2023-01-11 electropeak by Ali Akbar Hosseini
 * using software serial for communating with Arduino Uno
 * if using Mega or any thing with more than One Serial channel use hardwareSerial
 * connect sensor TX to arduino RX(in this code pin #8) 
 * connect sensor RX to arduino TX(in this code pin #7)
 */
#include <SoftwareSerial.h> // software Serial, to use another pins as TX, RX
static const int RXPin = 16, TXPin = 17; // announce your Rx and Tx pins
SoftwareSerial newserial(RXPin, TXPin);
float Roll,Pitch,Yaw;
unsigned char Re_buf[8],counter=0;

void setup()
{ 
Serial.begin(9600);
newserial.begin(115200); // SoftwareSerial can only support 9600 baud rate for GY-25 but Serial3 can support 115200 and 9600 both
delay(4000); 
newserial.write(0XA5); 
newserial.write(0X54);//correction mode
delay(4000);
newserial.write(0XA5); 
newserial.write(0X51);//0X51:query mode, return directly to the angle value, to be sent each read, 0X52:Automatic mode,send a direct return angle, only initialization 
}
//looooooooooooooooooop
void loop() {
if (newserial.available()) { 
serialEvent();
Serial.print("roll= ");
Serial.print(Roll);
Serial.print(" pitch= "); 
Serial.print(Pitch);
Serial.print(" yaw= "); 
Serial.println(Yaw);
}
else Serial.println("check connections");
delay(200);
}
//loooooooooooooooooooop END
//data reading function
void serialEvent() { 
 newserial.write(0XA5); 
 newserial.write(0X51);//send it for each read
 while (newserial.available()) { 
 Re_buf[counter]=(unsigned char)newserial.read();
 if(counter==0&&Re_buf[0]!=0xAA) return; 
 counter++; 
 if(counter==8) { // package is complete 
 counter=0; 
 if(Re_buf[0]==0xAA && Re_buf[7]==0x55) { // data package is correct 
 Yaw=(int16_t)(Re_buf[1]<<8|Re_buf[2])/100.00; 
 Pitch=(int16_t)(Re_buf[3]<<8|Re_buf[4])/100.00;
 Roll=(int16_t)(Re_buf[5]<<8|Re_buf[6])/100.00;
 } 
 } 
 } 
}


