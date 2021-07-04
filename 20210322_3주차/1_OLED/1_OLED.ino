#include <Wire.h>
#include <OLED32.h>

// OLED 디스플레이 선언
// display(SDA, SCL) 
// I2C통신이므로 DATA와 CLOCK 포트 필요

OLED display(4, 5); 
void setup()
{
  display.begin();
  display.print("Hello World!");
  display.print("Welcome to IoT Class!!!", 3, 1);
  delay(2000);
  display.off();
  delay(2000);
  display.on();
}

void loop()
{
  
}
