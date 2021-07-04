#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

const char* ssid = "chananpark";
const char* password = "";

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

  // 엑세스 방법 : host_name.domain_name
  // ping chananpark.local

}

void loop() {
  // put your main code here, to run repeatedly:
  MDNS.update();
}
