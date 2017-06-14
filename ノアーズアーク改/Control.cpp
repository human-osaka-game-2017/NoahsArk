#include "Mouse.h"
#include "GameScene.h"
#include "animal.h"

Animal rion={100.f,400.f,true};
void Control() {
	 MouseCheck(&g_Mouse);
	rion.x += MOVESPEED;
	if (rion.x > g_Mouse.dim_x&&rion.y > g_Mouse.dim_y) {
		rion.x += -5.0f;
	}
}