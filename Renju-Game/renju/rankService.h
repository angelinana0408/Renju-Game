//逻辑层
#ifndef _RANKSERVICE_H_//大写的这部分就叫做宏
#define _RANKSERVICE_H_


int judgeOrder(const int nStep);
void insertRank(const int nPosition, const Rank srRank);
void saveRanks();
void initRanks();
int getRanks(Rank *psrRanks, const int nMaxSize);
int getRankSize();

#endif //_RANKSERVICE_H_