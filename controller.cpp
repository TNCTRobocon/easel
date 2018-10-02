#include "config.hpp"
//#include "controller.hpp"

void DeinitCon(){
		close(fd);
		puts("safity exit");
}

void SetupCon(){
	fd = open("/dev/input/js0",O_RDONLY);
	errnum=errno;
	if(fd<0){
		printf("can not open file \n error=%d \n %s \n",errnum,strerror(errnum));
	}else{
		printf("open file\n");
	}
	atexit(DeinitCon);
}

unsigned char GetCon(){
	read(fd,&joysta,sizeof(joysta));
	switch(joysta.type & 0x7f){
			case JS_EVENT_BUTTON:
				if(joysta.value){
					reccon[8]=reccon[8] | (1 << joysta.number);
				}else{
					reccon[8]=reccon[8] & (!(1 << joysta.number));
				}
				return joysta.number+10;
				break;
			case JS_EVENT_AXIS:
				if((reccon[joysta.number]>highest && joysta.value<highest) || (reccon[joysta.number]<lowest && joysta.value>lowest) || (reccon[joysta.number]<highest && joysta.value>highest) || (reccon[joysta.number]>lowest && joysta.value<lowest)){
						reccon[joysta.number]=joysta.value;
						//printf("axis_%d\n",joysta.number);
						return joysta.number;
				}
	}
	return 0;//TODO　for fixing error but unknown reason.
}
