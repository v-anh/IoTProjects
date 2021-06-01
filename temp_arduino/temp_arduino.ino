#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

const int DHTPIN = A3;
const int DHTTYPE = DHT22;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorPin = A0;
void setup()
{
	Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Temp: ");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Do Am: ");
  Serial.println(h);
  Serial.print("Nhiet Do: ");
  Serial.println(t);

  if(isnan(t) || isnan(h)) {} else {
    lcd.setCursor(6,0);
    lcd.print(round(t));
    lcd.print("\337C");

    lcd.setCursor(10,1);
    lcd.print(round(h));
    lcd.print("%");
  }
}
