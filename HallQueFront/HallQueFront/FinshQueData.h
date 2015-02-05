#pragma once
#include <afxmt.h>
#include <list>
#include "SLZData.h"
#include <string>
using namespace std;

using namespace std;

class CFinshQueData
{
public:
	CFinshQueData(void);
	~CFinshQueData(void);
	void Add(const SLZData& data);//��������
	BOOL GetFinshedData(const UINT winID,SLZData& data);//��ȡ����,��ɾ��
	BOOL GetFinshedData();
private:
	std::list<SLZData> m_listFinshQue;//��ɶ���
	CMutex m_mtFinshQue;//��ɶ�����
private:
	static UINT DoFinshedData(LPVOID pParam);
	CWinThread* m_pDoFinshedDataThread;//������������߳�
	BOOL Start();
};
