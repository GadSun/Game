#pragma once
#include "Thing.h"
class CAnimal :
	/*
	定义动物类
	v1.0: 定义动物站立、转向、移动
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

