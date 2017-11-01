//逻辑层

#include"model.h"
#include"rankFile.h"


//全局变量 会把第一个字母大写
Rank AsrRanks[10];//A 数组 s 结构体 r类型名第一个字母，正式存储排名信息
int NRankSize = 0;

void initRanks();

int judgeOrder(const int nStep)
{
	//数组元素遍历时的索引值
	int nIndex = 0;

	//初始化：得到排名榜中已有玩家数,初始化NRankSize
	initRanks();

	//找到第一个大于该步数的玩家，则新的玩家的排名为找到的玩家的排名
	while(nIndex < NRankSize)
	{
		if(AsrRanks[nIndex].step >= nStep)
		{
			break;
		}
		nIndex++;
	}
	nIndex++;//名次比索引值多一
	return nIndex;
}

void insertRank(const int nPosition, const Rank srRank)//function：将结构体玩家信息以正确的排名位置放入正式的结构体数组中
{
	//元素数组索引
	int nIndex = NRankSize;

	//当插入点为最后一个元素时，直接覆盖原数据，当插入点不在最后时，将其他数据后移
	if(nPosition < 9)
	{
		//遍历元素，将数组从插入点开始，向后移一位，从后面向前移
		while(nIndex > nPosition)
		{
			AsrRanks[nIndex] = AsrRanks[nIndex-1];
			nIndex--;
		}
	}

	//在插入点添加新的元素
	AsrRanks[nPosition] = srRank;

	if(NRankSize<10)
	{
		//增加排名人数
		NRankSize++;
	}

}

void saveRanks()
{
	writeRanklist(AsrRanks, NRankSize);
}

//获得个数
int getRankSize()
{
	return NRankSize;
}

//添加获得玩家数组的函数
int getRanks(Rank *psrRanks, const int nMaxSize)
{
	int nIndex = 0;

	//循环从全局数组中取出数据，存放到临时存放的数组中
	for(nIndex = 0; (nIndex < nMaxSize )&& ( nIndex < NRankSize); nIndex ++)
	{
		psrRanks[nIndex] = AsrRanks[nIndex];
	}

	//索引好递增后，正好为正确读取的玩家个数
	return nIndex;
}

void initRanks()//得到NRankSize，即排行榜中已有玩家数
{
	//读取排名数组，获得个数
	NRankSize = readRanklist(AsrRanks, 10);
}