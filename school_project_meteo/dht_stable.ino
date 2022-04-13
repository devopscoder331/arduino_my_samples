// include the library code:
#include <LiquidCrystal.h>
#include <DHTStable.h>

#define DHTTYPE DHT11

int DHTPIN = 8;
DHTStable DHT;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Temperature!");
}

void loop() {
  delay(2000);
  DHT.read11(DHTPIN);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity = ");
  lcd.print(DHT.getHumidity());
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  lcd.print(DHT.getTemperature(), 1);
  
  delay(2000);

}
