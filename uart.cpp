//#include "uart.hpp"
#include "config.hpp"
#include <stdio.h>

void setupUART(){
	srid=serialOpen("/dev/ttyS0",115200);
	if(srid<0)
		printf("can not open serialport\nq	");
	else
	  printf("success open serialport\n");
	//serialPrintf(srid,"rst\r");
	serialPrintf(srid,"sel 32\r");
	serialPrintf(srid,"clear\r");
	serialPrintf(srid,"sel 33\r");
	serialPrintf(srid,"clear\r");
	serialPrintf(srid,"sel 0\r");
	serialPrintf(srid,"dt 0\r");
	serialPrintf(srid,"sel 0\r");
	serialPrintf(srid,"mc 0\r");
	//serialPrintf(srid,"sel 0\r");
	//serialPrintf(srid,"rst\r");
}
