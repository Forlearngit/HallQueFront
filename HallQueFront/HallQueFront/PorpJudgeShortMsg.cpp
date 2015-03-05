// PorpJudgeShortMsg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PorpJudgeShortMsg.h"
#include "CommonConvert.h"
#include "DoFile.h"
#include "PropertyShortMsg.h"
#include "PropConnectInfo.h"

extern UINT g_JudgeShortMsgSerialID;
// CPorpJudgeShortMsg �Ի���

IMPLEMENT_DYNAMIC(CPorpJudgeShortMsg, CPropertyPage)

CPorpJudgeShortMsg::CPorpJudgeShortMsg()
	: CPropertyPage(CPorpJudgeShortMsg::IDD)
	,m_curSelectItem(-1)
	, m_ed_strPhoneNum(_T(""))
{
	CDoFile doFile;
	m_filePath = doFile.GetExeFullFilePath();
	m_filePath += _T("\\JudgeShortMsg");
	doFile.CreateMyDirectory(m_filePath);
	m_filePath += _T("\\JudgeShortMsg.dat");
}

CPorpJudgeShortMsg::~CPorpJudgeShortMsg()
{
	ReleaseShortMsg();
}

void CPorpJudgeShortMsg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_OPENSHORTMSG, m_check_openMsg);
	DDX_Control(pDX, IDC_EDIT_PHONENUM, m_ed_phoneNum);
	DDX_Control(pDX, IDC_LIST_CONTENT, m_listctr_content);
	DDX_Text(pDX, IDC_EDIT_PHONENUM, m_ed_strPhoneNum);
}


BEGIN_MESSAGE_MAP(CPorpJudgeShortMsg, CPropertyPage)
	ON_BN_CLICKED(IDC_BN_ADDMSG, &CPorpJudgeShortMsg::OnBnClickedBnAddmsg)
	ON_BN_CLICKED(IDC_BN_DELMSG, &CPorpJudgeShortMsg::OnBnClickedBnDelmsg)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CONTENT, &CPorpJudgeShortMsg::OnLvnItemchangedListContent)
	ON_EN_CHANGE(IDC_EDIT_PHONENUM, &CPorpJudgeShortMsg::OnEnChangeEditPhonenum)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CONTENT, &CPorpJudgeShortMsg::OnNMDblclkListContent)
END_MESSAGE_MAP()


// CPorpJudgeShortMsg ��Ϣ�������

void CPorpJudgeShortMsg::PreInitDialog()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertyPage::PreInitDialog();
}



void CPorpJudgeShortMsg::OnBnClickedBnAddmsg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strPhoneNum;
	m_ed_phoneNum.GetWindowText(strPhoneNum);
	if(strPhoneNum.IsEmpty())
	{
		MessageBox(_T("�绰���벻��Ϊ��"),_T("ע��"),MB_OK | MB_ICONINFORMATION);
		return;
	}

	list<CJudgeShortMsg*>::iterator itera = m_list_judgeMsg.begin();
	for(itera;itera!=m_list_judgeMsg.end();itera++)
	{
		CJudgeShortMsg* pMsg = *itera;
		if(strPhoneNum == pMsg->GetPhoneNum())
		{
			if(IDYES == MessageBox(_T("�绰�����ظ�,�Ƿ����"),_T("ע��"),MB_YESNO | MB_ICONQUESTION))
			{
				break;
			}
			else
			{
				return;
			}
		}
	}
	
	CJudgeShortMsg* pShortMsg = new CJudgeShortMsg;
	pShortMsg->SetPhoneNum(strPhoneNum);
	if(m_shortMsgContent.IsEmpty())
	{
		pShortMsg->SetShortMsg(_T("[���ں�][Ա������][Ա������]���ֲ���"));
	}
	m_list_judgeMsg.push_back(pShortMsg);
	//������ʾ
	CString strSerialID;
	strSerialID.Format(_T("%d"),pShortMsg->GetJudgeShortMsgSerialID());
	int count = m_listctr_content.GetItemCount();
	int nItem = 1;
	m_listctr_content.InsertItem(count,strSerialID);
	m_listctr_content.SetItemText(count,nItem++,pShortMsg->GetPhoneNum());
	m_listctr_content.SetItemText(count,nItem++,pShortMsg->GetShortMsg());

	m_ed_strPhoneNum = _T("");
	UpdateData(FALSE);
	m_listctr_content.SetItemState(count,LVIS_SELECTED,LVIS_SELECTED);
}

