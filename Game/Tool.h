#pragma once
#include "time.h"
#include "Thing.h"
class CTool
	/*
	定义工具类
	定义返回完全随机数方法
	定义除去图片白色背景方法
	定义将世界中事物按距底部举例升序排列函数
	定义将缓冲DC初始化为背景的方法
	*/
{
public:
	CTool();
	~CTool();
	static int Random(int, int);
	static CThing* rank(int, CThing*);
	afx_msg static void print(HDC, int, int, int, int, HDC, int, int, UINT);
	static HDC intiBufferDC(HDC, HBITMAP, int, int);
	static int judgeColor(HDC, int, int);
};

