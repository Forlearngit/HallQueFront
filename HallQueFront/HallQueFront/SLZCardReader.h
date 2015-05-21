#pragma once
#include "DataDef.h"
//#include "ConfigCardDef.h"
#include "SwingCard.h"
#include "CardLevel.h"
#include <string>
#include <afxmt.h>
#include <string>
using namespace std;
#define MAX_CARD_NO 255 //����ȡ���Χ
//�����Ŀ�����Ϣ
class SLZCardReader
{
private:
	SLZCardReader(void);
public:
	~SLZCardReader(void);

	static SLZCardReader* GetInstance();

	BOOL HasData(); //�жϻ��������Ƿ������ݿ��Զ�
	CARDINFO GetData(); //��ȡ�������������ˢ����Ϣ
	void Run(); //��������������
private:
	BOOL Init_Library(); //��ʼ�����֤��
	BOOL ReadMsg(); //�����֤����Ϣ
//	int GetStatus(); //��ȡ���ȼ�
	CMutex m_CardReaderMutex; //�߳���
	HANDLE  m_hReadTread;//�߳̾��
	HANDLE m_hReadCard;//�߳̾��
	HANDLE m_hReadNewCard;//оƬ���߳̾��
	CList<CARDINFO,CARDINFO&> m_CardInfoList; //������
	//�����֤����
	int (_stdcall *SDT_StartFindIDCard)(int iPort,unsigned char* pucManaInfo,int iIfOpen);
	int (_stdcall *SDT_SelectIDCard)(int iPort,unsigned char* pucManaMsg,int iIfOpen);
	int (_stdcall *SDT_ReadBaseMsg)(int iPort,unsigned char* pucCHMsg,unsigned int* puiCHMsgLen,unsigned char* pucPHMsg,unsigned int* puiPHMsgLen,int iIfOpen);
	static DWORD WINAPI ReadThread(LPVOID pParam); //�����֤�߳�
	static DWORD WINAPI ReadCard(LPVOID pParam); //���ſ��߳�
	static DWORD WINAPI ReadNewCard(LPVOID pParam);//оƬ���߳�
private:
	BOOL OpenReadCard();
	CString m_cardcofinfo_path;//��ʶ����Ϣ�ļ�·��
	CString m_connect_path;//��������Ϣ�ļ�·��
	CArray<CCardLevel*,CCardLevel*> m_list_cardLev;//���ļ�����Ϣ����
	CString m_cardLev_path;//���ĵȼ���Ϣ�ļ�·��
private:
	BOOL ReadCardConnectInfo();//������������Ϣ
	BOOL ReadCardConnectLev();//������������Ϣ�����Ӧ�Ķ���ID
	BOOL ReadCardConfigInfo();//������ʶ����Ϣ
	void ClearSwingCardInfo();//ɾ��������ı���CSwingCard
	CString JudgeCardAttchQue(const CString& cardNum);//�ж�ˢ�������ſ������ĸ�����,���ض���ID�����ڲ��Խӵ����
	int JudgeCardAttchPageID(const CString& cardNum);//�ж�ˢ���Ŀ������ӵ��Ǹ�����,���ڲ��Խ����
	CARDCONNECTINFO m_cardConnectInfo;//������Զ�̷������ж���Ϣ
	CArray<CSwingCard*,CSwingCard*> m_list_swingCard;//ˢ��������
	void ClearCardLevInfo();//��տ��ȼ���������
	int GetCustLev(const CString& strCardNum);//��ȡ�ͻ��ȼ����ڶԽ����
	CString JudgeCardAttchQue(const int level);//�жϿ��Խӣ�����ȼ���Ӧһ�����У����ض��У����ڶԽӵ����
	int JudgeCardAttchPageID(int level);//�жϿ��Խ�,����ȼ����ؽ���ID�����ڶԽ����
public:
	BOOL ReFlushCardConnectInfo();//�ӿ�,ˢ�¿���������Ϣ
	BOOL ReFlushCardConfigInof();//�ӿ�,ˢ�¿���ʶ����Ϣ
	BOOL ReFlushCardLevelInfo();//�ӿ�,ˢ�¿��ȼ����ض�����Ϣ
private:
	string m_strCardNum;

private:
	/**************************��ˢ����������һ��***************************/
	BOOL MultiReadCard(int nPort,int nWaitTime,char* pErrInfo,CString& cCardNum); //����һˢ����
	//�򿪶˿�
	typedef int (CALLBACK* lpOpenPort)(int,char,char*);
	//��IC������
	typedef int (CALLBACK* lpICC_getIcInfo)(int,char,char,char*,int,char*,char*);
	//���ſ�����
	typedef int (CALLBACK* lpMsrRead)(int,char,int,char*,char*,int,char*);
	//�رն˿�
	typedef int (CALLBACK* lpClosePort)(char* );
	//��Ƭ��λ�ж�(�жϽӴ�ʽоƬ���Ƿ���λ)
	typedef int  (CALLBACK* lpCardPresent)(  int *,  char * );
	//IC���ϵ�
	typedef int  (CALLBACK* lpPowerOn)(  unsigned char *,   int *,   int ,   char *,   int );
	//IC���µ�
	typedef int  (CALLBACK* lpPowerOff)(  char *,  int );

	lpICC_getIcInfo m_pGetIcInfo;
	lpMsrRead m_pMsrRead;
	lpCardPresent m_pCardPresent;
	lpPowerOn m_pPowerOn;
	lpPowerOff m_pPowerOff;

	//��ˢ��������һ����ʼ����̬��
	BOOL Init_ICLibrary();

	void DealCardInfo(CARDINFO* cardinfo);

	CString GetCardNum(const char* buf);//�õ�����

	BOOL OpenNewReadCard();//оƬ��
	BOOL CloseNewReadCard();//�ر�оƬ���˿�
private:
	CString m_strCurrentCardNum;//�����жϵ�ǰ�Ӵ�ʽ�������Ƿ��ظ�ˢ
public:
	lpOpenPort m_pOpenPort;//�򿪶˿�
	lpClosePort m_pClosePort;//�رն˿�
};
