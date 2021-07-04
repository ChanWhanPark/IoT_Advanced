#include <FS.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPIFFS.begin();
  delay(1000);
  Serial.println();
  File f = SPIFFS.open("text.json", "r");
  char buff[512];
  int i=0;
  while(f.available()){
    buff[i++] = f.read();
  }
  f.close();
  Serial.println(buff);
  Serial.println(i);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

void readFile() {
  
}
