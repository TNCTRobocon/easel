//19.25v
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

void PinSetup();

void sig_catch(int sig){
	pinMode(sonic_1,OUTPUT);
	digitalWrite(sonic_1,0);
	pinMode(sonic_2,OUTPUT);
	digitalWrite(sonic_2,0);
	serialPrintf(srid,"sel 33\r");
	serialPrintf(srid,"clear\r");
	serialPrintf(srid,"sel 0\r");
	serialPrintf(srid,"dt 0\r");
	serialPrintf(srid,"sel 0\r");
	serialPrintf(srid,"mc 0\r");
	printf("all reset\n");
	air_clear();
	exit(1);
}

int main(){
	puts("\n/////////////////////////\nleftrobo program start\n/////////////////////////");
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

	PinSetup();
	air_clear();
	if(SIG_ERR == signal(SIGTERM,sig_catch)){//SIGTERMに戻す
		printf("failed to set signal handler\n");
		exit(1);
	}
//#if 0
	/*robot 左*/
//#if 0

	//1.二段テーブルまで移動
	std::cout << "1.二段テーブルまで移動" << std::endl;
	delay(500);
	//ちょっと右に進み
	Right(0.15);
	delay(2000); //要調整
	//止まる
	Stop(0);
	delay(200);
	//前進して
	Trapezoid(Front,0.4,5200); //要調整
	//止まる
	Stop(0);
	delay(100);
	//左旋回して
	Trapezoid(TurnLeft,0.4,500); //要調整
	//止まる
	Stop(0);
	delay(100);
	//壁に向かって前進して
	Front(0.15);
	//壁に当たったら
	while(( !get_lim(lim_5) && !get_lim(lim_6) ) || ( !get_lim(lim_7) && !get_lim(lim_8) ));
	//ちょっと壁に押し付けて
	delay(100);
	//止まる
	Stop(0);
	delay(100);
	//二段テーブルに向かって後進して
	Trapezoid_fh(Back,0.4);
	//二段テーブルに近づいたら
	while(GetSonic(sonic_1)>0.004000 && GetSonic(sonic_2)>0.004000);
	//減速
	Trapezoid_sp(Back,0.4);
	//二段テーブルに当たったら
	while(( !get_lim(lim_1) || !get_lim(lim_2) ) && ( !get_lim(lim_3) || !get_lim(lim_4) ));
	//ちょっと二段テーブルに押し付けて
	//delay(100); //要調整
	//止まる
	Stop(0);
	delay(200);
//#endif

	//2.ゼロ点合わせ
	std::cout << "2.ゼロ点合わせ" << std::endl;

	//二段テーブルから遠ざかるように前進
	Front(0.15);
	//ある程度離れたら
	while(GetSonic(sonic_2)<0.000500); //要調整 100mm程度
	//止まる
	Stop(0);
	delay(100);
	//左に進み
	Left(0.15);
	//右の超音波センサが反応したら
	while(GetSonic(sonic_1)>0.002000); //要調整
	//止まる
	Stop(0);
	delay(200);

	//3.左射出
	std::cout << "3.左射出" << std::endl;

	//右に進み
	Right(0.15);
	delay(5200); //要調整
	//止まる
	Stop(0);
	delay(400);
	//エアーで手動を上げる
	air_up();
	//待つ  //この間に手動は左射出
	delay(7000); //要調整

	//4.ゼロ点合わせ
	std::cout << "4.ゼロ点合わせ" << std::endl;

	//左に進み
	Left(0.15);
	//右の超音波センサが反応したら
	while(GetSonic(sonic_1)>0.002000); //要調整

	//5.右射出
	std::cout << "5.右射出" << std::endl;

	//少し左に進み
	Left(0.15);
	delay(4200); //要調整
	//止まる
	Stop(0);
	//待つ  //この間に手動は右射出
	delay(7000); //要調整

	//6.ゼロ点合わせ
	std::cout << "6.ゼロ点合わせ" << std::endl;

	//右に進み
	Right(0.15);
	//右の超音波センサが反応しなくなったら
	while(GetSonic(sonic_1)<0.002000); //要調整
	//止まる
	Stop(0);
	delay(1200);

	//7.振り子＆なだれ
	std::cout << "7.振り子＆なだれ" << std::endl;

	//左に進み
	Left(0.15);
	delay(200); //要調整
	//止まる
	Stop(0);
	//この後に手動は振り子、なだれ

/*
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

        case A:
          if(reccon[BUTTON]&(1<<0)){
						Front(0.15);
						while(GetSonic(sonic_1)<0.000380);
						Stop(0);
          }else{
          }
          break;

        case B:
          if(reccon[BUTTON]&(1<<1)){//up
						air_up();
						printf("b\n");
          }else{
          }
        break;

        case X:
          if(reccon[BUTTON]&(1<<2)){//down
						air_down();
						printf("x\n");
          }else{
          }
          break;

        case Y:
          if(reccon[BUTTON]&(1<<3)){
						air_clear();
						printf("y\n");
          }else{
          }
          break;

        case LB:
          if(reccon[BUTTON]&(1<<4)){
						TurnLeft(0.4);
          }else{
						Stop(0);
          }
          break;

        case RB:
          if(reccon[BUTTON]&(1<<5)){
						TurnRight(0.4);
          }else{
						Stop(0);
          }
          break;

					case DX:
					case DY:
					if(reccon[RT] > highest){//RT_右旋回
						printf("right-turn\n");
					}else if(reccon[RT] < lowest){
							if(reccon[LT] > highest){//LT_左旋回
								printf("left-turn\n");
							}else if(reccon[LT] < lowest){
									if(reccon[DX] < lowest){//DX_左進
										Left(0.15);
										printf("left\n");
									}else if(reccon[DX] > highest){//DX_右進
										Right(0.15);
										printf("right\n");
									}else{
											if(reccon[DY] < lowest){//DY_前進
												Front(0.15);
												printf("flont\n");
											}else if(reccon[DY] > highest){//DY_後進
												Back(0.15);
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
					//1.二段テーブルまで移動
					std::cout << "1.二段テーブルまで移動" << std::endl;
					delay(500);
					//ちょっと右に進み
					Right(0.15);
					delay(2000); //要調整
					//止まる
					Stop(0);
					delay(200);
					//前進して
					Trapezoid(Front,0.4,4500); //要調整
					//止まる
					Stop(0);
					delay(100);
					//左旋回して
					Trapezoid(TurnLeft,0.4,370); //要調整
					//止まる
					Stop(0);
					delay(100);
					//壁に向かって前進して
					Front(0.15);
					//壁に当たったら
					while(( !get_lim(lim_5) && !get_lim(lim_6) ) || ( !get_lim(lim_7) && !get_lim(lim_8) ));
					//止まる
					Stop(0);
					delay(100);
					//二段テーブルに向かって後進して
					Trapezoid_fh(Back,0.4);
					//二段テーブルに近づいたら
					while(GetSonic(sonic_1)>0.004000 && GetSonic(sonic_2)>0.004000);
					//減速
					Trapezoid_sp(Back,0.4);
					//二段テーブルに当たったら
					while(( !get_lim(lim_1) || !get_lim(lim_2) ) && ( !get_lim(lim_3) || !get_lim(lim_4) ));
					//ちょっと二段テーブルに押し付けて
					delay(200); //要調整
					//止まる
					Stop(0);
					delay(200);
				//#endif

					//2.ゼロ点合わせ
					std::cout << "2.ゼロ点合わせ" << std::endl;

					//二段テーブルから遠ざかるように前進
					Front(0.15);
					//ある程度離れたら
					while(GetSonic(sonic_2)<0.000500); //要調整 100mm程度
					//止まる
					Stop(0);
					delay(100);
					//左に進み
					Left(0.15);
					//右の超音波センサが反応したら
					while(GetSonic(sonic_1)>0.002000); //要調整
					//止まる
					Stop(0);
					delay(200);

					//3.左射出
					std::cout << "3.左射出" << std::endl;

					//右に進み
					Right(0.15);
					delay(4500); //要調整
					//止まる
					Stop(0);
					delay(400);
					//エアーで手動を上げる
					air_up();
					//待つ  //この間に手動は左射出
					delay(3500); //要調整

					//4.ゼロ点合わせ
					std::cout << "4.ゼロ点合わせ" << std::endl;

					//左に進み
					Left(0.15);
					//右の超音波センサが反応したら
					while(GetSonic(sonic_1)>0.002000); //要調整

					//5.右射出
					std::cout << "5.右射出" << std::endl;

					//少し左に進み
					Left(0.15);
					delay(3000); //要調整
					//止まる
					Stop(0);
					//待つ  //この間に手動は右射出
					delay(3500); //要調整

					//6.ゼロ点合わせ
					std::cout << "6.ゼロ点合わせ" << std::endl;

					//右に進み
					Right(0.15);
					//右の超音波センサが反応しなくなったら
					while(GetSonic(sonic_1)<0.002000); //要調整
					//止まる
					Stop(0);
					delay(1200);

					//7.振り子＆なだれ
					std::cout << "7.振り子＆なだれ" << std::endl;

					//左に進み
					Left(0.15);
					delay(400); //要調整
					//止まる
					Stop(0);
					//この後に手動は振り子、なだれ
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
	*/
}

void PinSetup(){
	pinMode(sonic_1,OUTPUT);
	digitalWrite(sonic_1,0);
	pinMode(sonic_2,OUTPUT);
	digitalWrite(sonic_2,0);
	pinMode(lim_1,INPUT);
	pinMode(lim_2,INPUT);
	pinMode(lim_3,INPUT);
	pinMode(lim_4,INPUT);
	pinMode(lim_5,INPUT);
	pinMode(lim_6,INPUT);
	pinMode(lim_7,INPUT);
	pinMode(lim_8,INPUT);
}
