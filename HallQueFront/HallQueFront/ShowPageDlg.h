#pragma once
#include "afxwin.h"
#include "OwnerDrawListBox.h"
#include <map>
using namespace std;

// CShowPageDlg �Ի���

class CShowPageDlg : public CDialog
{
	DECLARE_DYNAMIC(CShowPageDlg)

public:
	CShowPageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowPageDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	COwnerDrawListBox m_OwnerListBox;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBnAddpage();
	afx_msg void OnBnClickedBnDelpage();
	afx_msg void OnBnClickedBnTimehide();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	BOOL m_bIsHide;
	CRect m_rOldWindowRect;
	map<int,UINT> m_map_index;
	void ClearCtrlLinkPageID(UINT nPageID);//��ҳ��ɾ��ʱ,��չ����İ�ť���ҳ���ID
public:
	afx_msg void OnLbnSelchangeListPage();
protected:
	virtual void PostNcDestroy();
public:
	afx_msg void OnPaint();
	void SetBnTimeHide(BOOL isHide);
};
