#include <Wire.h>
#include "Adafruit_ADS1015.h"

Adafruit_ADS1115 ads1115; //on default address


void setup(void)
{

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  //Serial.println("Hello!");
  
  //Serial.println("Getting differential reading from AIN0 (P) and AIN1 (N)");
  //Serial.println("ADC Range: +/- 6.144V (1 bit = 188uV)");
  ads1115.begin();
}

void loop(void)
{
  int16_t results;
  int16_t i;
  
  results = ads1115.readADC_Differential_0_1();
  //Serial.print("Differential: "); Serial.print(results); Serial.print("("); Serial.print((int32_t)(results) * 188); Serial.println("uV)");
  // below just spits out the differential voltage in bits, and then converted to uV (the resolution is 188 uV)
  //Serial.print(results); Serial.print(","); Serial.print((int32_t)(results) * 188); Serial.println();
  Serial.print((int32_t)(results) * 188); Serial.println();
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  
  // for (int i = 0; i < 10; i++) {
  //  delay(1000);
  //  Serial.println(i);
  // }
  // for (int i=0; i < 60; i++){ 
  //  results = ads1115.readADC_Differential_0_1();
  //  Serial.println((int32_t)(results) * 188);
  //  digitalWrite(LED_BUILTIN, LOW);
  //  delay(1000);
  //  digitalWrite(LED_BUILTIN, HIGH);
  // }
}
