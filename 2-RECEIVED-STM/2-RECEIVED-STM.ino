#include <Ps3Controller.h>

void setup()
{
    Serial2.begin(115200, SERIAL_8N1, 16, 17); 
    Ps3.begin("22:22:22:22:22:22");
    
}

void loop()
{
     if( Ps3.data.button.cross ){
         Serial2.write(2);
       }
       else{
       Serial2.write(0);
       }

}
