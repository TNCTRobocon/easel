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
		for(value = 0.1;value<max_value;value+=0.0003){
			(*func)(value);
		}
		delay(delay_time);
		for(;value>0.1;value-=0.0003){
			(*func)(value);
		}
		(*func)(0);
	}else{
		for(value = 0.1;value<0.3;value+=0.0006){
			(*func)(value);
		}
		for(;value<max_value-0.2;value+=0.0027){
			(*func)(value);
		}
		for(;value<max_value;value+=0.0006){
			(*func)(value);
		}
		delay(delay_time);
		for(;value>max_value-0.2;value-=0.0006){
			(*func)(value);
		}
		for(;value>0.3;value-=0.0027){
			(*func)(value);
		}
		for(;value>0.1;value-=0.0006){
			(*func)(value);
		}
		(*func)(0);
	}
	printf("Trapezoid completed\n");
}

void TrapezoidFh(void (*func)(float),float max_value){
	double value;
	if(func==NULL){
		printf("func NULL\n");
		return;
	}
	if(max_value<0.15){
		printf("max_value low\n");
		return;
	}else if(max_value<0.3){
		for(value = 0.1;value<max_value;value+=0.0003){
			(*func)(value);
		}
	}else{
		for(value = 0.1;value<0.3;value+=0.0006){
			(*func)(value);
		}
		for(;value<max_value-0.2;value+=0.0027){
			(*func)(value);
		}
		for(;value<max_value;value+=0.0006){
			(*func)(value);
		}
	}
	printf("Trapezoid first half\n");
}

void TrapezoidSh(void (*func)(float),float max_value){
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
		for(;value>0.1;value-=0.0006){
			(*func)(value);
		}
		(*func)(0);
	}
	printf("Trapezoid second half\n");
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
	}else if(max_value<0.3){
		for(value=max_value;value>0.15;value-=0.0003){
			(*func)(value);
		}
	}else{
		for(value=max_value;value>max_value-0.2;value-=0.0006){
			(*func)(value);
		}
		for(;value>0.3;value-=0.0027){
			(*func)(value);
		}
		for(;value>0.15;value-=0.0006){
			(*func)(value);
		}
	}
	printf("Trapezoid special\n");
}
