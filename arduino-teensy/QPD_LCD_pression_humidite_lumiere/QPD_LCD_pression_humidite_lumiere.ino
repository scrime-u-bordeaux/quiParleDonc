// multiple lcd => try https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/
//see ===>>> https://forum.arduino.cc/index.php?topic=51651.0
//#include <Wire.h>  // Comes with Arduino IDE
//#include <LiquidCrystal_I2C.h>
//
//LiquidCrystal_I2C lcd1(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
//// Specify the 1st I2C chip address used for 1st LCD & its connection pins 
//// (addr, en,rw,rs,d4,d5,d6,d7,bl,blpol);
//
//LiquidCrystal_I2C lcd2(0x26, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
//// Specify the 2nd I2C chip address used for 2nd LCD & its connection pins 
//// (addr, en,rw,rs,d4,d5,d6,d7,bl,blpol);
//
//
//void setup()   
//{
//  Serial.begin(9600); 
//
//  lcd1.begin(16,2);   // initialize the 1st lcd for 16 chars 2 lines, turn on backlight
//  lcd2.begin(16,2);   // initialize the 2nd lcd for 16 chars 2 lines, turn on backlight
//
////-------- Write characters on the 1st & 2nd displays ------------------
// // NOTE: Cursor Position: (CHAR, LINE) start at 0  
//  lcd1.setCursor(0,0); 
//  lcd1.print("Hello, world!");
//  lcd2.setCursor(0,0); 
//  lcd2.print("Hello, world!");
//  delay(2000);
//  lcd1.setCursor(0,1);
//  lcd1.print("I'm 1st 16x2LCD");
//  lcd2.setCursor(0,1);  
//  lcd2.print("I'm 2nd 16x2LCD");
//}
//
//
//void loop()   
//{
// }

#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
//Library allows either I2C or SPI, so include both.
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C
LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_PCF8574 lcd2(0x26); 2eme ecran lcd???
int error;
int show = -1;
int h;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  //Wire.beginTransmission(0x27);
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();
  lcd.print("LCD OK");
  lcd.setCursor(0, 1);
  lcd.print("P  /  H%  /  lum");
  delay(2000);
  lcd.clear();
  lcd.noBlink();
  lcd.noCursor();
  bme.begin();  
}


void loop()
{

h = map(analogRead(A0), 640, 310, 0, 100);
h = constrain(h, 0, 100);
  lcd.setBacklight(255);
  //lcd.home();
  lcd.clear();
  lcd.print("T*:");
  lcd.print(bme.readTemperature());
  lcd.print("P*:");
  lcd.print(bme.readPressure() / 100.0F);
  lcd.print("hPa");
  lcd.print("H%:");
  lcd.print(bme.readHumidity());
  lcd.setCursor(0, 1);
  lcd.print("H% sol : ");
  if (h<10)lcd.print("0");
  lcd.print(h);
 
  lcd.print("H% sol : ");
  lcd.print(h);
  
  Serial.print("h");
  Serial.print(h);
  delay(1000);



  //   else if (show == 1) {
  //    lcd.clear();
  //    lcd.print("Cursor On");
  //    lcd.cursor();
  //
  //  } else if (show == 2) {
  //    lcd.clear();
  //    lcd.print("Cursor Blink");
  //    lcd.blink();
  //
  //  } else if (show == 3) {
  //    lcd.clear();
  //    lcd.print("Cursor OFF");
  //    lcd.noBlink();
  //    lcd.noCursor();
  //
  //  } else if (show == 4) {
  //    lcd.clear();
  //    lcd.print("Display Off");
  //    lcd.noDisplay();
  //
  //  } else if (show == 5) {
  //    lcd.clear();
  //    lcd.print("Display On");
  //    lcd.display();
  //
  //  } else if (show == 7) {
  //    lcd.clear();
  //    lcd.setCursor(0, 0);
  //    lcd.print("*** first line.");
  //
  //    lcd.print("*** second line.");
  //
  //  } else if (show == 8) {
  //    lcd.scrollDisplayLeft();
  //  } else if (show == 9) {
  //    lcd.scrollDisplayLeft();
  //  } else if (show == 10) {
  //    lcd.scrollDisplayLeft();
  //  } else if (show == 11) {
  //    lcd.scrollDisplayRight();
  //
  //  } else if (show == 12) {
  //    lcd.clear();
  //    lcd.print("write-");
  //
  //  } else if (show > 12) {
  //    lcd.print(show - 13);
  //  } // if

  //  delay(1400);
  //  show = (show + 1) % 16;
}
