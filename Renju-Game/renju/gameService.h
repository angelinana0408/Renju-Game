//�߼���
#ifndef _GAME_SERVICE_H_//��д���ⲿ�־ͽ�����
#define _GAME_SERVICE_H_

#include"model.h"


void initStatus();
int getStatus(const Point spPoint);
void setStatus(const Point spPoint);
int judge(Point spPoint);
int judgeDraw();

#endif //_GAMESERVICE_H_