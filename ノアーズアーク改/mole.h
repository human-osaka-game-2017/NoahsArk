#ifndef MOLE
#define MOLE
#include "char.h"

#define MOVESPEEDMOLE 2.f

extern Animal mole;
extern Animal mole2;

extern CUSTOMVERTEX drawmole[4];
extern CUSTOMVERTEX drawmole2[4];

void moledraw(int time);

extern bool g_MoveMole;

extern bool MolePlusSpeed;

//ƒ‚ƒOƒ‰‚ª¶‚«‚Ä‚¢‚é‚©€‚ñ‚Å‚¢‚é‚©
extern bool MoleDeadFlg;



#define MOLE_W 78.f
#define MOLE_H 52.f

#endif 

