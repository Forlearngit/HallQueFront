#pragma once
#include <list>
#include "afxmt.h"
#include "SLZData.h"
using namespace std;

class CDiscardQueData
{
public:
	CDiscardQueData(void);
	~CDiscardQueData(void);
	void Add(const SLZData& data);//���ӵ�����
	BOOL GetDiscardQueData(const UINT uWinID,SLZData& data);//��ȡ
	BOOL GetDiscardQueData(SLZData& data);
private:
	std::list<SLZData> m_list_discardQueData;//���Ŷ���
	CMutex m_mtDiscard;//���Ŷ�����
private:
	static UINT DoDiscardData(LPVOID pParam);
	CWinThread* m_pDoDiscardDataThread;//������������߳�
	BOOL Start();
};
