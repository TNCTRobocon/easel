
#include "config.hpp"

void setupUART(){
	srid=serialOpen("/dev/ttyS0",115200);
	if(srid<0)
		printf("can not open serialport\n");
	else
	  printf("success open serialport\n");
	serialPrintf(srid,"sel 33\r");
	serialPrintf(srid,"clear\r");
	serialPrintf(srid,"sel 0\r");
	serialPrintf(srid,"dt 0\r");
	serialPrintf(srid,"sel 0\r");
	serialPrintf(srid,"mc 0\r");
}
