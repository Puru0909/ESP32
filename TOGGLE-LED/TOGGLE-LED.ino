void setup() {
  
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  
}

void loop() {
  Serial2.write(0); 
  delay(500);        
      
}
// //reverse condition
// #define LED_PIN 2  // ESP32 built-in LED

// void setup() {
//   Serial.begin(115200);  
//   pinMode(2, OUTPUT);  
// }

// void loop() {
//   if (Serial.available()) {  
//     char receivedByte = Serial.read();  
//     if (receivedByte == 1) {
//       digitalWrite(2, HIGH);  // LED ON hogi
//     } else if (receivedByte == 0) {
//       digitalWrite(2, LOW);   //  LED OFF hogi
//     }
//   }
// }
