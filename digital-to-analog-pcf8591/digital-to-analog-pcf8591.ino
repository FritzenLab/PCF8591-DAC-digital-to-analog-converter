#include <Adafruit_PCF8591.h>
// Make sure that this is set to the value in volts of VCC
#define ADC_REFERENCE_VOLTAGE 3.3
Adafruit_PCF8591 pcf = Adafruit_PCF8591();

int SerialValue;
long oldtime;
long oldtime2;
int valueToWrite;


void setup() {
  Serial.begin(115200);
  while (!Serial)
    delay(10);

  pcf.begin();
  pcf.enableDAC(true);
  Serial.println("Type a value between 0.00 and 3.30 (a voltage)");
}

uint8_t dac_counter = 0;

void loop() {
  
  
  if (Serial.available() > 0) {
    // read the incoming byte:
    SerialValue = (Serial.readString().toFloat())*100;
    valueToWrite= map(SerialValue, 0, 330, 0, 255);
    
  }
  
  if(millis() - oldtime2 > 500){
    oldtime2= millis();
    pcf.analogWrite(valueToWrite);
  }  
}