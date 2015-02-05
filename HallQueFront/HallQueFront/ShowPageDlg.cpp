// ShowPageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HallQueFront.h"
#include "ShowPageDlg.h"
#include "TrackContrl.h"


// CShowPageDlg �Ի���
extern UINT g_nPageID;

IMPLEMENT_DYNAMIC(CShowPageDlg, CDialog)

CShowPageDlg::CShowPageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowPageDlg::IDD, pParent)
	, m_bIsHide(FALSE)
{

}

CShowPageDlg::~CShowPageDlg()
{
}

void CShowPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PAGE, m_OwnerListBox);
}


BEGIN_MESSAGE_MAP(CShowPageDlg, CDialog)
	ON_BN_CLICKED(IDC_BN_ADDPAGE, &CShowPageDlg::OnBnClickedBnAddpage)
	ON_BN_CLICKED(IDC_BN_DELPAGE, &CShowPageDlg::OnBnClickedBnDelpage)
	ON_BN_CLICKED(IDC_BN_TIMEHIDE, &CShowPageDlg::OnBnClickedBnTimehide)
	ON_WM_TIMER()
	ON_LBN_SELCHANGE(IDC_LIST_PAGE, &CShowPageDlg::OnLbnSelchangeListPage)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CShowPageDlg ��Ϣ�������

BOOL CShowPageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	list<CTrackContrl*>::const_iterator itera = theApp.m_pView->m_list_trackCtrl.begin();
	for(itera;itera!=theApp.m_pView->m_list_trackCtrl.end();itera++)
	{
		CTrackContrl* pTrackCtrl = *itera;
		if(pTrackCtrl->GetSerialID()==0)
		{
			int index = m_OwnerListBox.AddListBoxItem(_T("��ҳ��"),theApp.LoadIcon(IDI_ICON_PAGE));
			m_map_index[index] = pTrackCtrl->GetSerialID();//����
			m_OwnerListBox.SetCurSel(index);
			OnLbnSelchangeListPage();
		}
		else
		{
			CString strItemName;
			strItemName.Format(_T("ҳ��[%d]"),pTrackCtrl->GetSerialID());
			int index = m_OwnerListBox.AddListBoxItem(strItemName,theApp.LoadIcon(IDI_ICON_PAGE));
			m_map_index[index] = pTrackCtrl->GetSerialID();//����
			pTrackCtrl->SetAllCtrlHide();
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CShowPageDlg::OnBnClickedBnAddpage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nPageID++;
	CTrackContrl* pTrackCtrl = new CTrackContrl;
	ASSERT(pTrackCtrl!=NULL);
	pTrackCtrl->SetSerialID(g_nPageID);
	pTrackCtrl->Create(theApp.m_pView);
	theApp.m_pView->m_list_trackCtrl.push_back(pTrackCtrl);
	CString strName;
	strName.Format(_T("ҳ��[%d]"),g_nPageID);
	int index = m_OwnerListBox.AddListBoxItem(strName,theApp.LoadIcon(IDI_ICON_PAGE));
	m_map_index[index]=g_nPageID;//����
}

void CShowPageDlg::OnBnClickedBnDelpage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(IDYES!=theApp.m_pView->MessageBox(_T("ɾ����ҳ�潫ɾ��ҳ������������,ȷ��ɾ��?"),_T("ע��"),MB_YESNO |
		MB_ICONQUESTION))
		return;
	int nIndex = m_OwnerListBox.GetCurSel();
	if(nIndex==CB_ERR)return;
	m_OwnerListBox.DeleteListBoxItem(nIndex);
	map<int,UINT>::const_iterator itera = m_map_index.find(nIndex);
	if(itera!=m_map_index.end())
	{
		list<CTrackContrl*>::const_iterator trakItera = theApp.m_pView->m_list_trackCtrl.begin();
		for(trakItera;trakItera!=theApp.m_pView->m_list_trackCtrl.end();trakItera++)
		{
			CTrackContrl* ptrackCtr = *trakItera;
			if(ptrackCtr->GetSerialID()==itera->second && ptrackCtr->GetSerialID()!=0)
			{
				UINT nDelPageID = ptrackCtr->GetSerialID();
				delete ptrackCtr;
				ptrackCtr = NULL;
				////��Ӧ�ĵ�ǰѡ���pTrackCtr�ÿ�,��Ϊɾ��ʱѡ���pTrackCtr������
				theApp.m_pView->m_pTrackCtrl=NULL;
				////////////////////////////////////
				theApp.m_pView->m_list_trackCtrl.erase(trakItera);
				/////////////////////////////////////////////////////
				ClearCtrlLinkPageID(nDelPageID);//���ù������ҳ��İ�ť
				/////////////////////////////////////////////////////
				break;
			}
		}
	}
	m_map_index.clear();
	list<CTrackContrl*>::const_iterator secondItera = theApp.m_pView->m_list_trackCtrl.begin();
	int count = m_OwnerListBox.GetCount();
	for(int i=0;i<count;i++)
	{
		if(secondItera!=theApp.m_pView->m_list_trackCtrl.end())
		{
			CTrackContrl* pSecondTrackCtrl = *secondItera;
			ASSERT(pSecondTrackCtrl!=NULL);
			m_map_index[i] = pSecondTrackCtrl->GetSerialID();
		}
		secondItera++;
	}
	if(count>0&&nIndex>0)m_OwnerListBox.SetCurSel(nIndex-1);
	OnLbnSelchangeListPage();
//	theApp.m_pView->ShowPage(0);
}

