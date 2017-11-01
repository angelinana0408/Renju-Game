//��ʾ��
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



void printChess()//function�����ݲ�ͬʱ�̵�״ֵ̬�������̣�״ֵ̬���ô��뺯����ͨ������getStatus�������ɣ�
{
	//��ʱ�洢ֻ�Ǵ����Ϊ�˱�����������
	int i, j;//ѭ��ʱ������ֵ
	char cA='A';//A�������ƺ�������
	int nStatus = STATUS_BLANK;//��ʱ״ֵ̬
	Point spPoint;//��ʱ�ṹ�壬Ϊ�������д��ݲ�����ʽ����
	
	//��ʶһ���¹��ܵĿ�ʼ
	printf("\n");
	printf("��������������������������������������\n");
	
	//���ƺ�����A-O
	printf("    ");//��ʽ����
	for(i = 0; i< 15; i++)
	{
		printf("%c ",cA+i);
	}
	printf("\n");

	//��������
	for(i = 0; i < 15; i++ )
	{
		printf(" %02d ", i);//����ָʾ������

		//������������״̬
		for(j = 0; j< 15; j++)
		{
			spPoint.row = i;
			spPoint.col = j;
			nStatus = getStatus(spPoint); //�õ��ĵ�״̬���Ա�������
			if(nStatus == STATUS_BLANK)
			{
				printf(CHESS_BLANK);//����һ���հ׽����
			}
			else if(nStatus == STATUS_BLAKE)
			{
				printf(CHESS_BLACK);//����һ������
			}
			else if(nStatus == STATUS_WHITE)
			{
				printf(CHESS_WHITE);//����һ������
			}
			
		}
		printf("\n");
	}
}

