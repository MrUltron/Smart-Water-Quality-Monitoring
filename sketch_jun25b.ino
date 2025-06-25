#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <SD.h>

// Pin definitions
const int pHPin = A0;
const int TDSPin = A1;
const int oneWireBus = 2;
const int chipSelect = 10;

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  lcd.init(); lcd.backlight();
  SD.begin(chipSelect);
  lcd.print("Water Quality");
}

void loop() {
  // Read pH
  int pHValue = analogRead(pHPin);
  float voltage = pHValue * (5.0 / 1023.0);
  float pH = 7 + ((2.5 - voltage) / 0.18);

  // Read TDS
  int tdsValue = analogRead(TDSPin);
  float tds = (tdsValue * (5.0 / 1023.0)) * 500;

  // Read temperature
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.printf("pH: %.2f TDS:%.0f", pH, tds);
  lcd.setCursor(0, 1);
  lcd.printf("Temp: %.1fC", temp);

  // Log to SD card
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.printf("%lu,%.2f,%.0f,%.1f
", millis(), pH, tds, temp);
    dataFile.close();
  }

  // Serial output
  Serial.printf("pH: %.2f, TDS: %.0f ppm, Temp: %.1fC
", pH, tds, temp);

  delay(2000);
}