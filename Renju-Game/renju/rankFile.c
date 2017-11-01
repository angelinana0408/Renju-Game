//���ݴ洢��
#include<stdio.h>
#include"model.h"
#include"global.h"

int readRanklist(Rank *psrRanks, const int nMaxSize)//Function:ȡ���ļ�����Ҹ���������������Ͳ����ŵ������ṹ������
{	//�ṹ����Ķ��壺1�� Rank *psrRanks2��
	FILE* pfRanklist = NULL;	//���а��ļ�ָ��
	int nSize = 0;	//������Ҹ�������ʱ
	int nIndex = 0;	//�����������
	char acBuf[128];	//����������ļ��ж�ȡ����������

	//���ļ�
	if((pfRanklist = fopen("Ranklist.txt","rb+")) == NULL)
	{
		return 0;
	}

	//��ȡ������Ϣ����
	fscanf(pfRanklist, "TOTALCOUNT%d RANKLIST\n", &nSize);
	
	//���ж�ȡ�ļ�������ļ�����10�������ȡ���ļ�β������������ȡ
	for(nIndex = 0; (nIndex < nSize&&nIndex < nMaxSize)||(!feof(pfRanklist)); nIndex++)
	{
		Rank srRank;
		//��ȡһ�м�¼��Ϣ��ע���ڸ�ʽ����Ҫ���ϣ�\n,������ȡ�ľ���һ�м�¼���Ҳ�����\n
		fscanf(pfRanklist,"%s ## %d\n", &srRank.name, &srRank.step);
		psrRanks[nIndex] = srRank;
	}

	//�ر��ļ�
	fclose(pfRanklist);

	//�������ݸ���
	return nSize;
	
}

int writeRanklist(Rank *psrRanks, const int nSize)//function:����Ҹ����������ṹ�����е���������Ͳ����ŵ��ļ���
{
	FILE* pfRanklist = NULL;
	int nIndex = 0;	

	//���ļ�
	pfRanklist = fopen("Ranklist.txt","wb+");

	//���ļ������򷵻�FALSE
	if(pfRanklist == NULL)
	{
		return FALSE;
	}

	//д����������
	fprintf(pfRanklist,"TOTALCOUNT%d RANKLIST\n", nSize);

	//����Rank�ṹ�����飬������ʾ
	for(nIndex = 0; nIndex < nSize; nIndex++)
	{
		Rank* psrRank;
		psrRank = &psrRanks[nIndex];

		//д�ļ����ֶ�֮���á�##���ָ�
		fprintf(pfRanklist,"%s ## %d\n", psrRank->name, psrRank->step);
	}

	fclose(pfRanklist);

	return TRUE;
}


	
	
	
	
	
	
	
	
	