void CPorpJudgeShortMsg::OnBnClickedBnDelmsg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = m_listctr_content.GetFirstSelectedItemPosition();
	int index = m_listctr_content.GetNextSelectedItem(pos);
	if(index<0)
	{
		AfxMessageBox(_T("��ѡ�ж�������"));
		return;
	}
	int seralID = 0;
	CString strSerialID = m_listctr_content.GetItemText(m_curSelectItem,0);
	CCommonConvert::CStringToint(seralID,strSerialID);
	list<CJudgeShortMsg*>::iterator itera = m_list_judgeMsg.begin();
	for(itera;itera != m_list_judgeMsg.end();itera++)
	{
		CJudgeShortMsg* pJudgeShortMsg = *itera;
		if(seralID == pJudgeShortMsg->GetJudgeShortMsgSerialID())
		{
			delete pJudgeShortMsg;
			pJudgeShortMsg = NULL;
			m_list_judgeMsg.erase(itera);//��������ɾ��
			break;
		}
	}
	//����
	m_listctr_content.DeleteItem(m_curSelectItem);//����ɾ��
	//ɾ������ʱ�ѽ������������ϱ�
	if(index>0)
	{
		m_listctr_content.SetItemState(index-1,LVIS_SELECTED,LVIS_SELECTED);
	}
	else
	{
		m_listctr_content.SetItemState(0,LVIS_SELECTED,LVIS_SELECTED);
	}
}

