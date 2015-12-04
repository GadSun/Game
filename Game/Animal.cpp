#include "stdafx.h"
#include "Animal.h"

CAnimal::CAnimal(){
}

CAnimal::CAnimal(int width, int height, int position_x, int position_y, int type, int aniType)
{
	//TODO: ������ߴ硢λ�á����ࡢĿ�ĵء�����״̬���ٶȽ��г�ʼ��
	this->width = width;
	this->height = height;
	this->position_x = position_x;
	this->position_y = position_y;
	this->type = type;
	this->aniType = aniType;
	this->aim_x = position_x;
	this->aim_y = position_y;
	this->direction = SOUTH;
	this->stat = 0;
	this->speed_x = 0;
	this->speed_y = 0;
	this->n = 1;
	this->index = 0;
}

CAnimal::~CAnimal()
{
}

void CAnimal::stand(){
	/*
	������վ���ķ���
	�ٶȱ�Ϊ0
	״̬��Ϊվ��
	Ŀ�ĵر�Ϊ��ǰλ�ã���Ҫ������
	*/
	this->aim_x = position_x;
	this->aim_y = position_y;
	this->stat = STAND;
	this->speed_x = 0;
	this->speed_y = 0;
}

void CAnimal::turn(){
	/*
	����ת��ķ���
	��Ŀ�ĵص���λ��ʱ����
	��Ŀ�ĵز�����λ��ʱ���ж�Ŀ�ĵ���λ�õ���Թ�ϵ���ı䳯��
	*/
	int tan;//Ŀ�ĵ���λ����Թ�ϵ
	if (aim_x == position_x&&aim_y == position_y){
		return;
	}
	tan = abs(aim_x - position_x) - abs(aim_y - position_y);
	if (aim_x - position_x > 0){
		if (aim_y - position_y > 0){
			if (tan > 0){
				direction = EAST;
				if (stat == 40){
					speed_x = 4;
					speed_y = 0;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan == 0){
				direction = SOUTHEAST;
				if (stat == 40){
					speed_x = 4;
					speed_y = 4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan < 0){
				direction = SOUTH;
				if (stat == 40){
					speed_x = 0;
					speed_y = 4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
		}
		else{
			if (tan > 0){
				direction = EAST;
				if (stat == 40){
					speed_x = 4;
					speed_y = 0;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan == 0){
				direction = NORTHEAST;
				if (stat == 40){
					speed_x = 4;
					speed_y = -4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan < 0){
				direction = NORTH;
				if (stat == 40){
					speed_x = 0;
					speed_y = -4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
		}
	}
	else{
		if (aim_y - position_y > 0){
			if (tan > 0){
				direction = WEST;
				if (stat == 40){
					speed_x = -4;
					speed_y = 0;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan == 0){
				direction = SOUTHWEST;
				if (stat == 40){
					speed_x = -4;
					speed_y = 4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan < 0){
				direction = SOUTH;
				if (stat == 40){
					speed_x = 0;
					speed_y = 4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
		}
		else{
			if (tan > 0){
				direction = WEST;
				if (stat == 40){
					speed_x = -4;
					speed_y = 0;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan == 0){
				direction = NORTHWEST;
				if (stat == 40){
					speed_x = -4;
					speed_y = -4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
			else if (tan < 0){
				direction = NORTH;
				if (stat == 40){
					speed_x = 0;
					speed_y = -4;
				}
				else if (stat == 0){
					speed_x = 0;
					speed_y = 0;
				}
			}
		}
	}
}

void CAnimal::move(){
	/*
	�����ƶ��ķ���
	��ת��
	״̬��Ϊ�ƶ�
	*/
	this->turn();
	this->stat = MOVE;
	switch (direction)
	{
	case SOUTH:
		speed_x = 0;
		speed_y = 4;
		break;
	case SOUTHWEST:
		speed_x = -4;
		speed_y = 4;
		break;
	case WEST:
		speed_x = -4;
		speed_y = 0;
		break;
	case NORTHWEST:
		speed_x = -4;
		speed_y = -4;
		break;
	case NORTH:
		speed_x = 0;
		speed_y = -4;
		break;
	case NORTHEAST:
		speed_x = 4;
		speed_y = -4;
		break;
	case EAST:
		speed_x = 4;
		speed_y = 0;
		break;
	case SOUTHEAST:
		speed_x = 4;
		speed_y = 4;
		break;
	default:
		break;
	}
}
