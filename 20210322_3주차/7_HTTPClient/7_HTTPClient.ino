#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

const char* ssid = "IoT518";
const char* password = "iot123456"

#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); // use for client
  WiFi.begin(ssid, password);
  Serial.println("");

  //Wait for connection
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());

  if (MDNS.begin("chananpark")){ // DNS의 이름을 줌
    Serial.println("MDNS responder started");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  MDNS.update();
  WiFiClient client;
  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  if (http.begin(client, "http://www.amazon.com")){
    Serial.print("[HTTP] Get...\n");
    int httpCode = http.GET();
    if (httpCode > 0){
      Serial.printf("[HTTP] Get... code: %d\n", httpCode);
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY){
        String payload = http.getString();
        Serial.println(payload);
      }
  } else {
    Serial.printf("[HTTP] Get... Failed. error : %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  }
  else{
    Serial.printf("[HTTP] Unable to connect\n");
  }

  delay(10000);
}
