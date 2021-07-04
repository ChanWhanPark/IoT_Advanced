#include <ArduinoJson.h>
StaticJsonDocument<1024> doc;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  deserializeJson(doc, "{'name':'chananpark', 'studentNum':'2016146022', 'scores':{'C++':'A','Python':'B'}}");

  doc["dept"]="embedded";
}

void loop() {
  // put your main code here, to run repeatedly:
  serializeJson(doc, Serial);
  Serial.println();
  serializeJsonPretty(doc, Serial);
  Serial.println((const char*)doc["scores"]);
  delay(1000);
}
