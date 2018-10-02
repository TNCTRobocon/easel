#include "config.hpp"
//#include "move.hpp"
#include <stdio.h>

#define sign_rf -1 //lb
#define sign_lf 1//rf
#define sign_rb -1//lf
#define sign_lb 1 //rb

void Front(float value){
  if(spflag==1){
		printf("flont %d\n",(int)value*100);
	}else{
		printf("flont %.2lf\n",value);
	}
  motordrive(tirerf,sign_rf*value);
  motordrive(tirerb,sign_rb*value);
  motordrive(tirelf,sign_lf*value);
  motordrive(tirelb,sign_lb*value);
}

void Back(float value){
  if(spflag==1){
		printf("back %d\n",(int)value*100);
	}else{
		printf("back %.2lf\n",value);
	}
  motordrive(tirerf,-sign_rf*value);
  motordrive(tirerb,-sign_rb*value);
  motordrive(tirelf,-sign_lf*value);
  motordrive(tirelb,-sign_lb*value);
}

void Right(float value){
  if(spflag==1){
		printf("right %d\n",(int)value*100);
	}else{
		printf("right %.2lf\n",value);
	}
  motordrive(tirerf,-sign_rf*value);
  motordrive(tirerb,sign_rb*value);
  motordrive(tirelf,sign_lf*value);
  motordrive(tirelb,-sign_lb*value);
}

void Left(float value){
  if(spflag==1){
		printf("left %d\n",(int)value*100);
	}else{
		printf("left %.2lf\n",value);
	}
  motordrive(tirerf,sign_rf*value);
  motordrive(tirerb,-sign_rb*value);
  motordrive(tirelf,-sign_lf*value);
  motordrive(tirelb,sign_lb*value);
}

void TurnRight(float value){
  if(spflag==1){
		printf("turn-right %d\n",(int)value*100);
	}else{
		printf("turn-right %.2lf\n",value);
	}
  motordrive(tirerf,-sign_rf*value);
  motordrive(tirerb,-sign_rb*value);
  motordrive(tirelf,sign_lf*value);
  motordrive(tirelb,sign_lb*value);
}

void TurnLeft(float value){
  if(spflag==1){
		printf("turn-left %d\n",(int)value*100);
	}else{
		printf("turn-left %.2lf\n",value);
	}
  motordrive(tirerf,sign_rf*value);
  motordrive(tirerb,sign_rb*value);//
  motordrive(tirelf,-sign_lf*value);
  motordrive(tirelb,-sign_lb*value);
}

void Stop(float value){
  value = 0;
  if(spflag==1){
		printf("stop %d\n",(int)value*100);
	}else{
		printf("stop %.2lf\n",value);
	}
  motordrive(tirerf,value);
  motordrive(tirerb,value);
  motordrive(tirelf,value);
  motordrive(tirelb,value);
}
