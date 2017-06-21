#ifndef CONTROL
#define CONTROL

#include"animal.h"

extern Animal lion;

extern POINT pt;

struct mob 
{
	float x;
	float y;
	bool movecheck;
	bool hitcheck;
};




void Control();
void Hit();

#endif 

