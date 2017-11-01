//数据存储层
#include<stdio.h>
#include"model.h"
#include"global.h"

extern int AnChessStatus[15][15];

int saveChess()
{
	FILE* pfChess = NULL;
	int i, j;
	

	//打开文件
	pfChess = fopen("CurrentChess.txt","wb+");

	//打开文件出错，则返回FALSE
	if(pfChess == NULL)
	{
		return FALSE;
	}

	//写入当前棋局
	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 15; j++)
		{
			fprintf(pfChess,"%d ", AnChessStatus[i][j]);
		}
		fprintf(pfChess,"\n");
	}

	fclose(pfChess);

	return TRUE;

}

int readChess()
{
	FILE* pfChess = NULL;
	int i, j;

	//打开文件
	if((pfChess = fopen("CurrentChess.txt","rb+")) == NULL)
	{
		return FALSE;
	}

	//读取
	for(i = 0; i < 15; i++)
	{
		for(j = 0; j < 15; j++)
		{
			fscanf(pfChess,"%d", &AnChessStatus[i][j]);
		}
		    
	}

	fclose(pfChess);

	return TRUE;
	
}