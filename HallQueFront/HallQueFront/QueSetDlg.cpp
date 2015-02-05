// QueSetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HallQueFront.h"
#include "QueSetDlg.h"
#include "QueueInfo.h"
#include "CascadeMethod.h"


// CQueSetDlg �Ի���

IMPLEMENT_DYNAMIC(CQueSetDlg, CDialog)

CQueSetDlg::CQueSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueSetDlg::IDD,pParent)
	, m_cs_quename(_T(""))
	, m_cs_callname(_T(""))
	, m_cs_queid(_T(""))
	, m_cs_frontid(_T(""))
	, m_cs_numstart(_T(""))
	, m_cs_numend(_T(""))
	, m_cs_amlimit(_T(""))
	, m_cs_pmlimit(_T(""))
	, m_cs_daylimit(_T(""))
	, m_ReadMaxSerialID(0)
	, m_cs_queManNum(_T(""))
{
	m_infofile_path=m_dealFile.GetExeFullFilePath();//�����ļ���Ϣ
	m_infofile_path+=_T("\\QueBasicInfo");
	m_dealFile.CreateMyDirectory(m_infofile_path);
	m_maxnumfile_path = m_infofile_path + _T("\\maxnum.dat");
	m_infofile_path+=_T("\\QueBasicInfo.dat");
	
}

CQueSetDlg::~CQueSetDlg()
{
}

//������ؼ�����
void CQueSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_QUENAME, m_listctr_quename);
	DDX_Control(pDX, IDC_TIMESTART, m_timectrl_start);
	DDX_Control(pDX, IDC_TIMEEND, m_timectrl_end);
	DDX_Text(pDX, IDC_ED_QUENAME, m_cs_quename);
	DDX_Text(pDX, IDC_ED_CALLNAME, m_cs_callname);
	DDX_Text(pDX, IDC_ED_QUEID, m_cs_queid);
	DDX_Text(pDX, IDC_ED_FRONTID, m_cs_frontid);
	DDX_Text(pDX, IDC_ED_QUENUMSTART, m_cs_numstart);
	DDX_Text(pDX, IDC_ED_QUENUMEND, m_cs_numend);
	DDX_Text(pDX, IDC_ED_AMLIMIT, m_cs_amlimit);
	DDX_Text(pDX, IDC_ED_PMLIMIT, m_cs_pmlimit);
	DDX_Text(pDX, IDC_ED_DAYLIMIT, m_cs_daylimit);

	DDX_Control(pDX, IDC_ED_QUESERIALID, m_ed_queSerialID);
	DDX_Text(pDX, IDC_ED_QUESERIALID, m_cs_queManNum);
}


BEGIN_MESSAGE_MAP(CQueSetDlg, CDialog)
	ON_BN_CLICKED(IDC_BN_ADDQUEUE, &CQueSetDlg::OnBnClickedBnAddqueue)
	ON_LBN_SELCHANGE(IDC_LIST_QUENAME, &CQueSetDlg::OnLbnSelchangeListQuename)
	ON_BN_CLICKED(IDC_BN_DELQUEUE, &CQueSetDlg::OnBnClickedBnDelqueue)
	ON_EN_CHANGE(IDC_ED_AMLIMIT, &CQueSetDlg::OnEnChangeEdAmlimit)
	ON_EN_CHANGE(IDC_ED_PMLIMIT, &CQueSetDlg::OnEnChangeEdPmlimit)
	ON_EN_CHANGE(IDC_ED_DAYLIMIT, &CQueSetDlg::OnEnChangeEdDaylimit)
	ON_EN_CHANGE(IDC_ED_QUENAME, &CQueSetDlg::OnEnChangeEdQuename)
	ON_EN_CHANGE(IDC_ED_CALLNAME, &CQueSetDlg::OnEnChangeEdCallname)
	ON_EN_CHANGE(IDC_ED_FRONTID, &CQueSetDlg::OnEnChangeEdFrontid)
	ON_EN_CHANGE(IDC_ED_QUENUMSTART, &CQueSetDlg::OnEnChangeEdQuenumstart)
	ON_EN_CHANGE(IDC_ED_QUENUMEND, &CQueSetDlg::OnEnChangeEdQuenumend)
	ON_BN_CLICKED(IDC_BN_OK, &CQueSetDlg::OnBnClickedBnOk)
	ON_BN_CLICKED(IDC_BN_CANCLE, &CQueSetDlg::OnBnClickedBnCancle)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TIMESTART, &CQueSetDlg::OnDtnDatetimechangeTimestart)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_TIMEEND, &CQueSetDlg::OnDtnDatetimechangeTimeend)
	ON_EN_CHANGE(IDC_ED_QUESERIALID, &CQueSetDlg::OnEnChangeEdQueserialid)
