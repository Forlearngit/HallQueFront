#pragma once
#include "HallQueFrontView.h"
#include "DoFile.h"

// CPassWordDlg �Ի���
// ��������Ի���
class CPassWordDlg : public CDialog
{
	DECLARE_DYNAMIC(CPassWordDlg)

public:
	CPassWordDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPassWordDlg();
	CString GetPassWord()const
	{
		return m_strPassWord;
	}

	void SetPassWord(const CString password)
	{
		m_strPassWord=password;
	}

	BOOL ReadPassWordIntoFile();
	CDoFile m_PswdFile;

// �Ի�������
	enum { IDD = IDD_PASSWORD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_strPassWord;
	CString m_strShowPassWord;
	CString m_infofile_path;
	CStatic m_KeyPic;
	BOOL m_bSuccess;
	BOOL ShowPhoto(CStatic& picPhoto);
public:
	afx_msg void OnBnClickedButtonSetpswd();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

	afx_msg void OnPaint();
	afx_msg void OnBnClickedBnNumone();
	afx_msg void OnBnClickedBnNumtwo();
	CEdit m_ed_passWord;
	afx_msg void OnBnClickedBnNumthree();
	afx_msg void OnBnClickedBnNumfour();
	afx_msg void OnBnClickedBnNumfive();
	afx_msg void OnBnClickedBnNumsix();
	afx_msg void OnBnClickedBnNumseven();
	afx_msg void OnBnClickedBnNumeight();
	afx_msg void OnBnClickedBnNumnine();
	afx_msg void OnBnClickedBnNumzero();
	afx_msg void OnBnClickedBncancel();
};
