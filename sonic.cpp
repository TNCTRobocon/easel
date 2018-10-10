//#include "sonic.hpp"
#include "config.hpp"

double Sonic(int pin_num){
	struct timeval begin,end;
	bool time_flag = false;
	int count = 0;
	pinMode(pin_num,OUTPUT);
	digitalWrite(pin_num,1);
	pinMode(pin_num,INPUT);
	delayMicroseconds(750);
	while(digitalRead(pin_num)!=1){
		delayMicroseconds(1);
		count++;
		if(count>20000){
			time_flag = true;
			break;
		}
	}
	gettimeofday(&begin,nullptr);
	while(digitalRead(pin_num)!=0){};
	gettimeofday(&end,nullptr);
	//std::cout << end.tv_sec << " " << begin.tv_sec << " " << end.tv_usec << " " << begin.tv_usec << std::endl;
	if(!time_flag){
		return (double)((end.tv_sec-begin.tv_sec)+(end.tv_usec-begin.tv_usec)*1.0E-6);
	}else{
		return -1;
	}
	//19.455ms
}

double GetSonic(int pin_num){
	double _time = Sonic(pin_num);
	while(_time==-1){
		delay(70);
		_time = Sonic(pin_num);
	}
	//printf("%lf\n",_time);
	return _time;
}
