#include <DHTesp.h>
#include <OLED32.h>
#include <Wire.h>

DHTesp dht; // dht object
OLED display(4, 5);
int interval = 2000;
unsigned long lastDHTReadmillis = 0;
float humidity = 0;
float temperature = 0;
char buf[50];

void setup() {
  // put your setup code here, to run once:
  display.begin();
  display.print("Humid(%) Temp(C) ");
  Serial.begin(115200);
  dht.setup(14, DHTesp::DHT22); // Connect DHT sensor
  delay(1000);
  Serial.println();
  Serial.println("Humidity(%)\tTemperature(C)");

}

void loop() {
  // put your main code here, to run repeatedly:
  readDHT22();

  Serial.printf("%.1f\t %.1f\n", humidity, temperature);
  sprintf(buf, "%.1f %.1f", humidity, temperature);
  display.print(buf, 2, 1);
  delay(1000);
}

void readDHT22(){
  unsigned long currentMillis = millis(); // current time

  if (currentMillis - lastDHTReadmillis >= interval){ // interval
    lastDHTReadmillis = currentMillis;

    humidity = dht.getHumidity();
    temperature = dht.getTemperature();
  }
}
