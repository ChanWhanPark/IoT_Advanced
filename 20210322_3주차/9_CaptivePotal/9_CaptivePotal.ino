#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 1, 1);
DNSServer dnsServer;
ESP8266WebServer webServer(80);

String responseHTML = "Hello";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("chananpark");

  dnsServer.start(DNS_PORT, "*", apIP);
  webServer.on("/button", button);

  webServer.onNotFound([](){
    webServer.send(200, "text/html", responeHTML);
  });
  webServer.begin();
  Serial.println("Captive Portal Started");
}

void loop() {
  // put your main code here, to run repeatedly:
  dnsServer.processNextRequest();
  webServer.handleClient();
}

void button(){
  Serial.println("button pressed");
  webServer.send(200, "text/plain");
}
