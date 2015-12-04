#pragma once
//方向
#define SOUTH 1
#define SOUTHWEST 2
#define WEST 3
#define NORTHWEST 4
#define NORTH 5
#define NORTHEAST 6
#define EAST 7
#define SOUTHEAST 8
//事物种类
#define  SCENERY 10
#define PERSON 11
#define ANIMAL 12
//状态
#define STAND 0
#define MOVE 40
//镜头状态
#define STATIC 1//静态镜头(1,3,7,9)
#define X_DY_S 2//x方向动态，y方向静态（2,8）
#define X_SY_D 3//y方向静态，x方向动态（4,6）
#define DYNAMIC 4//动态镜头5
class CThing	
	/*
	所有事物的基类
	v1.0: 定义事物的位置，尺寸，种类,朝向、当前状态（站立、移动）、静态事物种类、动物种类、目的地、速度
	v1.0: 定义构造方法，设置事物的位置，尺寸，种类
	*/
{
public:
	CThing();
	CThing(int, int, int, int, int);
	~CThing();

public:
	int position_x;
	int position_y;
	int width;
	int height;
	int type;
	int direction;
	int stat;
	int sceType;
	int aniType;
	int position;//创建时所在的位置
	int barType;//障碍物种类
	int aim_x;
	int aim_y;
	int speed_x;
	int speed_y;
	int n;
	int index;
};

