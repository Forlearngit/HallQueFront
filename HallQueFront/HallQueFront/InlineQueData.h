#pragma once

#include "SLZData.h"
#include <afxmt.h>
#include "SLZWindowQueryView.h"
// CInlineQueData ����Ŀ��

class CInlineQueData : public CObject
{
	friend class CCallThread;
public:
	CInlineQueData(SLZWindowQueryView& rWindowTable);
	virtual ~CInlineQueData();
	//��ȡ�����Ŷӵ��׸�
	BOOL GetInlineQueData(const UINT iWinId, SLZData& rdata);
	void Add(SLZData& data);
	void AddHeadData(const SLZData& data);
	UINT GetCount();//��ȡ������
	UINT GetBussCount(const CString& strBussId);//��ȡ��Ӧ���е��Ŷ�����
	BOOL GetInlineQueData(SLZData& rdata);//��ȡ��һ������
	void RemoveAllData();
	int GetMaxQueNum(const CString queID);
	UINT GetCandoQueCount(UINT iWinID);//��ȡ�����ܹ�����Ķ����Ŷ������ܺ�
	BOOL AlterData(const CString QueNum,const CString strPhoneNum,const CString strMsg);
	BOOL GetInlineQueData(int i,SLZData& data);
private:
	CList<SLZData> m_lstInlineQue;//�ŶӶ���
	CMutex m_mtInlineQue;
	SLZWindowQueryView& m_rWindowTable;
};


