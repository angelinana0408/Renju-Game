//数据存储层
#include<stdio.h>
#include"model.h"
#include"global.h"

int readRanklist(Rank *psrRanks, const int nMaxSize)//Function:取出文件中玩家个数，将玩家姓名和步数放到排名结构数组中
{	//结构数组的定义：1、 Rank *psrRanks2、
	FILE* pfRanklist = NULL;	//排行榜文件指针
	int nSize = 0;	//排名玩家个数，临时
	int nIndex = 0;	//数组的索引号
	char acBuf[128];	//用来保存从文件中读取上来的数据

	//打开文件
	if((pfRanklist = fopen("Ranklist.txt","rb+")) == NULL)
	{
		return 0;
	}

	//读取排名信息个数
	fscanf(pfRanklist, "TOTALCOUNT%d RANKLIST\n", &nSize);
	
	//逐行读取文件，如果文件超出10条，或读取到文件尾部，都结束读取
	for(nIndex = 0; (nIndex < nSize&&nIndex < nMaxSize)||(!feof(pfRanklist)); nIndex++)
	{
		Rank srRank;
		//读取一行记录信息，注意在格式化中要标上，\n,这样读取的就是一行记录，且不包含\n
		fscanf(pfRanklist,"%s ## %d\n", &srRank.name, &srRank.step);
		psrRanks[nIndex] = srRank;
	}

	//关闭文件
	fclose(pfRanklist);

	//返回数据个数
	return nSize;
	
}

int writeRanklist(Rank *psrRanks, const int nSize)//function:将玩家个数和排名结构数组中的玩家姓名和步数放到文件中
{
	FILE* pfRanklist = NULL;
	int nIndex = 0;	

	//打开文件
	pfRanklist = fopen("Ranklist.txt","wb+");

	//打开文件出错，则返回FALSE
	if(pfRanklist == NULL)
	{
		return FALSE;
	}

	//写入排名总数
	fprintf(pfRanklist,"TOTALCOUNT%d RANKLIST\n", nSize);

	//遍历Rank结构体数组，逐行显示
	for(nIndex = 0; nIndex < nSize; nIndex++)
	{
		Rank* psrRank;
		psrRank = &psrRanks[nIndex];

		//写文件，字段之间用“##”分割
		fprintf(pfRanklist,"%s ## %d\n", psrRank->name, psrRank->step);
	}

	fclose(pfRanklist);

	return TRUE;
}


	
	
	
	
	
	
	
	
	


