#pragma once


// CSetTimeFormatDlg �Ի���

class CSetTimeFormatDlg : public CDialog
{
	DECLARE_DYNAMIC(CSetTimeFormatDlg)

public:
	CSetTimeFormatDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetTimeFormatDlg();

// �Ի�������
	enum { IDD = IDD_TIMEFORMAT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_TimeFormat_control;
	CString m_TimeFormat_Text;
	int   m_cursel;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
