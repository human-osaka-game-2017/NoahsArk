#ifndef MOLE
#define MOLE
#include "char.h"

#define MOVESPEEDMOLE 2.f

extern Animal mole;

extern CUSTOMVERTEX drawmole[4];

void moledraw(int time);

extern bool g_MoveMole;

extern bool MolePlusSpeed;

//���O���������Ă��邩����ł��邩
extern bool MoleDeadFlg;



#define MOLE_W 55.f
#define MOLE_H 55.f

#endif 