END_MESSAGE_MAP()




// CQueSetDlg ��Ϣ�������
BOOL CQueSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CTime time1(1998, 4, 3, 0, 0, 0);
	m_timectrl_start.SetTime(&time1);
	m_timectrl_end.SetTime(&time1);
	ReadMaxIdFromFile();
	ReadQueBasicInfoFromFile();
	int nLast=m_listctr_quename.GetCount();
	if (nLast>0)
	{
		m_listctr_quename.SetCurSel(0); //���ý��㵽�ؼ�ĩβ
	}
	OnLbnSelchangeListQuename();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
extern unsigned int gobal_queserial_id;

// ������Ӷ��а�ť
void CQueSetDlg::OnBnClickedBnAddqueue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	gobal_queserial_id++;
	CQueueInfo queinfo;
	CString n_QueName=_T("����");
	n_QueName.AppendFormat(_T("%d"),gobal_queserial_id);
	queinfo.SetBussName(n_QueName);
	queinfo.SetQueCallName(n_QueName);
	CString queid;
	m_convert.intToCString(gobal_queserial_id,queid);
	queinfo.SetQueID(queid);

	m_list_queinfo.AddTail(queinfo);
	m_listctr_quename.AddString(n_QueName);
	int nLast=m_listctr_quename.GetCount()-1;
	if (nLast>=0)
	{
		m_listctr_quename.SetCurSel(nLast); //���ý��㵽�ؼ�ĩβ
	}
	OnLbnSelchangeListQuename();
	/*SetModified();*/
}

//ѡ����б���ı���Ӧ����
void CQueSetDlg::OnLbnSelchangeListQuename()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = m_listctr_quename.GetCurSel();
	if(index==CB_ERR)
	{
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo =m_list_queinfo.GetAt(pos); //ȡ������������Ӧ�Ķ�����Ϣ
	m_cs_quename=queinfo.GetBussName();
	m_cs_queid=queinfo.GetQueID();
	m_cs_callname=queinfo.GetQueCallName();
	m_cs_frontid=queinfo.GetFrontID();

	CString amlimit,pmlimit,daylimit,numstart,numend;
	amlimit.Format(_T("%d"),queinfo.GetAmLimitCustomer());
	pmlimit.Format(_T("%d"),queinfo.GetPmLimitCustomer());
	daylimit.Format(_T("%d"),queinfo.GetDayLimitCustomer());
	numstart.Format(_T("%d"),queinfo.GetQueNumStart());
	numend.Format(_T("%d"),queinfo.GetQueNumEnd());
	CTime* workstart=&(queinfo.GetQueWorkTimeStart());
	CTime* workend=&(queinfo.GetQueWorkTimeEnd());
	m_timectrl_start.SetTime(workstart);
	m_timectrl_end.SetTime(workend);
	if (numstart==_T("0"))
	{
		numstart = _T("��");
	}
	if (numend==_T("0"))
	{
		numend = _T("��");
	}
	m_cs_amlimit=amlimit;
	m_cs_pmlimit=pmlimit;
	m_cs_daylimit=daylimit;
	m_cs_numstart=numstart;
	m_cs_numend=numend;
	m_cs_queManNum = queinfo.GetQueManNum();
	UpdateData(FALSE);
}

//���ɾ������
void CQueSetDlg::OnBnClickedBnDelqueue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = m_listctr_quename.GetCurSel();
	int count=m_listctr_quename.GetCount();
	if(count<=0)
	{
		return;
	}
	if(index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	m_DeleteQueidArr.Add(m_list_queinfo.GetAt(pos).GetQueID());
	m_list_queinfo.RemoveAt(pos);
	m_listctr_quename.DeleteString(index);
	
	if(m_listctr_quename.GetCount()>0)
	{
		m_listctr_quename.SetCurSel(m_list_queinfo.GetCount()-1);
		OnLbnSelchangeListQuename();
	}
	else
	{
		SetEdctrNull();
		UpdateData(FALSE);
	}
	/*SetModified();*/
}
void CQueSetDlg::SetEdctrNull()
{
	m_cs_amlimit=_T("");m_cs_pmlimit=_T("");
	m_cs_daylimit=_T("");m_cs_frontid=_T("");
	m_cs_numend=_T("");m_cs_numstart=_T("");
	m_cs_queid=_T("");m_cs_quename=_T("");
	m_cs_frontid=_T("");m_cs_callname=_T("");
	CTime time1(1998, 4, 3, 0, 0, 0);
	m_timectrl_start.SetTime(&time1);
	m_timectrl_end.SetTime(&time1);
}

