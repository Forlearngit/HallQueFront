// ShowWaitingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HallQueFront.h"
#include "ShowWaitingDlg.h"


// CShowWaitingDlg �Ի���

IMPLEMENT_DYNAMIC(CShowWaitingDlg, CDialog)

CShowWaitingDlg::CShowWaitingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowWaitingDlg::IDD, pParent)
{

}

CShowWaitingDlg::~CShowWaitingDlg()
{
}

void CShowWaitingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STA_SHOWWAITPIC, m_sta_showWaitPic);
}


BEGIN_MESSAGE_MAP(CShowWaitingDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CShowWaitingDlg ��Ϣ�������

BOOL CShowWaitingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_picImage.LoadFromResource(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP_LOGO));
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CShowWaitingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	CRect rect;
	m_sta_showWaitPic.GetWindowRect(rect);
	ScreenToClient(rect);
	SetStretchBltMode(dc, COLORONCOLOR);//������ɫʧ��
	if(!m_picImage.IsNull())
		m_picImage.StretchBlt(dc,rect.left,rect.top,rect.Width(),rect.Height(),SRCCOPY);
}
