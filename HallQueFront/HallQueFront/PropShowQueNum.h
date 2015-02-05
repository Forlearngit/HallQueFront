#pragma once
#include "afxwin.h"
#include "ColorStatic.h"
#include "QueueInfo.h"
#include "CommonConvert.h"

// CPropShowQueNum �Ի���

class CPropShowQueNum : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropShowQueNum)

public:
	CPropShowQueNum();
	virtual ~CPropShowQueNum();

// �Ի�������
	enum { IDD = IDD_PROPSHOWQUENUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CColorStatic m_sta_textColor;
	CEdit m_ed_content;
	afx_msg void OnStnClickedStaColor();
	void InitInfo();
private:
	COLORREF m_textColor;
	CFont m_textFont;
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBnFont();
	CComboBox m_com_queInfo;
private:
	CMap<int,int,CQueueInfo,CQueueInfo&> m_map_que;
	void ReadQueInfoFromFile();
	CString m_infofile_path;//�����Ϣ���ļ���ַ
	CCommonConvert m_convert;
};
