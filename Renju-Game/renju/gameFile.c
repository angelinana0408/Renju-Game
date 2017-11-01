//���ݴ洢��
#include<stdio.h>
#include"model.h"
#include"global.h"

extern int AnChessStatus[15][15];

int saveChess()
{
	FILE* pfChess = NULL;
	int i, j;
	

	//���ļ�
	pfChess = fopen("CurrentChess.txt","wb+");

	//���ļ������򷵻�FALSE
	if(pfChess == NULL)
	{
		return FALSE;
	}

	//д�뵱ǰ���
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

	//���ļ�
	if((pfChess = fopen("CurrentChess.txt","rb+")) == NULL)
	{
		return FALSE;
	}

	//��ȡ
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