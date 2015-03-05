// ShortMsgSetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ShortMsgSetDlg.h"
#include "CommonStrMethod.h"

// CShortMsgSetDlg �Ի���

IMPLEMENT_DYNAMIC(CShortMsgSetDlg, CDialog)

CShortMsgSetDlg::CShortMsgSetDlg(CWnd* pParent /*=NULL*/,CInlineQueData& rInlineQueData)
	: CDialog(CShortMsgSetDlg::IDD, pParent)
	,m_rInlineQueData(rInlineQueData)
{
	m_strMsgPath = CommonStrMethod::GetModuleDir() + L"ShortMsg\\";
	m_strMsgPath += L"ShortMsg.dat";
}

CShortMsgSetDlg::~CShortMsgSetDlg()
{
}

void CShortMsgSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_STATIC_CELLPHONE,m_sta_CellPhone);
	DDX_Control(pDX,IDC_STATIC_QUENUM,m_sta_QueNum);
	DDX_Control(pDX,IDC_STATIC_WAITNUM,m_sta_WaitNum);
//	DDX_Control(pDX,IDC_STATIC_MSG,m_sta_Msg);
	DDX_Control(pDX,IDC_EDIT_CELLPHONE,m_edit_CellPhone);
	DDX_Control(pDX,IDC_EDIT_QUENUM,m_edit_QueNum);
	DDX_Control(pDX,IDC_EDIT_WAITNUM,m_edit_WaitNum);
	DDX_Control(pDX,IDC_COMBO_MSG,m_com_Msg);
}


BEGIN_MESSAGE_MAP(CShortMsgSetDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CShortMsgSetDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CShortMsgSetDlg::OnBnClickedCancel)
	ON_EN_SETFOCUS(IDC_EDIT_CELLPHONE, &CShortMsgSetDlg::OnEnSetfocusEditCellphone)
	ON_EN_CHANGE(IDC_EDIT_CELLPHONE, &CShortMsgSetDlg::OnEnChangeEditCellphone)
	ON_EN_SETFOCUS(IDC_EDIT_QUENUM, &CShortMsgSetDlg::OnEnSetfocusEditQuenum)
	ON_EN_UPDATE(IDC_EDIT_QUENUM, &CShortMsgSetDlg::OnEnUpdateEditQuenum)
	ON_EN_SETFOCUS(IDC_EDIT_WAITNUM, &CShortMsgSetDlg::OnEnSetfocusEditWaitnum)
	ON_EN_UPDATE(IDC_EDIT_WAITNUM, &CShortMsgSetDlg::OnEnUpdateEditWaitnum)
END_MESSAGE_MAP()


// CShortMsgSetDlg ��Ϣ�������

BOOL CShortMsgSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ReadMsgInfoFromFile();
	m_sta_CellPhone.SetWindowText(L"");
//	m_sta_Msg.SetWindowText(L"");
	m_sta_QueNum.SetWindowText(L"");
	m_sta_WaitNum.SetWindowText(L"");
// 	CFont font;
// 	font.CreatePointFont(100,L"����");
// 	m_sta_CellPhone.SetFont(&font,TRUE);
// 	m_sta_Msg.SetFont(&font,TRUE);
// 	m_sta_QueNum.SetFont(&font,TRUE);
// 	m_sta_WaitNum.SetFont(&font,TRUE);
	return TRUE;
}
void CShortMsgSetDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd* pWnd = FindWindow(NULL,L"��Ļ����");
	if(pWnd)
	{
		::SendMessage(pWnd->m_hWnd,WM_DESTROY,0,0);
	}
	CString strWaitNum;
	CString strMsg;
	m_edit_CellPhone.GetWindowText(m_strPhoneNum);
	m_edit_QueNum.GetWindowText(m_strQueNum);
	m_edit_WaitNum.GetWindowText(strWaitNum);
	m_com_Msg.GetWindowText(m_strMsg);
	int ncount = m_strMsg.GetLength();
	if (m_strPhoneNum.IsEmpty()||m_strQueNum.IsEmpty()||strWaitNum.IsEmpty()||m_strMsg.IsEmpty())
	{
		return;
	}
	else
	{
		int icount;
		CCommonConvert::CStringToint(icount,strWaitNum);
		if (icount>0)
		{
			if (GetSendQueNum(m_strQueNum,icount))
			{
				if(m_rInlineQueData.AlterData(m_strQueNum,m_strPhoneNum,m_strMsg))
				{
					OnOK();
				}
				m_sta_WaitNum.SetWindowText(L"�ȴ�������д����");
			}
			else
			{
				m_sta_WaitNum.SetWindowText(L"�ȴ�������д����");
			}
		}
		else
		{
			m_sta_WaitNum.SetWindowText(L"�ȴ�������д����");
		}
	}
}

