#include "stdafx.h"
#include "Background.h"


CBackground::CBackground()
{
}

CBackground::CBackground(int width, int height, int position_x, int position_y)
{
	this->width = width;
	this->height = height;
	this->position_x = position_x;
	this->position_y = position_y;
}

CBackground::~CBackground()
{
}
