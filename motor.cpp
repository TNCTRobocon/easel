#include "config.hpp"

void motordrive(int id,float value){
	if(spflag==1){
		printf("mc no\n");
		//mcm(id,(int)(value*200));
	}else{
		dtm(id,value);
	}
}

void dtm(int id, float dt){ //dt
	serialPrintf(srid,"sel %d\r",id);
	serialPrintf(srid,"dt %.2f\r",dt);
	delay(1);
}

void mcm(int id, int mc){ //mc
	serialPrintf(srid,"sel %d\r",id);
	serialPrintf(srid,"mc %d\r",mc);
}
