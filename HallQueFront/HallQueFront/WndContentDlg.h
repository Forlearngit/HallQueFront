#pragma once
#include "resource.h"

// CWndContentDlg �Ի���

class CWndContentDlg : public CDialog
{
	DECLARE_DYNAMIC(CWndContentDlg)

public:
	CWndContentDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWndContentDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_WNDSCREEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
