#include <Servo.h>

class cServo {
    short min_pos;
    short max_pos;
    Servo servo;

    public:
    cServo(short, short);

    void setPosDegree(short new_pos);
    int setPos10k(short new_pos, short offset); //0-10000 to degree
    void setup(short);
};