BOOL CShortMsgSetDlg::GetSendQueNum(CString& strQueNum,int iCount)
{
	int iSendQueNum = GetNumFromString(strQueNum)-iCount-1;
	if (iSendQueNum<=0)
	{
		return FALSE;
	}
	CString strFront = strQueNum.Left(1);
	strQueNum.Format(L"%03d",iSendQueNum);
	strQueNum = strFront+strQueNum;
	return TRUE;
}

int CShortMsgSetDlg::GetNumFromString(CString strNum)
{
	if (strNum==_T(""))
	{
		return 0;
	}
	CString strRealNum;
	int nStartNumIndex = strNum.FindOneOf(_T("0123456789"));
	strRealNum = strNum.Mid(nStartNumIndex);
	char szbuf[32] = {0};
	CCommonConvert::WChar2Char(szbuf, 32, strRealNum.GetBuffer());
	int nMaxID = ::atoi(szbuf);
	return nMaxID;
}

void CShortMsgSetDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd* pWnd = FindWindow(NULL,L"��Ļ����");
	if(pWnd)
	{
		::SendMessage(pWnd->m_hWnd,WM_DESTROY,0,0);
	}
	OnCancel();
}

void CShortMsgSetDlg::OnEnSetfocusEditCellphone()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strCellPhone;
	m_edit_CellPhone.GetWindowText(strCellPhone);
	if (strCellPhone.IsEmpty())
	{
		m_sta_CellPhone.SetWindowText(L"����д���ն��ŵĵ绰����");
	}

}

void CShortMsgSetDlg::OnEnChangeEditCellphone()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strCellPhone;
	m_edit_CellPhone.GetWindowText(strCellPhone);
	if (strCellPhone.IsEmpty())
	{
		m_sta_CellPhone.SetWindowText(L"����д���ն��ŵĵ绰����");
	}
	else
	{
		m_sta_CellPhone.SetWindowText(L"");
	}
}

void CShortMsgSetDlg::OnEnSetfocusEditQuenum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strQuenum;
	m_edit_QueNum.GetWindowText(strQuenum);
	if (strQuenum.IsEmpty())
	{
		m_sta_QueNum.SetWindowText(L"����д����ȡƱ����");
	}
}

void CShortMsgSetDlg::OnEnUpdateEditQuenum()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// �������� EM_SETEVENTMASK ��Ϣ���͵��ؼ���
	// ͬʱ�� ENM_UPDATE ��־�������㵽 lParam �����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strQuenum;
	m_edit_QueNum.GetWindowText(strQuenum);
	if (strQuenum.IsEmpty())
	{
		m_sta_QueNum.SetWindowText(L"����д����ȡƱ����");
	}
	else
	{
		m_sta_QueNum.SetWindowText(L"");
	}
}



void CShortMsgSetDlg::OnEnSetfocusEditWaitnum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strWaitNum;
	m_edit_WaitNum.GetWindowText(strWaitNum);
	if (strWaitNum.IsEmpty())
	{
		m_sta_WaitNum.SetWindowText(L"����д������ն���ʱ�Ŷӵ�������");
	}
}


void CShortMsgSetDlg::OnEnUpdateEditWaitnum()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// �������� EM_SETEVENTMASK ��Ϣ���͵��ؼ���
	// ͬʱ�� ENM_UPDATE ��־�������㵽 lParam �����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strWaitNum;
	m_edit_WaitNum.GetWindowText(strWaitNum);
	if (strWaitNum.IsEmpty())
	{
		m_sta_WaitNum.SetWindowText(L"����д������ն���ʱ�Ŷӵ�������");
	}
	else
	{
		m_sta_WaitNum.SetWindowText(L"");
	}
}

BOOL CShortMsgSetDlg::ReadMsgInfoFromFile()
{
	CFile file;
	CFileException e;
	if (file.Open(m_strMsgPath,CFile::modeRead,&e))
	{
		if (file.GetLength())
		{
			CArchive ar(&file,CArchive::load);
			CString strMsg=NULL;
			do 
			{
				ar>>strMsg;
				m_com_Msg.AddString(strMsg);
				strMsg=_T("");
			} while (!ar.IsBufferEmpty());
			ar.Close();
		}
		file.Close();
		return TRUE;
	}
	else return FALSE;
}
