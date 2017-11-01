//逻辑层
#ifndef _GAME_SERVICE_H_//大写的这部分就叫做宏
#define _GAME_SERVICE_H_

#include"model.h"


void initStatus();
int getStatus(const Point spPoint);
void setStatus(const Point spPoint);
int judge(Point spPoint);
int judgeDraw();

#endif //_GAMESERVICE_H_