BOOL CPorpJudgeShortMsg::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	m_listctr_content.GetClientRect(&rect);
	int nCol = 0;
	m_listctr_content.InsertColumn(nCol++,_T("���"),LVCFMT_CENTER,10*rect.Width()/100,-1);
	m_listctr_content.InsertColumn(nCol++,_T("�绰����"),LVCFMT_CENTER,30*rect.Width()/100,-1);
	m_listctr_content.InsertColumn(nCol++,_T("��������"),LVCFMT_CENTER,60*rect.Width()/100,-1);
	m_listctr_content.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	m_listctr_content.SetExtendedStyle(LVS_EX_GRIDLINES);//���������

	m_listctr_content.SetRowHeigt(15);
	m_listctr_content.SetFontHW(13, 0);

	ReadShortMsgFromFile();

	CPropertyShortMsg* pPropertyShortMsg = (CPropertyShortMsg*)GetParent();
	CPropConnectInfo* pPropConnectInfo = (CPropConnectInfo*)pPropertyShortMsg->GetParent();
	if(pPropConnectInfo->m_logicVariables.IsOpenJudgeShortMsg)
	{
		m_check_openMsg.SetCheck(BST_CHECKED);
	}
	else
	{
		m_check_openMsg.SetCheck(BST_UNCHECKED);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CPorpJudgeShortMsg::OnApply()
{
	// TODO: �ڴ����ר�ô����/����û���
	WriteShortMsgToFile();
	CPropertyShortMsg* pPropertyShortMsg = (CPropertyShortMsg*)GetParent();
	CPropConnectInfo* pPropConnectInfo = (CPropConnectInfo*)pPropertyShortMsg->GetParent();
	
	if(BST_CHECKED == m_check_openMsg.GetCheck())
	{
		pPropConnectInfo->m_logicVariables.IsOpenJudgeShortMsg = TRUE;
	}
	else
	{
		pPropConnectInfo->m_logicVariables.IsOpenJudgeShortMsg = FALSE;
	}
	return CPropertyPage::OnApply();
}

void CPorpJudgeShortMsg::OnLvnItemchangedListContent(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_curSelectItem = pNMLV->iItem;
	m_curSelectShortMsg = m_listctr_content.GetItemText(m_curSelectItem,2);
	*pResult = 0;
}

void CPorpJudgeShortMsg::ReleaseShortMsg()
{
	list<CJudgeShortMsg*>::iterator itera = m_list_judgeMsg.begin();
	for(itera;itera != m_list_judgeMsg.end();itera++)
	{
		CJudgeShortMsg* pJudgeShortMsg = *itera;
		delete pJudgeShortMsg;
		pJudgeShortMsg = NULL;
	}
	m_list_judgeMsg.clear();
}

void CPorpJudgeShortMsg::OnEnChangeEditPhonenum()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	/*
	if(m_curSelectItem < 0)return;
	CString strPhoneNum;
	m_ed_phoneNum.GetWindowText(strPhoneNum);
	
	CString strSerialID = m_listctr_content.GetItemText(m_curSelectItem,0);
	int nSerialID = -1;
	CCommonConvert::CStringToint(nSerialID,strSerialID);

	list<CJudgeShortMsg*>::iterator itera = m_list_judgeMsg.begin();
	for(itera;itera != m_list_judgeMsg.end();itera++)
	{
		CJudgeShortMsg* pShortMsg = *itera;
		if(pShortMsg->GetJudgeShortMsgSerialID() == nSerialID)
		{
			pShortMsg->SetPhoneNum(strPhoneNum);
			break;
		}
	}

	m_listctr_content.SetItemText(m_curSelectItem,1,strPhoneNum);
	*/
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CPorpJudgeShortMsg::OnNMDblclkListContent(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}

BOOL CPorpJudgeShortMsg::WriteShortMsgToFile()
{
	CFile file;
	CFileException e;
	if (file.Open(m_filePath,CFile::modeCreate|CFile::modeWrite,&e))
	{
		list<CJudgeShortMsg*>::const_iterator itera = m_list_judgeMsg.begin();
		for (itera;itera!=m_list_judgeMsg.end();itera++)
		{
			CArchive ar(&file,CArchive::store);
			ar<<*itera;
			ar.Close();
		}
		file.Close();
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	return FALSE;
}

BOOL CPorpJudgeShortMsg::ReadShortMsgFromFile()
{
	ReleaseShortMsg();
	CFile file;
	CFileException e;
	if (file.Open(m_filePath,CFile::modeRead,&e))
	{
		////ע�����л�������ָ������Ѿ��������ڴ�
		CJudgeShortMsg* pJudgeShortMsg = NULL;
		UINT cardConfigID = 0;
		CArchive ar(&file,CArchive::load);
		if (file.GetLength()) 
		{
			do
			{
				ar>>pJudgeShortMsg;
				if (pJudgeShortMsg)
				{
					//������ʾ
					CString strSerialID;
					strSerialID.Format(_T("%d"),pJudgeShortMsg->GetJudgeShortMsgSerialID());
					int count = m_listctr_content.GetItemCount();
					int nItem = 1;
					m_listctr_content.InsertItem(count,strSerialID);
					m_listctr_content.SetItemText(count,nItem++,pJudgeShortMsg->GetPhoneNum());
					m_listctr_content.SetItemText(count,nItem++,pJudgeShortMsg->GetShortMsg());

					m_list_judgeMsg.push_back(pJudgeShortMsg);
					cardConfigID = pJudgeShortMsg->GetJudgeShortMsgSerialID() > cardConfigID
						? pJudgeShortMsg->GetJudgeShortMsgSerialID() : cardConfigID;
				}
			}while(!ar.IsBufferEmpty());
		}
		ar.Close();
		file.Close();
		g_JudgeShortMsgSerialID = cardConfigID;
	}
	else return FALSE;
	return TRUE;
}

