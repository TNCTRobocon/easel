#pragma once

#define tirerf 16 //タイヤ右前
#define tirelf 17 //タイヤ左前
#define tirerb 18 //タイヤ右後
#define tirelb 19 //タイヤ左後

#define mcmax 165 //mc
#define mcmid 100
#define mcmin 40
#define dtmax 0.7 //dt
#define dtmid 0.5
#define dtmin 0.2
#define lowest -8192 //border
#define highest 8192

#define sonic_1 0//27
#define sonic_2 2
#define lim_1 1//18
#define lim_2 4//23
#define lim_3 5
#define lim_4 6
#define lim_5 10
#define lim_6 11
#define lim_7 26
#define lim_8 27

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringSerial.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <linux/joystick.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include <iostream>
#include <sstream>

#include "controller.hpp"
#include "motor.hpp"
#include "move.hpp"
#include "sonic.hpp"
#include "trapezoid.hpp"
#include "uart.hpp"
#include "write.hpp"
#include "limitswitch.hpp"
#include "air.hpp"

extern int reccon[9];
extern int srid;
extern int errnum;
extern struct js_event ebuf;
extern struct js_event joysta;
extern int mcsp;
extern float dtsp;
extern float dttire;
extern bool spflag; //dt:false mc:true
/*bool btflag{true};//許可:true 禁止:false
bool aflag,bflag,xflag,yflag{false};//許可:true 禁止:false
*/
extern int fd;//game pad file id;
