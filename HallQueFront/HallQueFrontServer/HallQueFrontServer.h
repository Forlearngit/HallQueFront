// HallQueFrontServer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHallQueFrontServerApp:
// �йش����ʵ�֣������ HallQueFrontServer.cpp
//

class CHallQueFrontServerApp : public CWinApp
{
public:
	CHallQueFrontServerApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��
private:
	BOOL AddAutoRun(CString strValueName);

	DECLARE_MESSAGE_MAP()
};

extern CHallQueFrontServerApp theApp;