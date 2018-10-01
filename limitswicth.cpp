#include "config.hpp"


bool get_lim(int pin_num){
  bool state = false;
  if(digitalRead(pin_num)==1){
    state = true;
  }
  return state;
}
