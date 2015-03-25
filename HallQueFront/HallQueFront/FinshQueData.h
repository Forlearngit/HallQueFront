#pragma once
#include <afxmt.h>
#include <list>
#include "SLZData.h"
#include <string>
#include "JudyeShortMsg.h"
#include "ConfigCardDef.h"
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
	std::list<CJudgeShortMsg*> m_list_shortmsg;//����������Ϣ����
	CMutex m_mtFinshQue;//��ɶ�����
	CString m_filePath;//���ļ�·��
private:
	static UINT DoFinshedData(LPVOID pParam);
	CWinThread* m_pDoFinshedDataThread;//������������߳�
	BOOL Start();
	void ReleaseListShorMsg();
	BOOL ReadJudgeShortMsg();
	BOOL SendMsgToPhone(const SLZData& data);
public:
	BOOL ReFlushListShortMsg();//�ӿ�ˢ�³��ֲ������Ͷ��ŵĶ���
private:
	CARDCONNECTINFO m_cardConnectInfo;//������Զ�̷������ж���Ϣ
	BOOL ReadCardConnectInfo();//��ȡ��������Ϣ
public:
	BOOL ReFlushCardConnectInfo();//ˢ�¿�������Ϣ
};
