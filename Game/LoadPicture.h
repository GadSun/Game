#pragma once
class CLoadPicture
	/*
	��������ͼƬ��
	���屳��������ͼƬ������ͼƬ����̬����ͼƬ
	���幹�캯������ͼƬ
	*/
{
public:
	CLoadPicture();
	~CLoadPicture();
public:
	HBITMAP background;
	HBITMAP person[800];
	HBITMAP animal[3][120];
	HBITMAP scenery[97];
	HBITMAP  barrier[90];
	HBITMAP white;
};

