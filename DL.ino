#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#include "cservo.hpp"
#include "ldr.hpp"

#define DEBUG

#define SERVO_OFFSET 0

cServo cservo(0, 180);
Adafruit_SSD1306 display(128, 32);
Ldr ldr;

void setup() {
  cservo.setup(3);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);
  display.display();
}

void loop() {
  display.clearDisplay();
  #ifndef DEBUG
  ldr.check();
  #else
  ldr.checkAndDraw(display);
  #endif
  #ifndef DEBUG
  #else
  int a = ldr.getAvg();
  long ai = a * 10000L;
  ai = ai/1023;
  int deg = cservo.setPos10k(ai, SERVO_OFFSET);
  display.setTextSize(1);
  display.setCursor(56, 10);
  display.print("10k");
  display.print(ai);
  display.setCursor(8, 20);
  display.print("deg");
  display.print(deg);
  display.print("(+");
  display.print(SERVO_OFFSET);
  display.print(")");
  #endif
  display.display();
  delay(50);
}
