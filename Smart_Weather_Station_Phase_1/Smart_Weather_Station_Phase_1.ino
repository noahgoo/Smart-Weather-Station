#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 9
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(13, 12, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  delay(100);
  lcd.print("Weather Station");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  dht.read(DHTPIN);

  // if (isnan(humid) || isnan(temp)) {
  //   Serial.println("Failed to read from DHT sensor!");
  //   return;  // Skip the rest of the loop if sensor failed
  // }

  Serial.print("Humidity: ");
  Serial.print(humid);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" ºC");

  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humid);

  delay(2000);
}
