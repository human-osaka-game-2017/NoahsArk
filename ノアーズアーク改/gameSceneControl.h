#ifndef GAMESCENECONTROL
#define GAMESCENECONTROL

enum {
	TITLESCENE,
	GEMESELECTION,
	STAGEONE,
	STAGETWO,
	STAGETHREE,
	STAGEFOUR,
	GAMECLEAR,
	GAMEOVER,
	END
};
void sceneControl();
void  pictureDraw();
extern int scene;
#endif 

