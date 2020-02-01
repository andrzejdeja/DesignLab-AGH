#include "ldr.hpp"
#include "Arduino.h"

void Ldr::check(){
    x[i] = analogRead(A0);
    x[i+1] = analogRead(A1);
    TIMES*2 > i+3 ? i += 2 : i = 0;
}

void Ldr::checkAndDraw(Adafruit_SSD1306 d){
    x[i] = analogRead(A0);
    x[i+1] = analogRead(A1);
    d.setTextSize(1);
    d.setCursor(8, 0);
    d.print(x[i]);
    d.setCursor(48, 0);
    d.print(x[i+1]);
    int a = this->getAvg();
    d.setCursor(8, 10);
    d.print("avg");
    d.print(a);
    //d.display();
    TIMES*2 > i+3 ? i += 2 : i = 0;
}

int Ldr::getAvg(){
    int s = 0;
    for(int i = 0; i < TIMES*2; i++){
        s += x[i];
    }
    return s/(2*TIMES);
}
