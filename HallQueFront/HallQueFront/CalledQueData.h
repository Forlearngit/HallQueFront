#pragma once

#include "SLZData.h"
#include <afxmt.h>
#include "SLZWindowQueryView.h"
// CCalledQueData ����Ŀ��

class CCalledQueData : public CObject
{
	friend class CallThread;
public:
	CCalledQueData(SLZWindowQueryView& rWindowTable);
	virtual ~CCalledQueData();
	////��ȡ���ں��еĶ�������
	BOOL GetCalledQueData(const UINT iWinId, SLZData& rdata);
	////ɾ�����ں��еĶ�������
	BOOL DeleteCalledQueData(const SLZData& rdata);
	////�������ں��еĶ�������
	void Add(const SLZData& data);
	BOOL ModifyCalledQueData(const SLZData& rdata);
	////��ȡ��С
	UINT GetCount();
private:
	CList<SLZData> m_lstCalledQue;//���ں��ж���
	CMutex m_mtCalledQue;
	SLZWindowQueryView& m_rWindowTable;
};