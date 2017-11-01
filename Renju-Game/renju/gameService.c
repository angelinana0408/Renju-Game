//逻辑层
#include<stdio.h>
#include"global.h"
#include"model.h"

extern int AnChessStatus[15][15];//全局二维数组，定数组，真正记录各点状态,extern 声明用外面的
//@@@@@@@@@@@@@@@@@@@@@开局和下子@@@@@@@@@@@@@@@@@@@@@@
void initStatus()//function：初始化棋盘各个位置的状态值
{
	
	int i,j;//行号列号索引值

	//初始化状态值，使用双重循环便利二维数组
	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 15; j++)
		{
			AnChessStatus[i][j]=STATUS_BLANK;
		}
	}
}
//set get 一般是成对出现
int getStatus(const Point spPoint)//function：返回状态二维数组
	//加const表示不能修改其值
{
	return AnChessStatus[spPoint.row][spPoint.col];
}

void setStatus(const Point spPoint)//function：将状态值放入二维数组的对应位置
{
	AnChessStatus[spPoint.row][spPoint.col] = spPoint.status;
}


//@@@@@@@@@@@@@@@@@@@@@胜负判断@@@@@@@@@@@@@@@@@@@@@@

int judgeHorizontal(const Point spPoint)
{
	int i,j;
	int counter = 1;
	//横向
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
	//竖向
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
	//对角线（左下-右上）
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
	//下斜（左上-右下）
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
	//计数器，用来记录连续相同的棋子个数
	int nCount=0;
	//标准状态
	const int STANDARD = AnChessStatus[spPoint.row][spPoint.col];

	if(judgeDraw() == TRUE)
	{
		return JUDGE_DRAW;
	}

	//横向
	nCount = judgeHorizontal(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}

	//竖向
	nCount = judgeVertical(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}

	//对角线（左下-右上）
	nCount = judgeHyperphoria(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}


	//下斜（左上-右下）
	nCount = judgeHypophoria(spPoint);
	if(nCount >= 5)
	{
		return JUDGE_WIN;
	}

	return JUDGE_PLAY;
}

