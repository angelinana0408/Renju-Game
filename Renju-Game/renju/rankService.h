//�߼���
#ifndef _RANKSERVICE_H_//��д���ⲿ�־ͽ�����
#define _RANKSERVICE_H_


int judgeOrder(const int nStep);
void insertRank(const int nPosition, const Rank srRank);
void saveRanks();
void initRanks();
int getRanks(Rank *psrRanks, const int nMaxSize);
int getRankSize();

#endif //_RANKSERVICE_H_