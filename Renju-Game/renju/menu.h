//表示层(还需要被其他.c文件用到的menu.c中的函数要在此定义)

#ifndef _MENU_H_//大写的这部分就叫做宏
#define _MENU_H_

void initApplication();
void exitApplication();
int printMainMenu();
void playGame();
void printAboutUs();
void printGameRule();
void printRanklist();

#endif //_MENU_H_