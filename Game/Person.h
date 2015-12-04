#pragma once
#include "Thing.h"
class CPerson :
	/*
	人物类
	v1.0: 定义人物站立、转向、移动
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

