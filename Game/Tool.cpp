#include "stdafx.h"
#include "Tool.h"


CTool::CTool()
{
}


CTool::~CTool()
{
}

int CTool::Random(int start, int end){
	/*
	���巵�����������
	*/
	if (end > start){
		return(start + (GetTickCount() + rand()) % (end - start));
	}
	else if (end == start){
		return end;
	}
	else if (end < start){
		return(end + (GetTickCount() + rand()) % (start - end));
	}
}

void CTool::print(HDC hDesDC,
	int iDesX, int iDesY,
	int iWide, int iHigh,
	HDC hSurDC,
	int iSurX, int iSurY,
	UINT iMaskCol
	)
{
	/*
	��ͼƬ�İ�ɫ����ȥ������
	*/
	HBITMAP hTmpBmp = CreateCompatibleBitmap(hDesDC, iWide, iHigh);
	HBITMAP hMaskBmp = CreateBitmap(iWide, iHigh, 1, 1, NULL);
	HDC		hTmpDC = CreateCompatibleDC(hDesDC);
	HDC		hMaskDC = CreateCompatibleDC(hDesDC);
	HBITMAP hOldTmpBmp = (HBITMAP)SelectObject(hTmpDC, hTmpBmp);
	HBITMAP hOldMaskBmp = (HBITMAP)SelectObject(hMaskDC, hMaskBmp);

	BitBlt(hTmpDC, 0, 0, iWide, iHigh, hSurDC, iSurX, iSurY, SRCCOPY);

	COLORREF colOld = SetBkColor(hTmpDC, iMaskCol);
	BitBlt(hMaskDC, 0, 0, iWide, iHigh, hTmpDC, 0, 0, SRCCOPY);
	SetBkColor(hTmpDC, colOld);

	BitBlt(hMaskDC, 0, 0, iWide, iHigh, hMaskDC, 0, 0, NOTSRCCOPY);

	BitBlt(hTmpDC, 0, 0, iWide, iHigh, hMaskDC, 0, 0, SRCAND);


	BitBlt(hMaskDC, 0, 0, iWide, iHigh, hMaskDC, 0, 0, NOTSRCCOPY);
	BitBlt(hDesDC, iDesX, iDesY, iWide, iHigh, hMaskDC, 0, 0, SRCAND);
	BitBlt(hDesDC, iDesX, iDesY, iWide, iHigh, hTmpDC, 0, 0, SRCPAINT);

	SelectObject(hTmpDC, hOldTmpBmp);
	DeleteDC(hTmpDC);
	SelectObject(hMaskDC, hOldMaskBmp);
	DeleteDC(hMaskDC);

	DeleteObject(hTmpBmp);
	DeleteObject(hMaskBmp);
}

CThing* CTool::rank(int thingNum, CThing* world){
	//TODO: �����������ﰴ��ײ�����������
	if (thingNum == 1 || thingNum == 0){
		return world;
	}
	//����position_y��������
	for (int i = 0; i < thingNum; i++){
		for (int j = i + 1; j < thingNum; j++){
			if (world[i].position_y + world[i].height > world[j].position_y + world[j].height){
				CThing obj = world[i];
				world[i] = world[j];
				world[j] = obj;
			}
		}
	}
	return world;
}

HDC CTool::intiBufferDC(HDC dc, HBITMAP background, int width, int height){

	//TODO:  ������DC��ʼ��Ϊ����
	HDC hDCBitmap = CreateCompatibleDC(dc);
	SelectObject(hDCBitmap, background);
	CTool::print(dc, 0, 0, width, height, hDCBitmap, 0, 0, RGB(255, 255, 255));
	return dc;
}

int CTool::judgeColor(HDC DC_Barrier, int position_x, int position_y){
	
	//TODO: �ж���ɫ����ɫ����0  ��ɫ����1
	COLORREF color = GetPixel(DC_Barrier, position_x, position_y);
	if (color == RGB(0, 0, 0)){
		return 0;
	}
	else if (color == RGB(255, 255, 255));
	return 1;
}