#pragma once

#include <afxwin.h>
#include <afxmt.h>
#include "jTTS_ML.h"
#pragma comment(lib, "jTTS_ML.lib")
//#include "NurseDef.h"

class JttsAPI
{
private:
	JttsAPI();

public:
	~JttsAPI();
	static JttsAPI* GetInstance();
	BOOL SetPlay(
		UINT uDeviceID, //���ΪWAVE_MAPPER(-1)����ʾȱʡ�ķ����豸������Ϊָ���ķ����豸�� 
		HWND hwnd, //һ���Ϸ��Ĵ��ھ������ϵͳ�Ķ�ʱ����Ϻ󣬻ᷢ��һЩ�Զ�����Ϣ���˴��ڡ����ΪNULL����ʹ�ô�����Ϣ�ķ�ʽ֪ͨӦ�ó���
		JTTS_CALLBACKPROC lpfnCallback, //һ���Ϸ��Ļص�������ַ����ϵͳ�Ķ�ʱ����Ϻ󣬻���ô˺�����
		DWORD dwUserData //�û�������Զ������ݣ��ص�ʱ���ش����ص�����
		);
	//ͬ�����ţ�����ʱ������
	static BOOL Play(CString strVoice);
	//void ErrorMessage(ERRCODE err);
private:
	BOOL InitTTS();
	BOOL EndTTS();
	BOOL WriteReg(void);
private:

	JTTS_CONFIG m_config;
	char* m_szInitPath;
	char* m_szSerialNo;
	char* m_szVoiceInfo;

	static JttsAPI* m_pThis;

};