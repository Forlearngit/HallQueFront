#pragma once
#include "afxwin.h"
#include "atlimage.h"


// CShowWaitingDlg �Ի���

class CShowWaitingDlg : public CDialog
{
	DECLARE_DYNAMIC(CShowWaitingDlg)

public:
	CShowWaitingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowWaitingDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_WAITING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_sta_showWaitPic;
private:
	CImage m_picImage;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
