
// computerjiangDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include<thread> 
#include <windows.h>

#include <mmsystem.h>

#pragma comment(lib, "WINMM.LIB")

// CcomputerjiangDlg �Ի���
class CcomputerjiangDlg : public CDialogEx
{
// ����
public:
	CcomputerjiangDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_COMPUTERJIANG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	HANDLE hThread;
	DWORD ThreadID;  
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedHidden();
	CStatic m_show;
	std::thread thread1; 

	void shijian();

	afx_msg void OnBnClickedCancel();
};
