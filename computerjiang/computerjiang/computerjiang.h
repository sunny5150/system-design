
// computerjiang.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CcomputerjiangApp:
// �йش����ʵ�֣������ computerjiang.cpp
//

class CcomputerjiangApp : public CWinApp
{
public:
	CcomputerjiangApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CcomputerjiangApp theApp;