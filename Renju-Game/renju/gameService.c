//�߼���
#include<stdio.h>
#include"global.h"
#include"model.h"

extern int AnChessStatus[15][15];//ȫ�ֶ�ά���飬�����飬������¼����״̬,extern �����������
//@@@@@@@@@@@@@@@@@@@@@���ֺ�����@@@@@@@@@@@@@@@@@@@@@@
void initStatus()//function����ʼ�����̸���λ�õ�״ֵ̬
{
	
	int i,j;//�к��к�����ֵ

	//��ʼ��״ֵ̬��ʹ��˫��ѭ��������ά����
	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 15; j++)
		{
			AnChessStatus[i][j]=STATUS_BLANK;
		}
	}
}
//set get һ���ǳɶԳ���
int getStatus(const Point spPoint)//function������״̬��ά����
	//��const��ʾ�����޸���ֵ
{
	return AnChessStatus[spPoint.row][spPoint.col];
}

void setStatus(const Point spPoint)//function����״ֵ̬�����ά����Ķ�Ӧλ��
{
	AnChessStatus[spPoint.row][spPoint.col] = spPoint.status;
}


//@@@@@@@@@@@@@@@@@@@@@ʤ���ж�@@@@@@@@@@@@@@@@@@@@@@

int judgeHorizontal(const Point spPoint)
{
	int i,j;
	int counter = 1;
	//����
	j = spPoint.col-1;
	i = spPoint.row;
	while(j >= 0)
	{
		if(AnChessStatus[i][j--] == spPoint.status)
		{
			counter ++;
		}
		else
		{
			break;
		}
	}
	j = spPoint.col + 1;
	while(j <= 14)
	{
		if(AnChessStatus[i][j++] == spPoint.status)
		{
			counter ++;
		}
		else
		{
			break;
		}
	}
	return 	counter;

}

int judgeVertical(const Point spPoint)
{
	int i,j;
	int counter = 1;
	//����
	j = spPoint.col;
	i = spPoint.row-1;
	while(i >= 0)
	{
		if(AnChessStatus[i--][j] == spPoint.status)
		{
			counter ++;
		}
		else
		{
			break;
		}
	}
	i =  spPoint.row + 1;
	while(i <= 14)
	{
		if(AnChessStatus[i++][j] == spPoint.status)
		{
			counter ++;
		}
		else
		{
			break;
		}
	}
	return 	counter;

}

int judgeHyperphoria(const Point spPoint)
{
	int i,j;
	int counter = 1;
	//�Խ��ߣ�����-���ϣ�
	j = spPoint.col+1;
	i = spPoint.row-1;
	while((i >= 0)&&(j <= 14))
	{
		if(AnChessStatus[i--][j++] == spPoint.status)
		{
			counter ++;
		}
		else
		{
			break;
		}
	}
	j = spPoint.col-1;
	i = spPoint.row+1;
	while((i <= 14)&&(j >= 0))
	{
		if(AnChessStatus[i++][j--] == spPoint.status)
		{
			counter ++;
		}
		else
		{
			break;
		}
	}
	return 	counter;

}

int judgeHypophoria(const Point spPoint)
{
	int i,j;
	int counter = 1;
	//��б������-���£�
	j = spPoint.col-1;
	i = spPoint.row-1;
	while((i >= 0)&&(j  >= 0))
	{
		if(AnChessStatus[i--][j--] == spPoint.status)
		{
			counter ++;
		}
		else
		{
			break;
		}
	}
	j = spPoint.col+1;
	i = spPoint.row+1;
	while((i <= 14)&&(j <= 14))
	{
		if(AnChessStatus[i++][j++] == spPoint.status)
		{
			counter ++;
		}
	
		
		else
		{
			break;
		}
	}
	return 	counter;

}

int judgeDraw()
{
	int i,j;
	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 15; j++)
		{
			if(AnChessStatus[i][j] == STATUS_BLANK)
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}

int judge(Point spPoint)
{
	//��������������¼������ͬ�����Ӹ���
	int nCount=0;
	//��׼״̬
	const int STANDARD = AnChessStatus[spPoint.row][spPoint.col];

	if(judgeDraw() == TRUE)
	{
		return JUDGE_DRAW;
	}

	//����
	nCount = judgeHorizontal(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}

	//����
	nCount = judgeVertical(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}

	//�Խ��ߣ�����-���ϣ�
	nCount = judgeHyperphoria(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}


	//��б������-���£�
	nCount = judgeHypophoria(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}

	return JUDGE_PLAY;
}

