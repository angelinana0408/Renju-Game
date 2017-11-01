//数据结构定义，定义结构体
#ifndef _MODEL_H_
#define _MODEL_H_
//坐标点的状态类型   枚举类型

enum PointStatus
{
	STATUS_BLANK = -1,
	STATUS_BLAKE = 0,
	STATUS_WHITE = 1
};

//坐标点数据
typedef struct Point
{
	int row;
	int col;
	int status;
}Point;


// 排名数组结构
typedef struct Rank
{
	char name[64];	//胜利者姓名
	int step;	//胜利时所用的步数
}Rank;

#endif