// �༭�������������ؼ�
void CQueSetDlg::OnEnChangeEdAmlimit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if (index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	int amlimit=0;
	m_convert.CStringToint(amlimit,m_cs_amlimit);
	queinfo.SetAmLimitCustomer(amlimit);
	m_list_queinfo.GetAt(pos)=queinfo;
	OnLbnSelchangeListQuename();
	/*SetModified();*/
}

//�༭������������
void CQueSetDlg::OnEnChangeEdPmlimit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if (index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	int pmlimit=0;
	m_convert.CStringToint(pmlimit,m_cs_pmlimit);
	queinfo.SetPmLimitCustomer(pmlimit);
	m_list_queinfo.GetAt(pos)=queinfo;
	OnLbnSelchangeListQuename();
	/*SetModified();*/
}

//�༭����ȫ�������ؼ�
void CQueSetDlg::OnEnChangeEdDaylimit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if (index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	int daylimit=0;
	m_convert.CStringToint(daylimit,m_cs_daylimit);
	queinfo.SetDayLimitCustomer(daylimit);
	m_list_queinfo.GetAt(pos)=queinfo;
	/*SetModified();*/
}

//�༭�޸�ҵ������
void CQueSetDlg::OnEnChangeEdQuename()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if(index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	queinfo.SetBussName(m_cs_quename);
	
	m_listctr_quename.DeleteString(index);
	m_listctr_quename.InsertString(index,m_cs_quename);
	m_listctr_quename.SetCurSel(index);
	m_list_queinfo.SetAt(pos,queinfo);

	/*SetModified();*/
}

//�༭���ú������ƿؼ�
void CQueSetDlg::OnEnChangeEdCallname()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if(index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	queinfo.SetQueCallName(m_cs_callname);
	m_list_queinfo.SetAt(pos,queinfo);

	/*SetModified();*/
	
}

//�༭���ö���ID�ؼ�


void CQueSetDlg::OnEnChangeEdFrontid()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if(index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	queinfo.SetFrontID(m_cs_frontid);
	m_list_queinfo.GetAt(pos)=queinfo;
	/*SetModified();*/
}




void CQueSetDlg::OnEnChangeEdQuenumstart()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if(index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	int numstart=0;
	m_convert.CStringToint(numstart,m_cs_numstart);
	queinfo.SetQueNumStart(numstart);
	m_list_queinfo.GetAt(pos)=queinfo;
	/*SetModified();*/
}

void CQueSetDlg::OnEnChangeEdQuenumend()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if(index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	int numend=0;
	m_convert.CStringToint(numend,m_cs_numend);
	queinfo.SetQueNumEnd(numend);
	m_list_queinfo.GetAt(pos)=queinfo;
	/*SetModified();*/
}
extern void MyWriteConsole(CString str);

BOOL CQueSetDlg::WriteQueBasicInfoToFile()
{
// #ifdef _DEBUG
// 	m_ComputerTime.SetStartTime(clock());
// #endif
	CFile file;
	CFileException e;
	if (file.Open(m_infofile_path,CFile::modeCreate|CFile::modeWrite,&e))
	{
		int count=m_list_queinfo.GetCount();
		for (int i=0;i<count;i++)
		{
			CArchive ar(&file,CArchive::store);
			CQueueInfo queinfo;
			POSITION pos = m_list_queinfo.FindIndex(i);
			if(pos)
			{
				queinfo=m_list_queinfo.GetAt(pos);
				ar<<&queinfo;
			}
			ar.Close();
		}
		/*UINT* pqueserial_id = &gobal_queserial_id;
		file.Write(pqueserial_id,sizeof(UINT));*/
		
		file.Close();

// #ifdef _DEBUG
// 		m_ComputerTime.SetFinshTime(clock());
// 		CString MyClock;
// 		MyClock.Format(_T("%f"),m_ComputerTime.GetDuration());
// 		MyWriteConsole(_T("CArchive:")+MyClock);
// #endif
		return TRUE;
	}
	else
	{
		TRACE(_T("File could not be opened %d\n"), e.m_cause);
		return FALSE;
	}
}

