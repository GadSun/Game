#pragma once
//����
#define SOUTH 1
#define SOUTHWEST 2
#define WEST 3
#define NORTHWEST 4
#define NORTH 5
#define NORTHEAST 6
#define EAST 7
#define SOUTHEAST 8
//��������
#define  SCENERY 10
#define PERSON 11
#define ANIMAL 12
//״̬
#define STAND 0
#define MOVE 40
//��ͷ״̬
#define STATIC 1//��̬��ͷ(1,3,7,9)
#define X_DY_S 2//x����̬��y����̬��2,8��
#define X_SY_D 3//y����̬��x����̬��4,6��
#define DYNAMIC 4//��̬��ͷ5
class CThing	
	/*
	��������Ļ���
	v1.0: ���������λ�ã��ߴ磬����,���򡢵�ǰ״̬��վ�����ƶ�������̬�������ࡢ�������ࡢĿ�ĵء��ٶ�
	v1.0: ���幹�췽�������������λ�ã��ߴ磬����
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
	int position;//����ʱ���ڵ�λ��
	int barType;//�ϰ�������
	int aim_x;
	int aim_y;
	int speed_x;
	int speed_y;
	int n;
	int index;
};

