//表示层
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include"global.h"
#include"gameService.h"
#include"model.h"
#include"rankService.h"
//extern int AnChessStatus[15][15];

void printWinner(const Point spPoint);
void printDraw();
void playGame();
void printChess();
void inputPoint(Point *spPoint);
void initApplication();
int printMainMenu();
void printAddRank(const int nStep);



void printChess()//function：根据不同时刻的状态值绘制棋盘（状态值不用传入函数，通过调用getStatus函数即可）
{
	//临时存储只是搭建桥梁为了保存在数组里
	int i, j;//循环时的索引值
	char cA='A';//A用来绘制横向坐标
	int nStatus = STATUS_BLANK;//临时状态值
	Point spPoint;//临时结构体，为了向函数中传递参数形式整洁
	
	//标识一个新功能的开始
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━\n");
	
	//绘制横坐标A-O
	printf("    ");//格式美观
	for(i = 0; i< 15; i++)
	{
		printf("%c ",cA+i);
	}
	printf("\n");

	//绘制棋盘
	for(i = 0; i < 15; i++ )
	{
		printf(" %02d ", i);//绘制指示纵坐标

		//绘制棋盘坐标状态
		for(j = 0; j< 15; j++)
		{
			spPoint.row = i;
			spPoint.col = j;
			nStatus = getStatus(spPoint); //得到改点状态，以便绘出棋子
			if(nStatus == STATUS_BLANK)
			{
				printf(CHESS_BLANK);//绘制一个空白交叉点
			}
			else if(nStatus == STATUS_BLAKE)
			{
				printf(CHESS_BLACK);//绘制一个黑子
			}
			else if(nStatus == STATUS_WHITE)
			{
				printf(CHESS_WHITE);//绘制一个白子
			}
			
		}
		printf("\n");
	}
}

