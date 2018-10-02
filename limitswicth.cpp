#include "config.hpp"


bool GetLim(int pin_num){
  bool state = false;
  if(digitalRead(pin_num)==1){
    state = true;
  }
  return state;
}
