#include "stdafx.h"
#include "Barrier.h"


CBarrier::CBarrier()
{
}

CBarrier::CBarrier(int width, int height, int position_x, int position_y, int barType){
	this->width = width;
	this->height = height;
	this->position_x = position_x;
	this->position_y = position_y;
	this->barType = barType;
}

CBarrier::~CBarrier()
{
}
