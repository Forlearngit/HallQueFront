#pragma once
#include "afxwin.h"
#include "atlimage.h"


// CWaringDlg �Ի���

class CWaringDlg : public CDialog
{
	DECLARE_DYNAMIC(CWaringDlg)

public:
	CWaringDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWaringDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_WARING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CStatic m_sta_showPic;
private:
	CImage m_picImage;
protected:
	virtual void PostNcDestroy();
};