void inputPoint(Point *pspPoint)//function：提示哪方用户输入，接受并解析用户输入的坐标放入临时数组中
	//因为函数只能返回一个值，所以要想返回pnRow,pnCol这两个值，需要用指针或二维数组
{
	char acPoint[8];	//用来获取用户输入的坐标
	int nStatus = STATUS_BLANK;		//坐标状态，初始化为空，用来接收这个位置原来的状态
	int nColor;	//临时代表状态值，为了描述简洁，判断应该哪方输入
	while(TRUE)//TRUE代表能下子
	{
		//以此标识，提示用户的输入
		printf("┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		nColor = (*pspPoint).status;
		//根据执子方，提示用户输入坐标
		if(nColor == 0)
		{
			printf("black stone move, please input coordinate number<example:A0>:");

		}
		else if(nColor == 1)
		{
			printf("white stone move, please input coordinate number<example:A0>:");
		}

		//获得用户输入的坐标
		scanf("%s",acPoint);
		fflush(stdin);

		//解析用户输入的坐标，并放入临时结构体中
		(*pspPoint).col= toupper(acPoint[0])-'A';//toupper  to upper,将字符转换成大写字母，头文件ctype
		//字符串的第二个字母后为数字，使用atoi函数进行转换
		(*pspPoint).row = atoi(&acPoint[1]);//atoi to int 将字符串转换为整数，如果不能转换则返回0，头文件stdlib

		//判断输入的行号与列号是否有效
		if((*pspPoint).row <0||(*pspPoint).row >14||(*pspPoint).col<0||(*pspPoint).col>14)
		{
			printf("The coordinate doesn't exist!\n");
			continue;
		}

		//获得坐标的状态值
		nStatus = getStatus(*pspPoint);

		//判断状态
		if(nStatus != STATUS_BLANK)//状态值不为空，此处已有棋子
		{
			printf("This coordinate has been occupied!\n");
			continue;
		}
		else
		{
			break;
		}
	}

}

void initApplication()//欢迎界面的输出，数据初始化
{
	
	
	printf("┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒\n");
    printf("○●○●○Welcome to Renju !●○●○●\n");
    printf("┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖\n");

    printf("\n");

	initRanks();
}

int printMainMenu()//function:输出菜单，接受用户输入
{
	int choice;
	printf("━━━━━━━━━━━━━━━━━━━\n");	
    printf("1.Start 2.Save 3.Load 4.Rank\n"
			"5.Rules 6.about...    0.exit\n");
	printf("┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
    printf("Please select menu item number:");
	fflush(stdin);
	scanf("%d", &choice);
	return choice;

}

void playGame()//function:小主函数，包含开始游戏的整个主干流程
{
	int nStep = 0;
	int c;//接受用户是否想中途退出游戏的信息
	
	
	int nResult = JUDGE_PLAY;
	Point spPoint;//临时储存某点信息
	//初始化游戏数据 initStatus();
	//绘制棋盘
	printChess();//此函数内部也定义了一个spPoint，但与此无关

	do//开始循环下子
	{
		
		spPoint.status = nStep%2;
		//获得用户下子点
		inputPoint(&spPoint);//已建立了此点状态值，下面是来建立此点的坐标，放入结构体中

		//设置状态值,为了下面更新棋盘用，把结构体内的信息放入数组中，正式保存
		setStatus(spPoint);

		//更新棋盘（先getStatus，从数组中得到棋子信息）
		printChess();

		//增加步数
		nStep++;

		nResult = judge(spPoint);

		//确认用户是否想中途退出游戏
		printf("Do you want to quit the game?<enter '0' to quit>:");
		scanf("%d",&c);
		fflush(stdin);
		if(0 == c)
		{
			break;
		}

	}while(nResult == JUDGE_PLAY);	//循环下子，当获胜时则跳出循环,FALSE代表还没出现赢家
	
	if(nResult == JUDGE_WIN)
	{
		printWinner(spPoint);
		printAddRank(nStep);//是否要存入此玩家，需要则存到内存中
	}
	if(nResult == JUDGE_DRAW)
	{
		printDraw();
	}

}

void printWinner(const Point spPoint)
{
	if(spPoint.status == 0)//黑子胜出
	{
		 printf("┏━━━━━━━━━┓\n");
		 printf("┃ ○ Black wins ○ ┃\n");
		 printf("┗━━━━━━━━━┛\n");	
	}
	else if(spPoint.status == 1)//白子胜出
	{
		 printf("┏━━━━━━━━━┓\n");
		 printf("┃ ● White wins ● ┃\n");
		 printf("┗━━━━━━━━━┛\n");	
	}
}

void printDraw()
{
	printf("┏━━━━━━━━━┓\n");
    printf("┃ ● Draw  Game ○ ┃\n");
    printf("┗━━━━━━━━━┛\n");
}


void exitApplication()//退出界面的输出，清除，内存释放
{
	
	saveRanks();
	
	printf("\n");
	printf("┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒┒\n");
    printf("○●○●○G A M E  O V E R !●○●○●\n");
    printf("┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖┖\n");

}

void printAboutUs()
{
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━\n");	
	printf("About the Renju game\n");
	printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
	printf("  Renju game 1.0 Beta version\n"
		"Copyright@2013\n");
	printf("┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");	
	printf("Enter any key to return...\n");
	getch();
	fflush(stdin);
}

void printGameRule()
{
	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━\n");
	printf("Game Rule\n");
	printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");
	printf("1.Renju is played by two players against each other.\n"
		"2.Black stone move first ,followed by white.\n"
		"3.Board:15x15.\n"
		"4.The winner is the first player to get an unbroken row of five stones.\n"
		"5.A draw occurs when both players will not get an unbroken row of stones.\n"
		"6.Columm numbers are letters,while row numbers are numeric.\n"
		"7.The player who selects black color stone moves first.\n"
		"8.Player can start game if select Start Game.\n"
		"9.Move stone: player input row & column number of cooresponding point, such as:A0.\n");
	printf("┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
	printf("Enter any key to return...\n");
	getch();//按任意键都会有反应，而且不用按回车，不像getchar(),按完字符还要按回车
	fflush(stdin);
}

void printAddRank(const int nStep)
{
	char acName[64];	//获得用户输入的姓名
	Rank srRank;	//排名信息结构体对象，临时结构体
	int nOrder = 0;

	//判断排名
	nOrder =  judgeOrder(nStep);

	//判断排名是否在10之内，是否应该加入排行榜
	if(nOrder <= 10)
	{
		printf("Congratulations!!! You have taken %d steps.\n",nStep);
		printf("┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
		printf("Please enter your name:");
		scanf("%s", &acName);
		strcpy(srRank.name, acName);
		srRank.step = nStep;

		//添加排名信息，把赢家真正放入到排名结构体数组中
		insertRank(nOrder-1, srRank);

	}

}

void printRanklist()
{
	const int nMaxSize = getRankSize();	//获得排行榜中应该已有玩家个数（包括没有存入文件的新增玩家）
	int nSize = 0;	//实际的玩家个数，正常情况，通常与nMaxSize相等
	Rank *psrRanks = NULL;	//获得排名数组，临时
	int nIndex = 0;

	printf("\n");
	printf("━━━━━━━━━━━━━━━━━━━\n");
	printf("Rank List\n");
	printf("┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n");  
	printf("Rank\tName\tSteps\n");

	psrRanks = (Rank*)malloc(sizeof(Rank) * nMaxSize);
	//初始化新空间，全部赋值为0
	memset(psrRanks, 0, sizeof(Rank) * nMaxSize);

	//获得玩家列表
	 nSize =  getRanks(psrRanks, nMaxSize);//将正式结构体数组中的内容放到临时结构体数组中

	 //获得排名数组
	 for(nIndex = 0; nIndex < nMaxSize; nIndex++)
	 {
		Rank *psrRank = &psrRanks[nIndex];
		printf("  %d\t%s\t%d\n", nIndex +1, psrRank->name, psrRank->step);
	 }

	 //释放内存空间
	 free(psrRanks);

	 printf("┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄\n");
	 printf("Enter any key to return\n");
	 getch();
	 fflush(stdin);

}