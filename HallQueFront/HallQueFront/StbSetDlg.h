#pragma once


// CStbSetDlg �Ի���

class CStbSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CStbSetDlg)

public:
	CStbSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStbSetDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_STBSETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	
};
