// PropertyShortMsg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PropertyShortMsg.h"


// CPropertyShortMsg

IMPLEMENT_DYNAMIC(CPropertyShortMsg, CPropertySheet)

CPropertyShortMsg::CPropertyShortMsg(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	this->m_psh.dwFlags |= PSH_NOAPPLYNOW;
	this->m_psh.dwFlags &= ~PSP_HASHELP;
	m_dMsgSetDlg.m_psp.dwFlags &= ~PSP_HASHELP;
	m_dJudgeShortMsgDlg.m_psp.dwFlags &= ~PSP_HASHELP;
	AddPage(&m_dMsgSetDlg);
	AddPage(&m_dJudgeShortMsgDlg);
}

CPropertyShortMsg::CPropertyShortMsg(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	this->m_psh.dwFlags |= PSH_NOAPPLYNOW;
	this->m_psh.dwFlags &= ~PSP_HASHELP;
	m_dMsgSetDlg.m_psp.dwFlags &= ~PSP_HASHELP;
	m_dJudgeShortMsgDlg.m_psp.dwFlags &= ~PSP_HASHELP;
	AddPage(&m_dMsgSetDlg);
	AddPage(&m_dJudgeShortMsgDlg);
}

CPropertyShortMsg::~CPropertyShortMsg()
{
}


BEGIN_MESSAGE_MAP(CPropertyShortMsg, CPropertySheet)
END_MESSAGE_MAP()


// CPropertyShortMsg ��Ϣ�������

BOOL CPropertyShortMsg::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();

	// TODO:  �ڴ��������ר�ô���

	return bResult;
}