void CShowPageDlg::OnBnClickedBnTimehide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	SetTimer(TIMEHIDESHOW,1000,NULL);
	if(!m_bIsHide)
	{
		CRect windowRect;
		GetWindowRect(windowRect);
		m_rOldWindowRect = windowRect;//����ԭ����rect
		CRect listBoxRect;
		m_OwnerListBox.GetWindowRect(listBoxRect);
		ScreenToClient(listBoxRect);
		windowRect.left-=listBoxRect.right;
		windowRect.right-=listBoxRect.right;
		MoveWindow(windowRect);
		CButton* pButton = (CButton*)GetDlgItem(IDC_BN_TIMEHIDE);
		pButton->SetWindowText(_T(">"));
		m_bIsHide=!m_bIsHide;
	}
	else
	{
		MoveWindow(m_rOldWindowRect);
		CButton* pButton = (CButton*)GetDlgItem(IDC_BN_TIMEHIDE);
		pButton->SetWindowText(_T("<"));
		m_bIsHide=!m_bIsHide;
	}
}

void CShowPageDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialog::OnTimer(nIDEvent);
}

void CShowPageDlg::OnLbnSelchangeListPage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = m_OwnerListBox.GetCurSel();
	if(index==CB_ERR)return;
	map<int,UINT>::const_iterator itera = m_map_index.find(index);
	if(itera!=m_map_index.end())
	{
		list<CTrackContrl*>::const_iterator trakItera = theApp.m_pView->m_list_trackCtrl.begin();
		for(trakItera;trakItera!=theApp.m_pView->m_list_trackCtrl.end();trakItera++)
		{
			CTrackContrl* ptrackCtr = *trakItera;
			if(ptrackCtr->GetSerialID()==itera->second && ptrackCtr->GetSerialID()==0)
			{
				CButton* pDelButton = (CButton*)GetDlgItem(IDC_BN_DELPAGE);
				pDelButton->EnableWindow(FALSE);
// 				if(theApp.m_pView->m_pTrackCtrl!=NULL)
// 					theApp.m_pView->m_pTrackCtrl->SetAllCtrlHide();//ԭ��������
// 				theApp.m_pView->m_pTrackCtrl = ptrackCtr;
// 				theApp.m_pView->m_pTrackCtrl->SetAllCtrlShow();
				theApp.m_pView->ShowPage(ptrackCtr->GetSerialID());
//				theApp.m_pView->Invalidate(TRUE);
				break;
			}
			else if(ptrackCtr->GetSerialID()==itera->second && ptrackCtr->GetSerialID()!=0)
			{
				theApp.m_pView->ShowPage(ptrackCtr->GetSerialID());
				CButton* pDelButton = (CButton*)GetDlgItem(IDC_BN_DELPAGE);
				pDelButton->EnableWindow(TRUE);
// 				if(theApp.m_pView->m_pTrackCtrl!=NULL)
// 					theApp.m_pView->m_pTrackCtrl->SetAllCtrlHide();//ԭ��������
// 				theApp.m_pView->m_pTrackCtrl = ptrackCtr;
// 				theApp.m_pView->m_pTrackCtrl->SetAllCtrlShow();
// 				theApp.m_pView->Invalidate(TRUE);
				break;
			}
			/*
			if(ptrackCtr->GetSerialID()==0)//��ҳ�治��ɾ��
			{
				CButton* pDelButton = (CButton*)GetDlgItem(IDC_BN_DELPAGE);
				pDelButton->EnableWindow(FALSE);
			}
			else
			{
				CButton* pDelButton = (CButton*)GetDlgItem(IDC_BN_DELPAGE);
				pDelButton->EnableWindow(TRUE);
			}
			if(ptrackCtr->GetSerialID()==itera->second)
			{
				theApp.m_pView->m_pTrackCtrl->SetAllCtrlHide();//ԭ��������
				theApp.m_pView->m_pTrackCtrl = ptrackCtr;
				theApp.m_pView->m_pTrackCtrl->SetAllCtrlShow();
				theApp.m_pView->Invalidate(TRUE);
				break;
			}
			*/
		}
	}
}

void CShowPageDlg::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���
//	delete this;
	CDialog::PostNcDestroy();
}

void CShowPageDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	map<int,UINT>::const_iterator itera = m_map_index.begin();
	for(itera;itera!=m_map_index.end();itera++)
	{
		if(theApp.m_pView->m_pTrackCtrl->GetSerialID() == itera->second)
		{
			m_OwnerListBox.SetCurSel(itera->first);
			OnLbnSelchangeListPage();
			break;
		}
	}
}

void CShowPageDlg::ClearCtrlLinkPageID(UINT nPageID)
{
	list<CTrackContrl*>::const_iterator itera = theApp.m_pView->m_list_trackCtrl.begin();
	for(itera;itera!=theApp.m_pView->m_list_trackCtrl.end();itera++)
	{
		CTrackContrl* pTrackContrl = *itera;
		pTrackContrl->SetAllCtrlLinkPageIDNULL(nPageID);
	}
}

void CShowPageDlg::SetBnTimeHide(BOOL isHide)
{
	m_bIsHide = isHide;
}