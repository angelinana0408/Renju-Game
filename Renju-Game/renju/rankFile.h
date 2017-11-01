//数据存储层
#ifndef _RANKFILE_H_//大写的这部分就叫做宏
#define _RANKFILE_H_

#include"model.h" 

int readRanklist(Rank *psrRanks, const int nMaxSize);
int writeRanklist(Rank *psrRanks, const int nSize);

#endif //_RANKFILE_H_