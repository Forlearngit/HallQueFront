#pragma once
#include "HallQueFront.h"

// CMsgSetDlg �Ի���

class CMsgSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CMsgSetDlg)

public:
	CMsgSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMsgSetDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_MSGSET};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	CListBox m_list_Msg;
	CEdit m_edit_Msg;
	CString m_strMsgPath;
	CStringArray m_arr_Msg;
	BOOL WriteMsgIntoFile();
	BOOL ReadMsgFromFile();
public:
	afx_msg void OnBnClickedButtonAddmsg();
	afx_msg void OnBnClickedButtonDelmsg();
	afx_msg void OnLbnSelchangeListMsg();
	afx_msg void OnEnChangeEditMsg();
	afx_msg void OnBnClickedOk();
};
