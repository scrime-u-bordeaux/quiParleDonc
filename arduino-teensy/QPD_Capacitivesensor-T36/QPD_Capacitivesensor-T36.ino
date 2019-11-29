#include <CapacitiveSensor.h>

/*
   CapitiveSense Library Demo Sketch
   Paul Badger 2008
   Uses a high value resistor e.g. 10M between send pin and receive pin
   Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
   Receive pin is the sensor pin - try different amounts of foil/metal on this pin
*/


CapacitiveSensor   cs_0_1 = CapacitiveSensor(0, 1);
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4, 5);
CapacitiveSensor   cs_6_7 = CapacitiveSensor(6, 7);
CapacitiveSensor   cs_8_9 = CapacitiveSensor(8, 9);

long cs1 =  0;
long cs2 =  0;
long cs3 =  0;
long cs4 =  0;
long cs5 =  0;
void setup()
{
  //cs_0_1.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
}

void loop()
{
  cs1 =  0;
  cs2 =  0;
  cs3 =  0;
  cs4 =  0;
  cs5 =  0;
  for (int i = 0 ; i < 10; i++) {
    cs1 =  cs1 + cs_0_1.capacitiveSensorRaw(10);
    delay(1);
    cs2 =  cs2 + cs_2_3.capacitiveSensorRaw(10);
    delay(1);
    cs3 =  cs3 + cs_4_5.capacitiveSensorRaw(10);
    delay(1);
    cs4 = cs4 +  cs_6_7.capacitiveSensorRaw(10);
    delay(1);
    cs5 =  cs5 + cs_8_9.capacitiveSensorRaw(10);
    delay(1);

  }
  cs1 = cs1 / 10;
  cs2 = cs2 / 10;
  cs3 = cs3 / 10;
  cs4 = cs4 / 10;
  cs5 = cs5 / 10;
  //Serial.print(0);
  //Serial.print(", ");
  //Serial.print("d");
  Serial.print(cs1); 
  Serial.print(cs2);
  Serial.print(cs3);
  Serial.print(cs4);
  Serial.print(cs5);
  Serial.println();
  // print sensor output 1

  // arbitrary delay to limit data to serial port
}
