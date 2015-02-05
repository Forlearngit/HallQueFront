#pragma once
#include "HallQueFrontView.h"
#include "DoFile.h"

// CPassWordChangeDlg �Ի���
//�޸�����Ի���
class CPassWordChangeDlg : public CDialog
{
	DECLARE_DYNAMIC(CPassWordChangeDlg)

public:
	CPassWordChangeDlg(CWnd* pParent);   // ��׼���캯��
	virtual ~CPassWordChangeDlg();
	BOOL WritePassWordIntoFile();
	CDoFile m_PswdFile;
// �Ի�������
	enum { IDD = IDD_PASSWORDCHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_strOldPassWord;
	CString m_strNewPassWord;
	CString m_infofile_path;
	CStatic m_KeyPic;
	BOOL ShowPhoto(CStatic& picPhoto);
	int m_iFocus;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnPaint();
	CEdit m_ed_OldPassWord;
	CEdit m_ed_NewPassWord;

	afx_msg void OnEnSetfocusEditOldpswd();
	afx_msg void OnEnSetfocusEditNewpswd();
	afx_msg void OnBnClickedBtn1();
	afx_msg void OnBnClickedBtn2();
	afx_msg void OnBnClickedBtn3();
	afx_msg void OnBnClickedBtn4();
	afx_msg void OnBnClickedBtn5();
	afx_msg void OnBnClickedBtn6();
	afx_msg void OnBnClickedBtn7();
	afx_msg void OnBnClickedBtn8();
	afx_msg void OnBnClickedBtn9();
	afx_msg void OnBnClickedBtn0();
	afx_msg void OnBnClickedBtnbk();
};
