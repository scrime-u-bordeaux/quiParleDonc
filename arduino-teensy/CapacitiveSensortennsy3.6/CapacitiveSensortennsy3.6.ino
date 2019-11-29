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
void setup()
{
  cs_0_1.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
}

void loop()
{
  long start = millis();
  long cs1 =  cs_0_1.capacitiveSensor(30);
  long cs2 =  cs_2_3.capacitiveSensor(10);
  long cs3 =  cs_4_5.capacitiveSensor(10);
  long cs4 =  cs_6_7.capacitiveSensor(10);
  long cs5 =  cs_8_9.capacitiveSensor(10);
  Serial.print("top");
  Serial.println(millis() - start);        // check on performance in milliseconds
  Serial.print("data");

  Serial.println(cs1);
  Serial.println(cs2);
  Serial.println(cs3);
  Serial.println(cs4);
  Serial.println(cs5);      // print sensor output 1

  delay(10);                             // arbitrary delay to limit data to serial port
}
