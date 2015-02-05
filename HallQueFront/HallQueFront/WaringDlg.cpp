// WaringDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HallQueFront.h"
#include "WaringDlg.h"


// CWaringDlg �Ի���

IMPLEMENT_DYNAMIC(CWaringDlg, CDialog)

CWaringDlg::CWaringDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWaringDlg::IDD, pParent)
{

}

CWaringDlg::~CWaringDlg()
{
}

void CWaringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STA_SHOWPIC, m_sta_showPic);
}


BEGIN_MESSAGE_MAP(CWaringDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CWaringDlg ��Ϣ�������

void CWaringDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	if(theApp.m_pView->m_showVaria.bShowNoPage)
	{
		if(!m_picImage.IsNull())
			m_picImage.Destroy();
		m_picImage.LoadFromResource(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_NOPAGE));
	}
	else if(theApp.m_pView->m_showVaria.bShowWait)
	{
		if(!m_picImage.IsNull())
			m_picImage.Destroy();
		m_picImage.LoadFromResource(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_WAIT));
	}
	else if (theApp.m_pView->m_showVaria.bSendMsg)
	{
		if(!m_picImage.IsNull())
			m_picImage.Destroy();
		m_picImage.LoadFromResource(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_SENDMSG));
	}
	CRect rect;
	m_sta_showPic.GetWindowRect(rect);
	ScreenToClient(rect);
	SetStretchBltMode(dc, COLORONCOLOR);//������ɫʧ��
	if(!m_picImage.IsNull())
		m_picImage.StretchBlt(dc,rect.left,rect.top,rect.Width(),rect.Height(),SRCCOPY);
}

BOOL CWaringDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_picImage.LoadFromResource(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_WAIT));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CWaringDlg::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���
	CDialog::PostNcDestroy();
}