void inputPoint(Point *pspPoint)//function����ʾ�ķ��û����룬���ܲ������û���������������ʱ������
	//��Ϊ����ֻ�ܷ���һ��ֵ������Ҫ�뷵��pnRow,pnCol������ֵ����Ҫ��ָ����ά����
{
	char acPoint[8];	//������ȡ�û����������
	int nStatus = STATUS_BLANK;		//����״̬����ʼ��Ϊ�գ������������λ��ԭ����״̬
	int nColor;	//��ʱ����״ֵ̬��Ϊ��������࣬�ж�Ӧ���ķ�����
	while(TRUE)//TRUE����������
	{
		//�Դ˱�ʶ����ʾ�û�������
		printf("��������������������������������������\n");
		nColor = (*pspPoint).status;
		//����ִ�ӷ�����ʾ�û���������
		if(nColor == 0)
		{
			printf("black stone move, please input coordinate number<example:A0>:");

		}
		else if(nColor == 1)
		{
			printf("white stone move, please input coordinate number<example:A0>:");
		}

		//����û����������
		scanf("%s",acPoint);
		fflush(stdin);

		//�����û���������꣬��������ʱ�ṹ����
		(*pspPoint).col= toupper(acPoint[0])-'A';//toupper  to upper,���ַ�ת���ɴ�д��ĸ��ͷ�ļ�ctype
		//�ַ����ĵڶ�����ĸ��Ϊ���֣�ʹ��atoi��������ת��
		(*pspPoint).row = atoi(&acPoint[1]);//atoi to int ���ַ���ת��Ϊ�������������ת���򷵻�0��ͷ�ļ�stdlib

		//�ж�������к����к��Ƿ���Ч
		if((*pspPoint).row <0||(*pspPoint).row >14||(*pspPoint).col<0||(*pspPoint).col>14)
		{
			printf("The coordinate doesn't exist!\n");
			continue;
		}

		//��������״ֵ̬
		nStatus = getStatus(*pspPoint);

		//�ж�״̬
		if(nStatus != STATUS_BLANK)//״ֵ̬��Ϊ�գ��˴���������
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

void initApplication()//��ӭ�������������ݳ�ʼ��
{
	
	
	printf("��������������������������������������\n");
    printf("������Welcome to Renju !������\n");
    printf("��������������������������������������\n");

    printf("\n");

	initRanks();
}

int printMainMenu()//function:����˵��������û�����
{
	int choice;
	printf("��������������������������������������\n");	
    printf("1.Start 2.Save 3.Load 4.Rank\n"
			"5.Rules 6.about...    0.exit\n");
	printf("��������������������������������������\n");
    printf("Please select menu item number:");
	fflush(stdin);
	scanf("%d", &choice);
	return choice;

}

void playGame()//function:С��������������ʼ��Ϸ��������������
{
	int nStep = 0;
	int c;//�����û��Ƿ�����;�˳���Ϸ����Ϣ
	
	
	int nResult = JUDGE_PLAY;
	Point spPoint;//��ʱ����ĳ����Ϣ
	//��ʼ����Ϸ���� initStatus();
	//��������
	printChess();//�˺����ڲ�Ҳ������һ��spPoint��������޹�

	do//��ʼѭ������
	{
		
		spPoint.status = nStep%2;
		//����û����ӵ�
		inputPoint(&spPoint);//�ѽ����˴˵�״ֵ̬���������������˵�����꣬����ṹ����

		//����״ֵ̬,Ϊ��������������ã��ѽṹ���ڵ���Ϣ���������У���ʽ����
		setStatus(spPoint);

		//�������̣���getStatus���������еõ�������Ϣ��
		printChess();

		//���Ӳ���
		nStep++;

		nResult = judge(spPoint);

		//ȷ���û��Ƿ�����;�˳���Ϸ
		printf("Do you want to quit the game?<enter '0' to quit>:");
		scanf("%d",&c);
		fflush(stdin);
		if(0 == c)
		{
			break;
		}

	}while(nResult == JUDGE_PLAY);	//ѭ�����ӣ�����ʤʱ������ѭ��,FALSE����û����Ӯ��
	
	if(nResult == JUDGE_WIN)
	{
		printWinner(spPoint);
		printAddRank(nStep);//�Ƿ�Ҫ�������ң���Ҫ��浽�ڴ���
	}
	if(nResult == JUDGE_DRAW)
	{
		printDraw();
	}

}

void printWinner(const Point spPoint)
{
	if(spPoint.status == 0)//����ʤ��
	{
		 printf("����������������������\n");
		 printf("�� �� Black wins �� ��\n");
		 printf("����������������������\n");	
	}
	else if(spPoint.status == 1)//����ʤ��
	{
		 printf("����������������������\n");
		 printf("�� �� White wins �� ��\n");
		 printf("����������������������\n");	
	}
}

void printDraw()
{
	printf("����������������������\n");
    printf("�� �� Draw  Game �� ��\n");
    printf("����������������������\n");
}


void exitApplication()//�˳�����������������ڴ��ͷ�
{
	
	saveRanks();
	
	printf("\n");
	printf("��������������������������������������\n");
    printf("������G A M E  O V E R !������\n");
    printf("��������������������������������������\n");

}

void printAboutUs()
{
	printf("\n");
	printf("��������������������������������������\n");	
	printf("About the Renju game\n");
	printf("��������������������������������������\n");
	printf("  Renju game 1.0 Beta version\n"
		"Copyright@2013\n");
	printf("��������������������������������������\n");	
	printf("Enter any key to return...\n");
	getch();
	fflush(stdin);
}

void printGameRule()
{
	printf("\n");
	printf("��������������������������������������\n");
	printf("Game Rule\n");
	printf("��������������������������������������\n");
	printf("1.Renju is played by two players against each other.\n"
		"2.Black stone move first ,followed by white.\n"
		"3.Board:15x15.\n"
		"4.The winner is the first player to get an unbroken row of five stones.\n"
		"5.A draw occurs when both players will not get an unbroken row of stones.\n"
		"6.Columm numbers are letters,while row numbers are numeric.\n"
		"7.The player who selects black color stone moves first.\n"
		"8.Player can start game if select Start Game.\n"
		"9.Move stone: player input row & column number of cooresponding point, such as:A0.\n");
	printf("��������������������������������������\n");
	printf("Enter any key to return...\n");
	getch();//������������з�Ӧ�����Ҳ��ð��س�������getchar(),�����ַ���Ҫ���س�
	fflush(stdin);
}

void printAddRank(const int nStep)
{
	char acName[64];	//����û����������
	Rank srRank;	//������Ϣ�ṹ�������ʱ�ṹ��
	int nOrder = 0;

	//�ж�����
	nOrder =  judgeOrder(nStep);

	//�ж������Ƿ���10֮�ڣ��Ƿ�Ӧ�ü������а�
	if(nOrder <= 10)
	{
		printf("Congratulations!!! You have taken %d steps.\n",nStep);
		printf("��������������������������������������\n");
		printf("Please enter your name:");
		scanf("%s", &acName);
		strcpy(srRank.name, acName);
		srRank.step = nStep;

		//���������Ϣ����Ӯ���������뵽�����ṹ��������
		insertRank(nOrder-1, srRank);

	}

}

void printRanklist()
{
	const int nMaxSize = getRankSize();	//������а���Ӧ��������Ҹ���������û�д����ļ���������ң�
	int nSize = 0;	//ʵ�ʵ���Ҹ��������������ͨ����nMaxSize���
	Rank *psrRanks = NULL;	//����������飬��ʱ
	int nIndex = 0;

	printf("\n");
	printf("��������������������������������������\n");
	printf("Rank List\n");
	printf("��������������������������������������\n");  
	printf("Rank\tName\tSteps\n");

	psrRanks = (Rank*)malloc(sizeof(Rank) * nMaxSize);
	//��ʼ���¿ռ䣬ȫ����ֵΪ0
	memset(psrRanks, 0, sizeof(Rank) * nMaxSize);

	//�������б�
	 nSize =  getRanks(psrRanks, nMaxSize);//����ʽ�ṹ�������е����ݷŵ���ʱ�ṹ��������

	 //�����������
	 for(nIndex = 0; nIndex < nMaxSize; nIndex++)
	 {
		Rank *psrRank = &psrRanks[nIndex];
		printf("  %d\t%s\t%d\n", nIndex +1, psrRank->name, psrRank->step);
	 }

	 //�ͷ��ڴ�ռ�
	 free(psrRanks);

	 printf("��������������������������������������\n");
	 printf("Enter any key to return\n");
	 getch();
	 fflush(stdin);

}