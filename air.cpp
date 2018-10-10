#include "config.hpp"


void air_up(){
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"open 1 2 3 4\r");
  printf("air_up\n");
}

void air_down(){
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"close 1 2 3 4 5 6\r");
  printf("air_down\n");
}

void air_clear(){
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"clear\r");
  printf("air_clear\n");
}
