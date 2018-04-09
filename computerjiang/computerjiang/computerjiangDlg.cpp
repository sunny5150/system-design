
// computerjiangDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "computerjiang.h"
#include "computerjiangDlg.h"
#include "afxdialogex.h"
#include<thread> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
volatile BOOL m_bRun;  

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CcomputerjiangDlg 对话框



CcomputerjiangDlg::CcomputerjiangDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcomputerjiangDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CcomputerjiangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW, m_show);

}

BEGIN_MESSAGE_MAP(CcomputerjiangDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_HIDDEN, &CcomputerjiangDlg::OnBnClickedHidden)

	ON_BN_CLICKED(IDCANCEL, &CcomputerjiangDlg::OnBnClickedCancel)

END_MESSAGE_MAP()


// CcomputerjiangDlg 消息处理程序

BOOL CcomputerjiangDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	thread1=std::thread([&]{shijian();});
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcomputerjiangDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcomputerjiangDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcomputerjiangDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool flag=true;
int hour=1;
int minute=0;


void CcomputerjiangDlg::OnBnClickedHidden()
{
	

	// TODO: 在此添加控件通知处理程序代码
}








void CcomputerjiangDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=false;
	thread1.detach();
	CDialogEx::OnCancel();
}



void CcomputerjiangDlg::shijian()
{
	CTime m_begintime;
	m_begintime=CTime::GetCurrentTime(); 
	SYSTEMTIME sys;
	CString txt_show;
	txt_show.Format(L"蕾姆欢迎您的光临❤");  
			SetDlgItemText(IDC_EDIT1, txt_show);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE5),AfxGetResourceHandle(), SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);
	Sleep(5000);
	GetLocalTime(&sys);
	if(sys.wDayOfWeek==0)
		sys.wDayOfWeek=7;
	txt_show.Format(L"主人您于%4d/%02d/%02d %02d:%02d:%02d 星期%1d上机", sys.wYear,	sys.wMonth,		sys.wDay, sys.wHour, sys.wMinute, sys.wSecond,sys.wDayOfWeek);
	SetDlgItemText(IDC_EDIT1, txt_show);
	while(flag)
	{
		SYSTEMTIME sys;  
        CString txt_show;  
        GetLocalTime(&sys);  
        txt_show.Format(L"现在是%4d/%02d/%02d %02d:%02d:%02d 星期%1d", sys.wYear, sys.wMonth, sys.wDay,		sys.wHour, sys.wMinute, sys.wSecond, sys.wDayOfWeek);  
        SetDlgItemText(IDC_EDIT2, txt_show);  
		CTime m_endtime = CTime::GetCurrentTime();//当前时间  
        CTimeSpan span;  
        span = m_endtime - m_begintime;  
		txt_show.Format(L"我已陪伴主人❤%2d小时 %2d分 %2d秒❤",  span.GetHours(), int(span.GetMinutes()), int(span.GetSeconds()));  
		SetDlgItemText(IDC_EDIT3, txt_show);  
		if(span.GetHours()%1==0 && int(span.GetMinutes())==0 && int(span.GetSeconds())==0)
		{
			txt_show.Format(L"主人已经连续工作了1小时了，不妨起身活动一下❤");  
			SetDlgItemText(IDC_EDIT4, txt_show);
			PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetResourceHandle(), SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);
			txt_show.Format(L"请不要过于勉强，身体是最重要的哦❤");  
			SetDlgItemText(IDC_EDIT5, txt_show);
			Sleep(3900); 
			PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetResourceHandle(), SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);
			txt_show.Format(L"接下来可能休息不了哦，趁现在活动一下把❤");  
			SetDlgItemText(IDC_EDIT5, txt_show);
			Sleep(3000); 
			PlaySound(MAKEINTRESOURCE(IDR_WAVE3),AfxGetResourceHandle(), SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);
			txt_show.Format(L"如果能有帮得上忙的地方的话，蕾姆愿意帮助主人哦❤");  
			SetDlgItemText(IDC_EDIT5, txt_show);
			Sleep(3600); 
			PlaySound(MAKEINTRESOURCE(IDR_WAVE4),AfxGetResourceHandle(), SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);
			txt_show.Format(L"蕾姆会在这里安心等待主人的回来❤");  
			SetDlgItemText(IDC_EDIT5, txt_show);
			Sleep(3700); 	
		}
		else
		{
			txt_show.Format(L""); 
			SetDlgItemText(IDC_EDIT4, txt_show);
			SetDlgItemText(IDC_EDIT5, txt_show);
			sndPlaySound(NULL,SND_ASYNC | SND_LOOP);
		}

		Sleep(1000); 
			
	}
}




