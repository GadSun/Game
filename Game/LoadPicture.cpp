#include "stdafx.h"
#include "LoadPicture.h"


CLoadPicture::CLoadPicture()
{
	/*
	���뱳���������̬�������ϰ���ͼƬ
	*/
	char name[1024];
	background = (HBITMAP)LoadImage(AfxGetInstanceHandle(), "pic/diA.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	for (int i = 0; i < 800; i++){
		sprintf(name, "pic/per/c%05d.bmp", i);
		person[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	for (int i = 0; i < 97; i++){
		sprintf(name, "pic/��/c%05d.bmp", i);
		scenery[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	for (int i = 0; i < 120; i++){
		sprintf(name, "pic/��/c%05d.bmp", i);
		animal[0][i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	for (int i = 400; i < 520; i++){
		sprintf(name, "pic/��/c%05d.bmp", i);
		animal[1][i - 400] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	for (int i = 800; i < 920; i++){
		sprintf(name, "pic/��/c%05d.bmp", i);
		animal[2][i - 800] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	for (int i = 0; i < 13; i++){
		sprintf(name, "pic/��/b%05d.bmp", i);
		barrier[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	for (int i = 13; i < 85; i++){
		sprintf(name, "pic/��/white.bmp");
		barrier[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	for (int i = 85; i < 90; i++){
		sprintf(name, "pic/��/b%05d.bmp", i);
		barrier[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	white = (HBITMAP)LoadImage(AfxGetInstanceHandle(), "pic/��/white1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}


CLoadPicture::~CLoadPicture()
{
}
