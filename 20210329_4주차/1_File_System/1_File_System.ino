#include <FS.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  SPIFFS.begin();
  File f = SPIFFS.open("text.txt", "w");
  f.print("hi there");
  f.close();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(0) == 0) {
    readFile();
  }
  delay(1000);
}

void readFile() {
  File f = SPIFFS.open("text.txt", "r");
  char buff[512];
  int i = 0;
  while (f.available()) {
    buff[i++] = f.read();
  }
  buff[i] = '\0';
  f.close();
  Serial.println(buff);
  Serial.println(i);
}
