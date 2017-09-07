#ifndef GAMESCENECONTROL
#define GAMESCENECONTROL

enum {
	NONE,
	TITLESCENE,
	GEMESELECTION,
	STAGEONE,
	STAGETWO,
	STAGETHREE,
	STAGEFOUR,
	STAGEFIVE,
	STAGESIX,
	STAGESEVEN,
	STAGEEIGHT,
	GAMECLEAR,
	GAMEOVER,
	END
};
void sceneControl();
void  pictureDraw();
extern int scene;
extern int nextStage;
extern int currentStage;
extern float stageProgres;
#endif 

