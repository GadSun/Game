#include "stdafx.h"
#include "Thing.h"

CThing::CThing(){
}

CThing::CThing(int width, int height, int position_x, int position_y, int type)
{
	//TODO: 对事物尺寸、位置、种类、朝向进行初始化
	this->width = width;
	this->height = height;
	this->position_x = position_x;
	this->position_y = position_y;
	this->type = type;
	this->direction = 0;
	this->stat = 0;
}


CThing::~CThing()
{
}
