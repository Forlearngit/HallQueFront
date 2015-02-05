#pragma once
#include "afxwin.h"
#include "ColorStatic.h"
#include "QueueInfo.h"
#include "CommonConvert.h"
#include <map>
using namespace std;
// CPropEdButton �Ի���

class CPropEdButton : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropEdButton)

public:
	CPropEdButton();
	virtual ~CPropEdButton();

// �Ի�������
	enum { IDD = IDD_PROPEDBUTTON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_com_trans;
	
	afx_msg void OnStnClickedStaColor();
	CColorStatic m_sta_color;
	afx_msg void OnBnClickedBnTitlefont();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CEdit m_ed_width;
	CEdit m_ed_height;
//	CEdit m_ed_title;
	CEdit m_ed_title;

	COLORREF m_bkColor;
	COLORREF m_textColor;
	CFont m_hTextFont;
	//��ʼ������
	void InitFont();
	//��ʼ����ť��info
	void InitButtonInfo();
	virtual BOOL OnApply();
	virtual void OnOK();
	///�ҵ�͸���Ȱ����������Ժ�
	int FindMinDvalue(int num[],int per,int size);
private:
	CMap<int,int,CQueueInfo,CQueueInfo&> m_map_que;//���ӵĶ���
	map<int,UINT> m_map_pageID;//���ӽ���ID
	void ReadQueInfoFromFile();
	CString m_infofile_path;//�����Ϣ���ļ���ַ
	CCommonConvert m_convert;
	CString m_BkPicPath;   //����ͼƬ��ַ
	CStatic m_sta_bkpic;
	BOOL LoadPicImage(CString PicPath);
	BOOL DrawImage(CWnd* pWnd);
	CImage m_img; 
public:
	CComboBox m_com_queInfo;
	afx_msg void OnBnClickedBtnSetbk();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtnClrbk();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
