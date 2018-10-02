#pragma once

enum{LSX,LSY,RSX,RSY,RT,LT,DX,DY,BUTTON,A=10,B,X,Y,LB,RB,BACK,START,MIDBUT,LS,RS};

void SetupCon();
void DeinitCon();
unsigned char GetCon();
