#include "stdafx.h"
#include "Scenery.h"

CScenery::CScenery(){
}

CScenery::CScenery(int width, int height, int position_x, int position_y, int type, int sceType){
	//TODO: ������ߴ硢λ�á����ࡢ���򡢾�̬����������г�ʼ��
	this->width = width;
	this->height = height;
	this->position_x = position_x;
	this->position_y = position_y;
	this->type = type;
	this->direction = 0;
	this->stat = 0;
	this->sceType = sceType;
}
CScenery::~CScenery()
{
}
