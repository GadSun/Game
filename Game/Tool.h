#pragma once
#include "time.h"
#include "Thing.h"
class CTool
	/*
	���幤����
	���巵����ȫ���������
	�����ȥͼƬ��ɫ��������
	���彫���������ﰴ��ײ������������к���
	���彫����DC��ʼ��Ϊ�����ķ���
	*/
{
public:
	CTool();
	~CTool();
	static int Random(int, int);
	static CThing* rank(int, CThing*);
	afx_msg static void print(HDC, int, int, int, int, HDC, int, int, UINT);
	static HDC intiBufferDC(HDC, HBITMAP, int, int);
	static int judgeColor(HDC, int, int);
};

