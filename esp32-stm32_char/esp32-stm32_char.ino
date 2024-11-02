
void setup() {
  Serial2.begin(115200, SERIAL_8N1, 16, 17); 
}

void loop() {
  Serial2.println("Hello"); 
  delay(1000);              
}

