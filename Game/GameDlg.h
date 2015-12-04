
// GameDlg.h : 头文件
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


// CGameDlg 对话框
class CGameDlg : public CDialogEx
{
// 构造
public:
	CGameDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GAME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CLoadPicture clp;//保存图片对象
	int contrul;//控制对象（0.动物 1.人）
	int perIndex;//播放人物图片的张数
	int animalIndex;//播放动物图片的张数
	int perN;//控制人物图片张数变化的循环变量
	int aniN;//控制动物图片张数变化的循环变量
	CPerson per;//人物对象
	int perNum;//人的数量
	CScenery sce[200];//静态景物对象
	int sceNum;//静态景物数量
	CAnimal ani[200];//动物对象
	int aniNum;//动物数量
	int num;//测试数据
	int aniIndex;//更改动物位置时使用的循环变量
	CClientDC* dc;
	HDC buffer_DC;//缓冲DC
	HDC hDCBitmap;
	HDC hDCBitmap_bac;//绘制大地图DC
	CRect recBackground;
	int worldWidth;
	int worldHeight;
	CBackground bac;//v2.0: 背景对象 用于背景移动
	int bacNum;
	int scene;//镜头状态
	CScenery wal[46];//城墙数组
	int walNum;//城墙数量
	int area;//人物所在区域(0-9)
	CBarrier bar[70];//障碍物
	int barNum;//障碍物数量
	HDC DC_barrier;//绘制障碍物DC
	int barAry[480][240];//逻辑上碰撞数组

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
