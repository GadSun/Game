#include "stdafx.h"
#include "Thing.h"

CThing::CThing(){
}

CThing::CThing(int width, int height, int position_x, int position_y, int type)
{
	//TODO: ������ߴ硢λ�á����ࡢ������г�ʼ��
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
