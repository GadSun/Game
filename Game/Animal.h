#pragma once
#include "Thing.h"
class CAnimal :
	/*
	���嶯����
	v1.0: ���嶯��վ����ת���ƶ�
	*/
	public CThing
{
public:
	CAnimal();
	CAnimal(int, int, int, int, int, int);
	~CAnimal();
public:
	void stand();
	void turn();
	void move();
};

