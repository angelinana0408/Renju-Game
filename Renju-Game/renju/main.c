//表示层
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"gameService.h"
#include"gameFile.h"

int AnChessStatus[15][15];//全局二维数组，定数组，真正记录各点状态


int main()
{
	int choice;
	initApplication();
	do
		{	
			choice=printMainMenu();
            switch(choice)
			{
            case 1://开始游戏
				//design interface,screen clear,put item,loop,hint next step,calcu,tell win,put winner into link,put link to txt
				{
					//初始化游戏数据 
					initStatus();
					//开始游戏
					playGame();
				}
				break;
            case 2://put current interface to txt
				{
					if(1 == saveChess())//只能存一次档
					{
						printf("Succeed to save!\n");
					}
					else
					{
						printf("Failed to save!\n");
					}
				}
				break;
			case 3://read interface from txt
				{
					readChess();
					playGame();
				}
				break;
			case 4://display the link
				{
					printRanklist();
				}
				break;
			case 5://游戏规则
				{
					printGameRule();
				}
				break;
			case 6://关于我们
				{
					printAboutUs();
				}
				break;
            case 0:
				{//release();
				 exitApplication();
				 }
				break;
            default :
				{
				printf("Invalid item,enter again!\n");
				}
				break;
            }
        }while(choice != 0);
	
	system("pause");
    return 0;
}
