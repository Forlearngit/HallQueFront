#pragma once
#include "SLZData.h"
#include <list>
#include "afxmt.h"
using namespace std;
class CWaitQueData
{
public:
	CWaitQueData(void);
	~CWaitQueData(void);
	void Add(const SLZData& data);
	BOOL GetWaitQueData(const UINT winID,SLZData& data);
	BOOL IsHaveWaitQueData(const UINT winID);//�ж��Ƿ�ô�������һ�����ڵȴ�
private:
	std::list<SLZData> m_list_waitQue;
	CMutex m_mtWaitQue;
};
