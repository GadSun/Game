#pragma once
#include "Thing.h"
class CPerson :
	/*
	������
	v1.0: ��������վ����ת���ƶ�
	*/
	public CThing
{
public:
	CPerson();
	CPerson(int, int, int, int, int);
	~CPerson();
public:
	void stand();
	void turn();
	void move();	
};

