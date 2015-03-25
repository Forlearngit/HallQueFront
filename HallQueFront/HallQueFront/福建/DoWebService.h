#pragma once
#include <string>
#include "Fuzhou.h"
using namespace std;
class SLZData;

class CDoWebService
{
public:
	CDoWebService(void);
	~CDoWebService(void);
	int GetCardLevelFromServer(const CString& host,const CString& cardNo,USHORT port,int waitTimeSec,CustLev* pCustLev);
	int SendDealBusMsg(const CString& host,const SLZData& data,USHORT port,int waitTimeSec,int leftNum,BOOL isEnd=FALSE);
private:
	////ˢ��ʱ���ɶԽ��ַ���
	std::string ProduceSendCardMsg(const CString& cardNo,const CString& host,USHORT port);
	////����ˢ�������ַ������ؿ�����
	int AnaCustLevel(const std::string& recvMsg,CustLev* pCustLev);
	////����ҵ��ʱ���ɶԽ��ַ���
	std::string ProduceDealBusMsg(const SLZData& dealData,int leftNum,const CString& host,USHORT port,BOOL isEnd);
	////��������ҵ��ʱ���ر���
	int AnaBusErrcode(const std::string& recvMsg);
	BOOL InitClient();//��ʼ��sokcet
	void StopClient();
	BOOL ConnectToServer(SOCKET& cliSock,const CString& host,USHORT port,int waitSec);
	void GetCustProduct(const string& recvMsg,CustLev* pCustLev);
private:
	USHORT m_uPort;//�˿�
	CString m_romoteIP;//IP
	UINT m_nTimeOut;//��ʱ��(����)
};
