//��ʾ��
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"gameService.h"
#include"gameFile.h"

int AnChessStatus[15][15];//ȫ�ֶ�ά���飬�����飬������¼����״̬


int main()
{
	int choice;
	initApplication();
	do
		{	
			choice=printMainMenu();
            switch(choice)
			{
            case 1://��ʼ��Ϸ
				//design interface,screen clear,put item,loop,hint next step,calcu,tell win,put winner into link,put link to txt
				{
					//��ʼ����Ϸ���� 
					initStatus();
					//��ʼ��Ϸ
					playGame();
				}
				break;
            case 2://put current interface to txt
				{
					if(1 == saveChess())//ֻ�ܴ�һ�ε�
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
			case 5://��Ϸ����
				{
					printGameRule();
				}
				break;
			case 6://��������
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
