//Sillur
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

//LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)
LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float temp;
float humi;
float newTemp;
float newHumi;

void setup(){
  Serial.begin(9600);
  dht.begin();

  temp = dht.readTemperature();
  humi = dht.readHumidity();

  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

  lcd.init();                      
  lcd.backlight();

  lcd.setCursor(1,0);
  lcd.print("Temp:");
  lcd.setCursor(1,1);
  lcd.print("Humi:");
  
  lcd.setCursor(8,0);
  lcd.print(String(temp) + " C");
  
  lcd.setCursor(8,1);
  lcd.print(String(humi) + " %");
}

void loop(){
  newTemp = dht.readTemperature();
  newHumi = dht.readHumidity();

  if (temp != newTemp) {
    temp = newTemp;
    
    lcd.setCursor(8,0);
    lcd.print(String(temp) + " C");
  }

  if (humi != newHumi) {
    humi = newHumi;
    
    lcd.setCursor(8,1);
    lcd.print(String(humi) + " %");
  }

  delay(1000);
}
