#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TIMES 5

class Ldr {
    int i = 0;
    int x[2*TIMES];

    public:
    void check();
    void checkAndDraw(Adafruit_SSD1306 d);
    int getAvg();
};
