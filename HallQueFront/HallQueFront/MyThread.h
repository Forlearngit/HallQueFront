#pragma once

// CMyThread ����Ŀ��

class CMyThread : public CObject
{
public:
	CMyThread();
	virtual ~CMyThread();
	void Start();
	void Suspend();
	void Resume();
	void Exit();
	DWORD GetThreadId()
	{
		return m_pThread->m_nThreadID;
	}

protected:
	virtual void Run();	//������д�ú��������߳�ѭ������ִ�еĴ������ú���

private:
	CWinThread* m_pThread;
	BOOL m_bContinue;
	static UINT ThreadProc(LPVOID pParam);
};


