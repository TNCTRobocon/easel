#include "config.hpp"


void AirUp(){//open [sel 32  1][sel 33  1,3,5] close [sel 32  2,3,4,5,6][sel 33  2,4,6]
  serialPrintf(srid,"sel 32\r");
  serialPrintf(srid,"close 2 3 4\r");
  serialPrintf(srid,"sel 32\r");
  serialPrintf(srid,"close 5 6\r");
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"close 2 4 6\r");
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"open 1 3 5\r");
  serialPrintf(srid,"sel 32\r");
  serialPrintf(srid,"open 1\r");
  printf("air_up\n");
}

void AirDown(){//open [sel 32  2][sel 33  2,4,6] close [sel 32  1,3,4,5,6][sel 33  1,3,5]
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"close 1 3 5\r");
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"open 2 4 6\r");
  serialPrintf(srid,"sel 32\r");
  serialPrintf(srid,"close 1 3\r");
  serialPrintf(srid,"sel 32\r");
  serialPrintf(srid,"close 4 5 6\r");
  serialPrintf(srid,"sel 32\r");
  serialPrintf(srid,"open 2\r");
  printf("air_down\n");
}

void AirClear(){
  serialPrintf(srid,"sel 32\r");
  serialPrintf(srid,"clear\r");
  serialPrintf(srid,"sel 33\r");
  serialPrintf(srid,"clear\r");
  printf("air_clear\n");
}
