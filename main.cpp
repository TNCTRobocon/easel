#include "config.hpp"

int reccon[9];
int srid;
struct js_event ebuf;
struct js_event joysta;
int errnum=0;
int mcsp=mcmid;
float dtsp=dtmid;
float dttire=dtmid;
bool spflag{false};
int fd;

int main(){
	int i = 0;
	errno=0;
	for(i=0;i<9;i++) reccon[i]=0;
	//memset(reccon,0,sizeof(reccon));

	if(wiringPiSetup()==-1){//wPi_num
		printf("error winringPi setup\n");
		return 1;
	}else{
		printf("success wiringPi setup\n");
	}


	setupUART();
	setupcon();
	read(fd,&joysta,sizeof(joysta));
	ebuf=joysta;
	pinMode(sonic_1,OUTPUT);
	pinMode(sonic_2,OUTPUT);
	pinMode(lim_1,INPUT);
	pinMode(lim_2,INPUT);
	pinMode(lim_3,INPUT);
	pinMode(lim_4,INPUT);
	pinMode(lim_5,INPUT);
	pinMode(lim_6,INPUT);
	pinMode(lim_7,INPUT);
	pinMode(lim_8,INPUT);

//#if 0

	while(1){
		switch(getcon()){
			case BACK: //リセット
				if(reccon[BUTTON]&(1<<6)){
					serialPrintf(srid,"sel 0\r");
					delay(1);
					serialPrintf(srid,"reboot\r");
					delay(1);
					printf("all stop and reboot\n");
				}else{
					printf("completed\n");
				}
				break;
#if 0
			case LT: //左旋回
		  case RT: //右旋回
			case DX: //移動
			case DY: //移動
			if(reccon[RT] > highest){//RT_右旋回
				printf("right-turn\n");
			}else if(reccon[RT] < lowest){
					if(reccon[LT] > highest){//LT_左旋回
						printf("left-turn\n");
					}else if(reccon[LT] < lowest){
							if(reccon[DX] < lowest){//LSX_左進
								printf("left\n");
							}else if(reccon[DX] > highest){//LSX_右進
								printf("right\n");
							}else{
									if(reccon[DY] < lowest){//LSY_前進
										printf("flont\n");
									}else if(reccon[DY] > highest){//LSY_後進
										printf("back\n");
									}else{//停止
										printf("stop\n");
									}
							}
					}
			}
				break;
			case RSX: //
				break;
			case RSY: //
				break;
			case LSX: //
				break;
			case LSY: //
				break;
#endif

        case A: //後
          if(reccon[BUTTON]&(1<<0)){

            //Trapezoid(Back,0.2,500);
						//while(GetSonic(front_sonic)>0.000300);
						//serialPrintf(srid,"rst\r");

						/*std::stringstream ss;
						int a = 16;
				    ss << "sel 33\r";
						Write(ss.str());*/
//#if 0
						if(get_lim(lim_1)){
							printf("lim_1\n");
						}
						if(get_lim(lim_2)){
							printf("lim_2\n");
						}
						if(get_lim(lim_3)){
							printf("lim_3\n");
						}
						if(get_lim(lim_4)){
							printf("lim_4\n");
						}
						if(get_lim(lim_5)){
							printf("lim_5\n");
						}
						if(get_lim(lim_6)){
							printf("lim_6\n");
						}
						if(get_lim(lim_7)){
							printf("lim_7\n");
						}
						if(get_lim(lim_8)){
							printf("lim_8\n");
						}
						if(GetSonic(sonic_1)<0.001000){
							printf("sonic_1\n");
						}
						if(GetSonic(sonic_2)<0.001000){
							printf("sonic_2\n");
						}
//						#endif
          }else{
          }
          break;

        case B: //右
          if(reccon[BUTTON]&(1<<1)){//up
						/*printf("a\n");
						while(digitalRead(rbl_lim)==0);
						printf("b\n");
						*/
            //Trapezoid(Right,0.2,500);
						air_up();
						printf("b\n");
          }else{
          }
        break;

        case X: //左
          if(reccon[BUTTON]&(1<<2)){//down
            //Trapezoid(Left,0.2,500);
						air_down();
						printf("x\n");
          }else{
          }
          break;

        case Y: //前
          if(reccon[BUTTON]&(1<<3)){
            //Trapezoid(Front,0.2,500);
						air_clear();
						printf("y\n");
          }else{
          }
          break;

        case LB: //前
          if(reccon[BUTTON]&(1<<4)){
						TurnLeft(0.4);
            //Trapezoid(TurnLeft,0.4,500);
          }else{
						Stop(0);
          }
          break;

        case RB: //前
          if(reccon[BUTTON]&(1<<5)){
						TurnRight(0.4);
            //Trapezoid(TurnRight,0.4,500);
          }else{
						Stop(0);
          }
          break;

					case DX: //移動
					case DY: //移動
					if(reccon[RT] > highest){//RT_右旋回
						printf("right-turn\n");
					}else if(reccon[RT] < lowest){
							if(reccon[LT] > highest){//LT_左旋回
								printf("left-turn\n");
							}else if(reccon[LT] < lowest){
									if(reccon[DX] < lowest){//LSX_左進
										//Trapezoid(Left,0.4,500);
										Left(0.30);
										printf("left\n");
									}else if(reccon[DX] > highest){//LSX_右進
										//Trapezoid(Right,0.4,500);
										Right(0.30);
										printf("right\n");
									}else{
											if(reccon[DY] < lowest){//LSY_前進
												Front(0.30);
												printf("flont\n");
											}else if(reccon[DY] > highest){//LSY_後進
												Back(0.30);
												printf("back\n");
											}else{//停止
												Stop(0);
												printf("stop\n");
											}
									}
							}
					}
						break;

			case START: //
				if(reccon[BUTTON]&(1<<7)){
					//#if 0
					Trapezoid(Front,0.4,3000);
					Stop(0);
					delay(1000);
					Trapezoid(TurnRight,0.4,600);
					Stop(0);
					delay(1000);
					Front(0.15);
					//while(!get_lim(lim_5) && !get_lim(lim_6) && !get_lim(lim_7) && !get_lim(lim_8));
					delay(100);
					Stop(0);
					Trapezoid_fh(Back,0.3);
					while(GetSonic(sonic_1)>0.002000);
					//Trapezoid_sp(Back,0.3);
					Trapezoid_sh(Back,0.3);
					//while(!get_lim(lim_1) && !get_lim(lim_2) && !get_lim(lim_3) && !get_lim(lim_4));
					Stop(0);
					delay(1000);
					Trapezoid(Right,0.4,100);
					delay(1000);
					Trapezoid(Left,0.4,100);

					//#endif
					#if 0
					Trapezoid(Front,0.2,2000);
					Stop(0);
					delay(1000);
					Trapezoid(TurnLeft,0.4,500);
					Stop(0);
					delay(1000);
					Trapezoid_fh(Back,0.2);
					while(GetSonic(sonic_1)>0.005000);
					Trapezoid_sh(Back,0.2);
					Stop(0);
					#endif
				}else{}

			break;


			case MIDBUT:
				if(reccon[BUTTON]&(1<<8)){
					if(spflag){
            spflag=false;
            printf("dt change\n");
          }else{
            spflag=true;
            printf("mc change\n");
          }
				}else{}
				break;

		}
	}
//	#endif
}
