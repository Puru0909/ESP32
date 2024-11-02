#include <Ps3Controller.h>

void setup()
{
    Serial.begin(115200);
    Ps3.begin("22:22:22:22:22:22");
    Serial.println("Ready.");
}

void loop()
{
  if (Ps3.isConnected()){
    Serial.println("Connected!");
  }

  delay(3000);
}