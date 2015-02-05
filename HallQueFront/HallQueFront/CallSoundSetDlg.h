#pragma once
#include "ListBoxPlus.h"

// CCallSoundSetDlg �Ի���
//��ʹ��JTTS�����������µ��������öԻ���
class CCallSoundSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CCallSoundSetDlg)

public:
	CCallSoundSetDlg(CString& strConf,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCallSoundSetDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_CALLMSGSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	int SplitStringToArray(CString strSrc, CArray<CString>& arrStr);
public:
	CString& m_StrConf;
	CEdit m_editTextAdd;
	CListBox m_lbList;
	CButton m_check_mksndall;
	CButton m_Sel_CommonChinese;
	CButton m_Sel_English;
	BOOL m_bMksndall;
	afx_msg void OnBnClickedBtnAddtext();
	afx_msg void OnLbnSelchangeListSoundmsg();
	afx_msg void OnBnClickedBtnChangemsg();
	afx_msg void OnBnClickedBtnDeletemsg();
	afx_msg void OnBnClickedBtnQuenum();
	afx_msg void OnBnClickedBtnStaffname();
	afx_msg void OnBnClickedBtnWndname();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnUp();
	afx_msg void OnBnClickedBtnDown();
	afx_msg void OnBnClickedCheckMksdall();
	afx_msg void OnBnClickedBtnBusname();
};
