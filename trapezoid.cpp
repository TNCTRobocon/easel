//#include "trapezoid.hpp"
#include "config.hpp"
#include <stdio.h>

void Trapezoid(void (*func)(float),float max_value,unsigned int delay_time){
	double value;
	if(func==NULL){
		printf("func NULL\n");
		return;
	}
	if(max_value<0.15){
		printf("max_value low\n");
		return;
	}else if(max_value<0.3){
		for(value = 0.15;value<max_value;value+=0.0003){
			(*func)(value);
		}
		delay(delay_time);
		for(;value>0.14;value-=0.0003){
			(*func)(value);
		}
		(*func)(0);
	}else{
		for(value = 0.15;value<0.3;value+=0.0006){
			(*func)(value);
			printf("1\n");
		}
		for(;value<max_value-0.2;value+=0.0027){
			(*func)(value);
			printf("2\n");
		}
		for(;value<max_value;value+=0.0006){
			(*func)(value);
			printf("3\n");
		}
		delay(delay_time);
		for(;value>max_value-0.2;value-=0.0006){
			(*func)(value);
			printf("4\n");
		}
		for(;value>0.3;value-=0.0027){
			(*func)(value);
			printf("5\n");
		}
		for(;value>0.14;value-=0.0006){
			(*func)(value);
			printf("6\n");
		}
		(*func)(0);
	}
	printf("daikei\n");
}

void Trapezoid_fh(void (*func)(float),float max_value){
	double value;
	if(func==NULL){
		printf("func NULL\n");
		return;
	}
	if(max_value<0.15){
		printf("max_value low\n");
		return;
	}else if(max_value<0.3){
		for(value = 0.15;value<max_value;value+=0.0003){
			(*func)(value);
		}
	}else{
		for(value = 0.15;value<0.3;value+=0.0006){
			(*func)(value);
		}
		for(;value<max_value-0.2;value+=0.0027){
			(*func)(value);
		}
		for(;value<max_value;value+=0.0006){
			(*func)(value);
		}
	}
	printf("daikei_fh\n");
}

void Trapezoid_sh(void (*func)(float),float max_value){
	double value;
	if(func==NULL){
		printf("func NULL\n");
		return;
	}
	if(max_value<0.15){
		printf("max_value low\n");
		return;
	}else if(max_value<0.3){
		for(value=max_value;value>0.0;value-=0.0003){
			(*func)(value);
		}
		(*func)(0);
	}else{
		for(value=max_value;value>max_value-0.2;value-=0.0006){
			(*func)(value);
		}
		for(;value>0.3;value-=0.0027){
			(*func)(value);
		}
		for(;value>0.14;value-=0.0006){
			(*func)(value);
		}
		(*func)(0);
	}
	printf("daikei_sh\n");
}

void Trapezoid_sp(void (*func)(float),float max_value){
	double value;
	if(func==NULL){
		printf("func NULL\n");
		return;
	}
	if(max_value<0.15){
		printf("max_value low\n");
		return;
	}else if(max_value<0.35){
		for(value=max_value;value>0.15;value-=0.0003){
			printf("%f\n",value);
			(*func)(value);
		}
	}else{
		for(value=max_value;value>max_value-0.2;value-=0.0006){
			printf("%f\n",value);
			(*func)(value);
		}
		for(;value>0.3;value-=0.0027){
			(*func)(value);
		}
		for(;value>0.15;value-=0.0006){
			printf("%f\n",value);
			(*func)(value);
		}
	}
	printf("daikei_sp\n");
}
