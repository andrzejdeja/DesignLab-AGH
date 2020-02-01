#include "cservo.hpp"

cServo::cServo(short _min_pos = 0, short _max_pos = 180) {
    min_pos = _min_pos >=0 ? _min_pos : 0;
    max_pos = _max_pos <=180 ? _max_pos : 180;
}

void cServo::setPosDegree(short new_pos){
    if (new_pos <= max_pos && new_pos >= min_pos) servo.write(new_pos);
}

int cServo::setPos10k(short new_pos, short offset){
  short t[40] = {0, 11, 57, 143, 259, 397, 552, 722, 903, 1094, 1293, 1501, 1716, 1937, 2164, 2398, 2638, 2884, 3135, 3393, 3657, 3926, 4203, 4486, 4775, 5072, 5377, 5689, 6009, 6338, 6676, 7024, 7381, 7750, 8130, 8522, 8927, 9346, 9779, 10000};
  short i = 0;
  new_pos = new_pos < 10000 ? new_pos : 10000;
  for(;i < 40; i++){
    if (t[i] >= new_pos) break;
  }
  setPosDegree(i + 6 + offset);
  return i + 6;
}

void cServo::setup(short pin){
    servo.attach(pin);
}
