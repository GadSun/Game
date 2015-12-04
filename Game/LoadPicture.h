#pragma once
class CLoadPicture
	/*
	定义载入图片类
	定义背景、人物图片、动物图片、静态事物图片
	定义构造函数载入图片
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

