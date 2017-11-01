//�߼���

#include"model.h"
#include"rankFile.h"


//ȫ�ֱ��� ��ѵ�һ����ĸ��д
Rank AsrRanks[10];//A ���� s �ṹ�� r��������һ����ĸ����ʽ�洢������Ϣ
int NRankSize = 0;

void initRanks();

int judgeOrder(const int nStep)
{
	//����Ԫ�ر���ʱ������ֵ
	int nIndex = 0;

	//��ʼ�����õ������������������,��ʼ��NRankSize
	initRanks();

	//�ҵ���һ�����ڸò�������ң����µ���ҵ�����Ϊ�ҵ�����ҵ�����
	while(nIndex < NRankSize)
	{
		if(AsrRanks[nIndex].step >= nStep)
		{
			break;
		}
		nIndex++;
	}
	nIndex++;//���α�����ֵ��һ
	return nIndex;
}

void insertRank(const int nPosition, const Rank srRank)//function�����ṹ�������Ϣ����ȷ������λ�÷�����ʽ�Ľṹ��������
{
	//Ԫ����������
	int nIndex = NRankSize;

	//�������Ϊ���һ��Ԫ��ʱ��ֱ�Ӹ���ԭ���ݣ�������㲻�����ʱ�����������ݺ���
	if(nPosition < 9)
	{
		//����Ԫ�أ�������Ӳ���㿪ʼ�������һλ���Ӻ�����ǰ��
		while(nIndex > nPosition)
		{
			AsrRanks[nIndex] = AsrRanks[nIndex-1];
			nIndex--;
		}
	}

	//�ڲ��������µ�Ԫ��
	AsrRanks[nPosition] = srRank;

	if(NRankSize<10)
	{
		//������������
		NRankSize++;
	}

}

void saveRanks()
{
	writeRanklist(AsrRanks, NRankSize);
}

//��ø���
int getRankSize()
{
	return NRankSize;
}

//��ӻ���������ĺ���
int getRanks(Rank *psrRanks, const int nMaxSize)
{
	int nIndex = 0;

	//ѭ����ȫ��������ȡ�����ݣ���ŵ���ʱ��ŵ�������
	for(nIndex = 0; (nIndex < nMaxSize )&& ( nIndex < NRankSize); nIndex ++)
	{
		psrRanks[nIndex] = AsrRanks[nIndex];
	}

	//�����õ���������Ϊ��ȷ��ȡ����Ҹ���
	return nIndex;
}

void initRanks()//�õ�NRankSize�������а������������
{
	//��ȡ�������飬��ø���
	NRankSize = readRanklist(AsrRanks, 10);
}