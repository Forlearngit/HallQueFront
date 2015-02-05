#pragma once

#include "QueueInfo.h"
#include "DoFile.h"
#include "afxwin.h"
#include "CommonConvert.h"
#include "ComputeFuncationTime.h"
#include "afxdlgs.h"
#include "resource.h"
// CQueSetDlg �Ի���


class CQueSetDlg : public CDialog
{
	DECLARE_DYNAMIC(CQueSetDlg)

public:
	CQueSetDlg(CWnd* pParent = NULL);
	virtual ~CQueSetDlg();

// �Ի�������
	enum { IDD = IDD_QUESETDLG };

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//������Ϣӳ��ĺ���
	virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
public:
	CList<CQueueInfo,CQueueInfo&> m_list_queinfo;//��Ŷ�����Ϣ������
	CDoFile m_dealFile;
	
	/*virtual BOOL OnApply();*/
	CListBox m_listctr_quename; //�����б�listbox�ؼ�
private:
	CCommonConvert m_convert; 
	CString m_infofile_path; //�ļ���ŵ�ַ
	CString m_maxnumfile_path;
	CStringArray m_DeleteQueidArr;
	BOOL CheckQueNum();
public:
	CString m_cs_quename; //�����ؼ���ʾ�Ĺ�������
	CString m_cs_callname;
	CString m_cs_queid;
	CString m_cs_frontid;
	CString m_cs_numstart;
	CString m_cs_numend;
	CString m_cs_amlimit;
	CString m_cs_pmlimit;
	CString m_cs_daylimit;
	CDateTimeCtrl m_timectrl_start;
	CDateTimeCtrl m_timectrl_end;
	CComboBox m_cs_stbid; // ������
	//CString GetQueinfoBasicInfo(){return m_infofile_path;} //��õ�ַ

	BOOL WriteQueBasicInfoToFile(); //д���ļ�
	BOOL ReadQueBasicInfoFromFile(); //��ȡ�ļ�
	BOOL WriteMaxIdToFile();		//д��������ļ�
	BOOL ReadMaxIdFromFile();		//����������ļ�
	BOOL RefrushQueInfo();
	void SetEdctrNull(); //�ؼ���ʾ�ÿ�

	int m_ReadMaxSerialID;

	CComputeFuncationTime m_ComputerTime;
	afx_msg void OnBnClickedBnAddqueue();
	afx_msg void OnLbnSelchangeListQuename();
	afx_msg void OnBnClickedBnDelqueue();
	afx_msg void OnEnChangeEdAmlimit();
	afx_msg void OnEnChangeEdPmlimit();
	afx_msg void OnEnChangeEdDaylimit();
	afx_msg void OnEnChangeEdQuename();
	afx_msg void OnEnChangeEdCallname();
	afx_msg void OnEnChangeEdFrontid();
	afx_msg void OnEnChangeEdQuenumstart();
	afx_msg void OnEnChangeEdQuenumend();
	afx_msg void OnBnClickedBnOk();
	afx_msg void OnBnClickedBnCancle();
	afx_msg void OnDtnDatetimechangeTimestart(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDtnDatetimechangeTimeend(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_ed_queSerialID;
	afx_msg void OnEnChangeEdQueserialid();
	CString m_cs_queManNum;
};
