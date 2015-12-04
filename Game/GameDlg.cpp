
// GameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Game.h"
#include "GameDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGameDlg �Ի���



CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CGameDlg ��Ϣ�������

BOOL CGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	//���öԻ����С
	::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 640, 300, 640, 480, SWP_NOZORDER);
	//::SetWindowPos(this->m_hWnd, HWND_BOTTOM, 0, 0, 1800, 900, SWP_NOZORDER);

	//��ʼ������dc
	dc = new CClientDC(this);
	buffer_DC = CreateCompatibleDC(NULL);
	hDCBitmap = CreateCompatibleDC(NULL);
	HBITMAP h_temp_bitmap = CreateCompatibleBitmap(*dc, 1920, 960);
	SelectObject(buffer_DC, h_temp_bitmap);

	//��ʼ�����ͼDC
	h_temp_bitmap = CreateCompatibleBitmap(*dc, 1920, 960);
	hDCBitmap_bac = CreateCompatibleDC(NULL);
	SelectObject(hDCBitmap_bac, h_temp_bitmap);

	//��ʼ�������ϰ���DC
	h_temp_bitmap = CreateCompatibleBitmap(*dc, 1920, 960);
	DC_barrier = CreateCompatibleDC(NULL);
	SelectObject(DC_barrier, h_temp_bitmap);

	//��ʼ����������������
	perNum = 0;
	sceNum = 0;
	aniNum = 0;
	barNum = 0;
	num = 0;
	aniIndex = 0;

	//��ʼ������
	bac = CBackground(640, 480, 0, 0);
	bacNum = 1;

	//��ʼ������ͼƬ������
	perIndex = 0;
	animalIndex = 0;

	//����ͼƬ���ż�ʱ��
	SetTimer(1, 40, NULL);
	SetTimer(2, 40, NULL);
	SetTimer(3, 40, NULL);
	SetTimer(4, 2000, NULL);

	//��ʼ����ͷ״̬
	area = 1;
	scene = STATIC;

	//��ʼ����ǽ����ǽ��Ӧ���ϰ���
	for (int i = 0; i < 20; i++){
		//89�� ����ǽ 20��
		wal[i] = CScenery(52, 96, 300, 148 + i * 24, SCENERY, 89);
		bar[i] = CBarrier(52, 96, 300, 148 + i * 24, 89);
		wal[++i] = CScenery(52, 96, 1552, 148 + (i - 1) * 24, SCENERY, 89);
		bar[i] = CBarrier(52, 96, 1552, 148 + (i - 1) * 24, 89);
	}

	for (int i = 0; i < 4; i++){
		//��벿��8��88�ź��ǽ
		wal[20 + i] = CScenery(112, 68, 356 + i * 108, 118, SCENERY, 88);
		bar[20 + i] = CBarrier(112, 68, 356 + i * 108, 118, 88);
		wal[24 + i] = CScenery(112, 68, 356 + i * 108, 644, SCENERY, 88);
		bar[24 + i] = CBarrier(112, 68, 356 + i * 108, 644, 88);
	}

	for (int i = 0; i < 4; i++){
		//�Ұ벿��8��88�ź��ǽ
		wal[28 + i] = CScenery(112, 68, 1112 + i * 108, 118, SCENERY, 88);
		bar[28 + i] = CBarrier(112, 68, 1112 + i * 108, 118, 88);
		wal[32 + i] = CScenery(112, 68, 1112 + i * 108, 644, SCENERY, 88);
		bar[32 + i] = CBarrier(112, 68, 1112 + i * 108, 644, 88);
	}

	for (int i = 0; i < 3; i++){
		//�м�3��88�ź��ǽ
		wal[36 + i] = CScenery(112, 68, 788 + i * 108, 118, SCENERY, 88);
		bar[36 + i] = CBarrier(112, 68, 788 + i * 108, 118, 88);
	}

	//6������ǽ
	wal[39] = CScenery(100, 104, 276, 92, SCENERY, 87);
	bar[39] = CBarrier(100, 104, 276, 92, 87);
	wal[40] = CScenery(100, 104, 276, 614, SCENERY, 87);
	bar[40] = CBarrier(100, 104, 276, 614, 87);
	wal[41] = CScenery(100, 104, 1528, 92, SCENERY, 87);
	bar[41] = CBarrier(100, 104, 1528, 92, 87);
	wal[42] = CScenery(100, 104, 1528, 614, SCENERY, 87);
	bar[42] = CBarrier(100, 104, 1528, 614, 87);
	wal[43] = CScenery(100, 104, 784, 614, SCENERY, 87);
	bar[43] = CBarrier(100, 104, 784, 614, 87);
	wal[44] = CScenery(100, 104, 1020, 614, SCENERY, 87);
	bar[44] = CBarrier(100, 104, 1020, 614, 87);
	walNum = 45;
	barNum = 45;

	//��ȡ����ߴ�
	DIBSECTION ds;
	BITMAPINFOHEADER &bm = ds.dsBmih;
	HBITMAP picture = clp.person[0];
	GetObject(picture, sizeof(ds), &ds);
	int width = bm.biWidth;
	int height = bm.biHeight;

	//ʵ��������
	per = CPerson(width, height, 20, 20, PERSON);
	perNum = 1;

	//�����Ӷ�������
	aniNum = CTool::Random(5, 10);
	for (int i = 0; i < aniNum; i++){
		//��ȡ����ߴ�
		DIBSECTION ds;
		BITMAPINFOHEADER &bm = ds.dsBmih;
		int anitype = CTool::Random(0, 3);
		HBITMAP picture = clp.animal[anitype][0];
		GetObject(picture, sizeof(ds), &ds);
		int width = bm.biWidth;
		int height = bm.biHeight;
		ani[i] = CAnimal(width, height, CTool::Random(0, 1920 - width - 20), CTool::Random(0, 960 - height - 20), ANIMAL, anitype);
		ani[i].position = i;
	}

	//������þ�̬��������

	sceNum = CTool::Random(20, 50);
	for (int i = 0; i < sceNum; i++){
		//��ȡ��̬����ߴ�
		DIBSECTION ds;
		BITMAPINFOHEADER &bm = ds.dsBmih;
		int scetype = CTool::Random(13, 85);
		HBITMAP picture = clp.scenery[scetype];
		GetObject(picture, sizeof(ds), &ds);
		int width = bm.biWidth;
		int height = bm.biHeight;
		sce[i] = CScenery(width, height, CTool::Random(0, 1920 - width - 20), CTool::Random(0, 960 - height), SCENERY, scetype);
	}

	//�����ϰ���DC
	SelectObject(hDCBitmap, clp.white);
	CTool::print(DC_barrier, 0, 0, 1920, 960, hDCBitmap, 0, 0, RGB(0, 255, 255));
	for (int i = 0; i < barNum; i++){
		SelectObject(hDCBitmap, clp.barrier[bar[i].barType]);
		CTool::print(DC_barrier, bar[i].position_x, bar[i].position_y, bar[i].width, bar[i].height, hDCBitmap, 0, 0, RGB(255, 255, 255));
	}

	for (int i = 0; i < 480; i++){
		for (int j = 0; j < 240; j++){
			barAry[i][j] = CTool::judgeColor(DC_barrier, i * 4, j * 4);
		}
	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	/*
	1.���ƶ���
	2.�����ƶ�
	3.�����ƶ�
	4.���ö����ƶ�Ŀ�ĵ�
	*/
	//��ʼ�����������������
	int thingNum = 0;
	CThing world[200];
	CClientDC dc(this);
	DIBSECTION ds;
	BITMAPINFOHEADER &bm = ds.dsBmih;
	HBITMAP temp;
	int width;
	int height;
	int index;
	switch (nIDEvent)
	{
	case 1:
		//��������뵽������
		if (perNum == 1){
			world[thingNum] = per;
			thingNum++;
		}

		//����̬�������뵽������
		for (int i = 0; i < sceNum; i++){
			world[thingNum] = sce[i];
			thingNum++;
		}

		//���������뵽������
		for (int i = 0; i < aniNum; i++){
			world[thingNum] = ani[i];
			thingNum++;
		}

		//����ǽ����������
		for (int i = 0; i < walNum; i++){
			world[thingNum] = wal[i];
			thingNum++;
		}

		//�������е���������
		*world = *(CTool::rank(thingNum, world));

		//���ƴ��ͼ
		SelectObject(hDCBitmap, clp.background);
		for (int i = 0; i < 6; i++){
			CTool::print(hDCBitmap_bac, i % 3 * 640, i / 3 * 480, 640, 480, hDCBitmap, 0, 0, RGB(255, 255, 255));
		}

		//���վ�ײ�������������Ƶ����ͼ��
		for (int i = 0; i < thingNum; i++){
			switch (world[i].type)
			{
			case PERSON:
				index = (world[i].direction - 1)*(world[i].stat / 8 + 5) + per.index*(world[i].stat / 8 + 5) / 10 + world[i].stat;
				temp = clp.person[index];
				GetObject(temp, sizeof(ds), &ds);
				width = bm.biWidth;
				height = bm.biHeight;
				world[i].width = width;
				world[i].height = height;
				SelectObject(hDCBitmap, temp);
				CTool::print(hDCBitmap_bac, world[i].position_x, world[i].position_y, width, height, hDCBitmap, 0, 0, RGB(255, 255, 255));
				per.index += per.n;
				if (per.index == world[i].stat / 8 + 4 || per.index == 9){
					per.n = -1;
				}
				else if (per.index == 0){
					per.n = 1;
				}
				break;
			case SCENERY:
				temp = clp.scenery[world[i].sceType];
				GetObject(temp, sizeof(ds), &ds);
				width = bm.biWidth;
				height = bm.biHeight;
				world[i].width = width;
				world[i].height = height;
				SelectObject(hDCBitmap, temp);
				CTool::print(hDCBitmap_bac, world[i].position_x, world[i].position_y, width, height, hDCBitmap, 0, 0, RGB(255, 255, 255));
				break;
			case ANIMAL:
				index = (world[i].direction - 1)*(world[i].stat / 8 + 5) + ani[i].index*(world[i].stat / 8 + 5) / 10 + world[i].stat;
				temp = clp.animal[world[i].aniType][index];
				GetObject(temp, sizeof(ds), &ds);
				width = bm.biWidth;
				height = bm.biHeight;
				ani[world[i].position].width = width;
				ani[world[i].position].height = height;
				SelectObject(hDCBitmap, temp);
				CTool::print(hDCBitmap_bac, world[i].position_x, world[i].position_y, width, height, hDCBitmap, 0, 0, RGB(255, 255, 255));
				ani[i].index += ani[i].n;
				if (ani[i].index == world[i].stat / 8 + 4 || ani[i].index == 9){
					ani[i].n = -1;
				}
				else if (ani[i].index == 0){
					ani[i].n = 1;
				}
				break;
			default:
				break;

			}
		}
		
		//�ڴ��ͼ��ȡ��Ҫ��ʾ����
		CTool::print(buffer_DC, bac.position_x, bac.position_y, 1920, 960, hDCBitmap_bac, 0, 0, RGB(255, 255, 255));

		//������DC���Ƶ��Ի�����
		CTool::print(dc.m_hDC, 0, 0, 640, 480, buffer_DC, 0, 0, RGB(255, 255, 255));
		//CTool::print(dc.m_hDC, 0, 0, 1800, 900, DC_barrier, 0, 0, RGB(255, 255, 255));

		break;
	case 2:
		//ת��
		per.turn();

		//����Ŀ�ĵ�ʱͣ
		if (per.speed_x == 0 && per.speed_y != 0){
			if ((per.position_y - per.aim_y) / per.speed_y == 0){
				per.stand();
			}
		}
		else if (per.speed_y == 0 && per.speed_x != 0){
			if ((per.position_x - per.aim_x) / per.speed_x == 0){
				per.stand();
			}
		}
		else if (per.speed_x != 0 && per.speed_y != 0){
			if ((per.position_y - per.aim_y) / per.speed_y == 0 && (per.position_x - per.aim_x) / per.speed_x == 0){
				per.stand();
			}
		}

		//�ж�Ŀǰ�������򣬲����������������þ�ͷ״̬
		if (per.position_x >= 0 && per.position_x < 300){
			if (per.position_y >= 0 && per.position_y < 220){
				area = 1;
				scene = STATIC;
			}
			else if (per.position_y >= 220 && per.position_y < 700){
				area = 4;
				scene = X_SY_D;
			}
			else if (per.position_y >= 700){
				area = 7;
				scene = STATIC;
			}
		}
		else if (per.position_x >= 300 && per.position_x < 1580){
			if (per.position_y >= 0 && per.position_y < 220){
				area = 2;
				scene = X_DY_S;
			}
			else if (per.position_y >= 220 && per.position_y < 700){
				area = 5;
				scene = DYNAMIC;
			}
			else if (per.position_y >= 700){
				area = 8;
				scene = X_DY_S;
			}
		}
		else if (per.position_x >= 1580){
			if (per.position_y >= 0 && per.position_y < 220){
				area = 3;
				scene = STATIC;
			}
			else if (per.position_y >= 220 && per.position_y < 700){
				area = 6;
				scene = X_SY_D;
			}
			else if (per.position_y >= 700){
				area = 9;
				scene = STATIC;
			}
		}

		//�߳�ȥʱ�ٶȽ�Ϊ0
		if (scene == STATIC){
			if ((per.position_x + per.speed_x) >= 1920 - per.width){
				per.speed_x = 0;
			}
			else if ((per.position_x + per.speed_x) <= 0){
				per.speed_x = 0;
			}
			if ((per.position_y + per.speed_y) >= 960 - per.height){
				per.speed_y = 0;
			}
			else if ((per.position_y + per.speed_y) <= 0){
				per.speed_y = 0;
			}
		}
		else if (scene == X_SY_D){
			if (per.position_x + per.speed_x >= 1920 - per.width){
				per.stand();
			}
			else if (per.position_x + per.speed_x <= 0){
				per.stand();
			}
		}
		else if (scene == X_DY_S){
			if (per.position_y + per.speed_y >= 960 - per.height){
				per.stand();
			}
			else if (per.position_y + per.speed_y <= 0){
				per.stand();
			}
		}
		
		//�ߵ��ϰ�����ʱ�ٶȽ�Ϊ0
		if (barAry[(per.position_x + per.speed_x + per.width) / 4][(per.position_y + per.speed_y + per.height - 4) / 4] == 0){
			per.speed_x = 0;
			per.speed_y = 0;
		}

		//��������λ��
		per.position_x += per.speed_x;
		per.position_y += per.speed_y;
		per.position_x = per.position_x / 4 * 4;
		per.position_y = per.position_y / 4 * 4;

		//��������ƶ�
		switch (scene)
		{
		case STATIC:
			break;
		case X_SY_D:
			bac.position_y += (-per.speed_y);
			break;
		case X_DY_S:
			bac.position_x += (-per.speed_x);
			break;
		case DYNAMIC:
			bac.position_x += (-per.speed_x);
			bac.position_y += (-per.speed_y);
			break;
		default:
			break;
		}

		break;
	case 3:
		for (int i = 0; i < aniNum; i++){
			ani[i].turn();
			//����Ŀ�ĵ�ʱͣ
			if (ani[i].speed_x == 0 && ani[i].speed_y != 0){
				if ((ani[i].position_y - ani[i].aim_y) / ani[i].speed_y == 0){
					ani[i].stand();
				}
			}
			else if (ani[i].speed_y == 0 && ani[i].speed_x != 0){
				if ((ani[i].position_x - ani[i].aim_x) / ani[i].speed_x == 0){
					ani[i].stand();
				}
			}
			else if (ani[i].speed_x != 0 && ani[i].speed_y != 0){
				if ((ani[i].position_y - ani[i].aim_y) / ani[i].speed_y == 0 && (ani[i].position_x - ani[i].aim_x) / ani[i].speed_x == 0){
					ani[i].stand();
				}
			}

			if (scene == STATIC){
				//�߳�ȥʱ�ٶȽ�Ϊ0
				if (ani[i].speed_x > 0 && (ani[i].position_x + ani[i].speed_x) > 1920 - ani[i].width - 20){
					ani[i].stand();
					break;
				}
				else if (ani[i].speed_x < 0 && (ani[i].position_x + ani[i].speed_x) < 0){
					ani[i].stand();
					break;
				}
				if (ani[i].speed_y > 0 && (ani[i].position_y + ani[i].speed_y) > 960 - ani[i].height - 20){
					ani[i].stand();
					break;
				}
				else if (ani[i].speed_y < 0 && (ani[i].position_y + ani[i].speed_y) < 0){
					ani[i].stand();
					break;
				}
			}

			//�ߵ��ϰ�����ʱ�ٶȽ�Ϊ0
			switch (ani[i].direction)
			{
			case SOUTH:
				if (barAry[(ani[i].position_x + ani[i].speed_x) / 4][(ani[i].position_y + ani[i].speed_y + ani[i].height) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			case SOUTHWEST:
				if (barAry[(ani[i].position_x + ani[i].speed_x + ani[i].width) / 4][(ani[i].position_y + ani[i].speed_y + ani[i].height) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			case WEST :
				if (barAry[(ani[i].position_x + ani[i].speed_x + ani[i].width) / 4][(ani[i].position_y + ani[i].speed_y) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			case NORTHWEST:
				if (barAry[(ani[i].position_x + ani[i].speed_x) / 4][(ani[i].position_y + ani[i].speed_y) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			case NORTH:
				if (barAry[(ani[i].position_x + ani[i].speed_x) / 4][(ani[i].position_y + ani[i].speed_y) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			case NORTHEAST:
				if (barAry[(ani[i].position_x + ani[i].speed_x + ani[i].width) / 4][(ani[i].position_y + ani[i].speed_y) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			case EAST:
				if (barAry[(ani[i].position_x + ani[i].speed_x + ani[i].width) / 4][(ani[i].position_y + ani[i].speed_y) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			case SOUTHEAST:
				if (barAry[(ani[i].position_x + ani[i].speed_x + ani[i].width) / 4][(ani[i].position_y + ani[i].speed_y + ani[i].height) / 4] == 0){
					ani[i].speed_x = 0;
					ani[i].speed_y = 0;
				}
				break;
			default:
				break;
			}

			//��������λ��
			ani[i].position_x += ani[i].speed_x;
			ani[i].position_y += ani[i].speed_y;
			ani[i].position_x = ani[i].position_x / 4 * 4;
			ani[i].position_y = ani[i].position_y / 4 * 4;
		}
		break;
	case 4:
		for (int i = 0; i < aniNum; i++){
			if (CTool::Random(0, 5) > 1){
				ani[i].aim_x = CTool::Random(0, 1920) / 4 * 4;
				ani[i].aim_y = CTool::Random(0, 960) / 4 * 4;
				ani[i].move();
			}
			else{
				ani[i].stand();
			}
		}
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  ������ʱ����Ŀ�ĵأ�����ʼ�ƶ����������)

	//�����������λ�õ��������
	int mouse_x;
	int mouse_y;

	//��ʼ���������
	switch (area){
	case 1:
		mouse_x = per.position_x;
		mouse_y = per.position_y;
		break;
	case 2:
		mouse_x = 300;
		mouse_y = per.position_y;
		break;
	case 3:
		mouse_x = per.position_x - 1580 + 300;
		mouse_y = per.position_y;
		break;
	case 4:
		mouse_x = per.position_x;
		mouse_y = 220;
		break;
	case 5:
		mouse_x = 300;
		mouse_y = 220;
		break;
	case 6:
		mouse_x = per.position_x - 1580 + 300;
		mouse_y = 220;
		break;
	case 7:
		mouse_x = per.position_x;
		mouse_y = per.position_y - 700 + 220;
		break;
	case 8:
		mouse_x = 300;
		mouse_y = per.position_y - 700 + 220;
		break;
	case 9:
		mouse_x = per.position_x - 1580 + 300;
		mouse_y = per.position_y - 700 + 220;
		break;
	default:
		break;
	}
	/*
	��������������ʱ���ó�����ԵΪĿ�ĵ�
	����������ڲ�ʱ ���õ����ΪĿ�ĵ�
	*/
	if (point.x > 640){
		per.aim_x = (640 - mouse_x) + per.position_x;
	}
	else if (point.x < 0){
		per.aim_x = 0 - mouse_x + per.position_x;
	}
	else{
		per.aim_x = point.x - mouse_x + per.position_x;
	}
	
	if (point.y > 480){
		per.aim_y = (480 - mouse_y) + per.position_y;
	}
	else if (point.y < 0){
		per.aim_y = 0 - mouse_y + per.position_y;
	}
	else{
		per.aim_y = point.y - mouse_y + per.position_y;
	}

	//�����ƶ�
	per.aim_y = per.aim_y / 4 * 4;
	per.aim_x = per.aim_x / 4 * 4;
	per.move();
		
	CDialogEx::OnLButtonDown(nFlags, point);
}