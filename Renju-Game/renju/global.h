//全局宏定义,许多文件都会用到的参数

#ifndef _GLOBAL_H_//大写的这部分就叫做宏
#define _GLOBAL_H_
//棋子的状态值
/*#define STATUS_BLANK -1
#define STATUS_BLAKE 0
#define STATUS_WHITE 1
*/
//定义棋子符号
#define CHESS_BLANK "╋"//空格图标，占4个char @@@常量数组,字符串要用引号,数组的[]不能写
#define CHESS_BLACK "○"
#define CHESS_WHITE "●"

#define TRUE 1
#define FALSE 0

#define JUDGE_PLAY 0
#define JUDGE_WIN 1
#define JUDGE_DRAW 2

//extern int AnChessStatus[15][15];//全局二维数组，定数组，真正记录各点状态.include一次就定义一次，加extern防止重定义


#endif //_GLOBAL_H_