



#define TXD_PIN(GPIO_NUM_17)
#define RXD_PIN(GPIO_NUM_16)
void setup() {
  // put your setup code here, to run once:
  Serial2.begin(115200, SERIAL_8O2, 16, 17);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  uint8_t a[10]={1,2,3,4,5,6,7,8,9,4};
  for (uint8_t i=0;i<10;i++){
    Serial2.write(a[i]);
  }
  
  delay(100);
}
