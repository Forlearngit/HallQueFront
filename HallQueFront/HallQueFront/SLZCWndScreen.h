#pragma once
#include "HardWareDef.h"
#include <afxmt.h>
#include <list>
#include <string>
#include <map>
using namespace std;

class CStbContent;
class StbDisplay;


class SLZCWndScreen
{
private:
	SLZCWndScreen(void);
//	static SLZCWndScreen* m_pInstance;
public:
	~SLZCWndScreen(void);
	static SLZCWndScreen* GetInstance(){
		static SLZCWndScreen instance;
		return &instance;
	}
private:
	typedef struct  
	{
		unsigned char address;//ͨ����ַ
		unsigned char channel;//ͨ����
		unsigned short width;//ͨ����
		unsigned short height;//ͨ����
		unsigned char fone;//�����С
	}ThrScreenBasicMsg;

	typedef struct  
	{
		CString msg;
		int address;
		int channel;
		CString localIp;
	}SendThrScreenMsg;

	typedef struct
	{
		UINT uStbID;
		CString strMsg;
	}StbScreenMsg;

	int DoScreenMsg(CString& msg,int address,
		char* buf);
	int DoSingleColorMsg(CString msg,int address,char* buf); //��ɫ����ʾ
	void AssicToHex(char *param);
	void StrToHexes(char *pc,int nsize,char *puc);
	int InitScreen(char *buf,const int address);
	BOOL IsResaved(const char* buf);//�жϷ��͸����������Ƿ���յ�
	CList<WNDSCREENMSG,WNDSCREENMSG&> m_listScreenMsg;//������
	HANDLE m_hDoWndScreenMsgThread;//�����������߳�
	static DWORD WINAPI DoWndScreenMsgThread(LPVOID pParm);//�����������߳�
	HANDLE m_hDoThrWndMsgThread;//����ͨ�������߳̾��
	static DWORD WINAPI DoThrWndMsgThread(LPVOID pParam);//
	CMutex m_WndScreenMutex;//������
	CMutex m_ThrWndMutex;//ͨ����
	void StartHardScreen();//���������������߳�
	std::list<ThrScreenBasicMsg> m_list_thrBasicMsg;//ͨ��ͨ��������Ϣ
//	std::string m_recvThroughInitStr;//���ܳ�ʼ��ͨ������
//	std::list<string> m_list_recvString;//�ֽ���ܵ�ͨ������
	std::list<SendThrScreenMsg> m_list_sendThrMsg;//ͨ�����ݻ�����
	CString FlushCstringToFitWndScreen(const CString& str,const int length,int height);//����ͨ��ʱ��ʽ���ַ���
	BOOL SendDataToThroughScreen(const CString& str,int address,int channel,const CString& localIp);
	int  FindChannelWidth(int address,int channel,int& height);//�����ͨ������ʾ���ٸ���
	void AddThrBasicMsg(ThrScreenBasicMsg msg);
	string::size_type GetIpPos(const string& msg);//�ж���ip�Ĳ����ַ��λ��
private:
	list<StbScreenMsg> m_list_stdscreenmsg;//stdscreenmsg������
	HANDLE m_hDoStbScreenThread;//����stb���߳�
	static DWORD WINAPI DoStbScreenMsgThread(LPVOID pParam);
	CMutex m_mtStbScreenMsg;

	StbDisplay* m_pStbDisplay;

	CMutex m_mtStbmapcallmsg;
	map<UINT,CStringArray*> m_map_stbcallMsg; 
	void ClearMapStbcallMsg();

	CString ProduceStbMsg(CString& strStbNum,UINT uStbID);//���ɷ��͵�Һ�����������ַ���
private:
	list<CStbContent*> m_list_stbcontent;//stbcontent����
	BOOL ReadStbContentInfo();
	void ClearStbContentInfo();
public:
	void AddScreenMsg(CString& msg,const int address);//�򻺳������������
//	void InitThroughScreen(const int address);//��ʼ��ͨ������ģʽ
//	void InitThroughScreen(const CString IP,USHORT port);//��ʼ��ͨ��TCPģʽ
//	BOOL DoThroughInitMsg();
//	void AddThroughInitStr(const char* buf,const DWORD count);
	void AddThroughScreenMsg(const CString& msg,int address,int channel,const CString& localIp = _T(""));//�򻺳��������ͨ������

	void AddStbScreenMsg(const CString& msg,UINT uStbID);

	BOOL ReFlushStbContentInfo();

	void UpdateStbTitleAndNotice();

	BOOL GetStbIDByStbNum(const CString& strStbNum,UINT* pStbID);//���ݻ����б�ŵõ�������ΨһID
};
