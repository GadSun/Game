
// GameDlg.h : ͷ�ļ�
//

#pragma once
#include "LoadPicture.h"
#include "Thing.h"
#include "Person.h"
#include "Scenery.h"
#include "Animal.h"
#include "Background.h"
#include "Barrier.h"
#include "Tool.h"
#include "afxwin.h"


// CGameDlg �Ի���
class CGameDlg : public CDialogEx
{
// ����
public:
	CGameDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GAME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CLoadPicture clp;//����ͼƬ����
	int contrul;//���ƶ���0.���� 1.�ˣ�
	int perIndex;//��������ͼƬ������
	int animalIndex;//���Ŷ���ͼƬ������
	int perN;//��������ͼƬ�����仯��ѭ������
	int aniN;//���ƶ���ͼƬ�����仯��ѭ������
	CPerson per;//�������
	int perNum;//�˵�����
	CScenery sce[200];//��̬�������
	int sceNum;//��̬��������
	CAnimal ani[200];//�������
	int aniNum;//��������
	int num;//��������
	int aniIndex;//���Ķ���λ��ʱʹ�õ�ѭ������
	CClientDC* dc;
	HDC buffer_DC;//����DC
	HDC hDCBitmap;
	HDC hDCBitmap_bac;//���ƴ��ͼDC
	CRect recBackground;
	int worldWidth;
	int worldHeight;
	CBackground bac;//v2.0: �������� ���ڱ����ƶ�
	int bacNum;
	int scene;//��ͷ״̬
	CScenery wal[46];//��ǽ����
	int walNum;//��ǽ����
	int area;//������������(0-9)
	CBarrier bar[70];//�ϰ���
	int barNum;//�ϰ�������
	HDC DC_barrier;//�����ϰ���DC
	int barAry[480][240];//�߼�����ײ����

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