BOOL CQueSetDlg::ReadQueBasicInfoFromFile()
{
	m_list_queinfo.RemoveAll();
	CFile file;
	CFileException e;
	if (file.Open(m_infofile_path,CFile::modeRead,&e))
	{
		CQueueInfo* queinfo=NULL;
		
		if (file.GetLength()) 
		{
			CArchive ar(&file,CArchive::load);
			do
			{
				ar>>queinfo;
				if (queinfo)
				{
					m_listctr_quename.AddString(queinfo->GetBussName());
					m_list_queinfo.AddTail(*queinfo);
					int queid;
					m_convert.CStringToint(queid,queinfo->GetQueID());
					/*m_ReadMaxSerialID=m_ReadMaxSerialID>queid?
m_ReadMaxSerialID:queid;*/
					delete queinfo;
					queinfo = NULL;
				}
			}while(!ar.IsBufferEmpty());
			ar.Close();
			file.Close();
		}
		
		/*UINT* pserial_id=new UINT;
		file.Read(pserial_id,sizeof(UINT));
		gobal_queserial_id = *pserial_id;*/
		/*gobal_queserial_id=m_ReadMaxSerialID;*/
	}
	else return FALSE;
	return TRUE;
}
// BOOL CQueSetDlg::OnApply()
// {
// 	WriteQueBasicInfoToFile();
// 	return CPropertyPage::OnApply();
// }

BOOL CQueSetDlg::WriteMaxIdToFile()
{
	CFile file;
	CFileException e;
	if (file.Open(m_maxnumfile_path,CFile::modeCreate|CFile::modeWrite,&e))
	{
		UINT iMaxId = gobal_queserial_id;
		file.Write(&iMaxId,sizeof(UINT));
 		//		file.Flush();
		file.Close();
	}
	else 
	{
		TRACE(_T("File could not be opened %d\n"), e.m_cause);
		return FALSE;
	}
	return TRUE;
}

BOOL CQueSetDlg::ReadMaxIdFromFile()
{
	CFile file;
	CFileException e;
	if (file.Open(m_maxnumfile_path,CFile::modeRead,&e))
	{
		UINT iMaxId;
		file.Read(&iMaxId,sizeof(UINT));
		gobal_queserial_id = iMaxId;
		file.Close();
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL CQueSetDlg::RefrushQueInfo()
{
	return ReadQueBasicInfoFromFile();
}
void CQueSetDlg::OnBnClickedBnOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (CheckQueNum())
	{
		CCascadeMethod cascade;
		for (int i = 0;i<m_DeleteQueidArr.GetCount();i++)
		{
			cascade.DeleteQueInfo(m_DeleteQueidArr[i]);
		}
		WriteMaxIdToFile();
		WriteQueBasicInfoToFile();
		return CDialog::OnOK();
	}
	else
	{
		AfxMessageBox(_T("���п�ʼ���������д�������顣"));
	}
}

BOOL CQueSetDlg::CheckQueNum()
{
	int count = m_list_queinfo.GetCount();
	for (int i=0;i<count;i++)
	{
		POSITION pos = m_list_queinfo.FindIndex(i);
		if(pos)
		{
			int ibegin = m_list_queinfo.GetAt(pos).GetQueNumStart();
			int iend = m_list_queinfo.GetAt(pos).GetQueNumEnd();
			if (iend<ibegin&&iend!=0)
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}

void CQueSetDlg::OnBnClickedBnCancle()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	return CDialog::OnCancel();
}



void CQueSetDlg::OnDtnDatetimechangeTimestart(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if (index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
//	CTime workstart;
//	m_timectrl_end.ModifyStyle(0,DTS_SHOWNONE,0);
	COleDateTime workstart;
	m_timectrl_start.GetTime(workstart);
	/*if(style == GDT_NONE)
	{
		ASSERT(&workstart);
	}*/
//	AfxMessageBox(workstart);
	
 	m_timectrl_end.SetTime(workstart);
	/*SYSTEMTIME sysstart;
	workstart.GetAsSystemTime(sysstart);
	CTime timestart(sysstart);*/
 	queinfo.SetQueWorkTimeStart(workstart);
 	m_list_queinfo.GetAt(pos)=queinfo;
	*pResult = 0;
}

void CQueSetDlg::OnDtnDatetimechangeTimeend(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if (index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	COleDateTime workend;
	m_timectrl_end.GetTime(workend);
	queinfo.SetQueWorkTimeEnd(workend);
	m_list_queinfo.GetAt(pos)=queinfo;
	*pResult = 0;
}

void CQueSetDlg::OnEnChangeEdQueserialid()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	UpdateData();
	int index=m_listctr_quename.GetCurSel();
	if(index==CB_ERR)
	{
		MessageBox(_T("��ѡ�����"),MB_OK,MB_ICONINFORMATION);
		return;
	}
	POSITION pos = m_list_queinfo.FindIndex(index);
	if(!pos)return;
	CQueueInfo queinfo=m_list_queinfo.GetAt(pos);
	queinfo.SetQueManNum(m_cs_queManNum);
	m_list_queinfo.GetAt(pos)=queinfo;
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
