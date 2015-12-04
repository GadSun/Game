#include "stdafx.h"
#include "Animal.h"

CAnimal::CAnimal(){
}

CAnimal::CAnimal(int width, int height, int position_x, int position_y, int type, int aniType)
{
	//TODO: 动事物尺寸、位置、种类、目的地、朝向、状态、速度进行初始化
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
	动物物站立的方法
	速度变为0
	状态变为站立
	目的地变为当前位置（充要条件）
	*/
	this->aim_x = position_x;
	this->aim_y = position_y;
	this->stat = STAND;
	this->speed_x = 0;
	this->speed_y = 0;
}

void CAnimal::turn(){
	/*
	动物转向的方法
	当目的地等于位置时返回
	当目的地不等于位置时，判断目的地与位置的相对关系，改变朝向
	*/
	int tan;//目的地与位置相对关系
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
	动物移动的方法
	先转向
	状态变为移动
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
