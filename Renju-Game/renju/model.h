//���ݽṹ���壬����ṹ��
#ifndef _MODEL_H_
#define _MODEL_H_
//������״̬����   ö������

enum PointStatus
{
	STATUS_BLANK = -1,
	STATUS_BLAKE = 0,
	STATUS_WHITE = 1
};

//���������
typedef struct Point
{
	int row;
	int col;
	int status;
}Point;


// ��������ṹ
typedef struct Rank
{
	char name[64];	//ʤ��������
	int step;	//ʤ��ʱ���õĲ���
}Rank;

#endif