// PlaySoundThread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HallQueFront.h"
#include "PlaySoundThread.h"
#include "DataDef.h"

// CPlaySoundThread

IMPLEMENT_DYNCREATE(CPlaySoundThread, CWinThread)

CPlaySoundThread::CPlaySoundThread()
{
}

CPlaySoundThread::~CPlaySoundThread()
{
}

BOOL CPlaySoundThread::InitInstance()
{
	// TODO: �ڴ�ִ���������̳߳�ʼ��
	return TRUE;
}

int CPlaySoundThread::ExitInstance()
{
	// TODO: �ڴ�ִ���������߳�����
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CPlaySoundThread, CWinThread)
		ON_THREAD_MESSAGE(CALL_MSG, &CPlaySoundThread::OnReset)
END_MESSAGE_MAP()


// CPlaySoundThread ��Ϣ�������
void AFX_MSG_CALL CPlaySoundThread::OnReset(WPARAM wParam, LPARAM lParam)
{
	// �����Լ���ʵ�ִ���
}