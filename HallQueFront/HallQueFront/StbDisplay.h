#pragma once

class StbDisplay
{
public:
	StbDisplay();
	~StbDisplay();
	//���±���
	BOOL StbUpdateTitleHtml(CString strTitle, CString strStbId);
	//����֪ͨ����
	BOOL StbUpdateNoticeHtml(CString strNotice, CString strStbId);
	//���º�����Ϣ
	BOOL StbUpdateCallMsg(CString strIMsg, CString strStbId);

	BOOL Start();
private:

	//����Һ����ʾ�����ò���
	void LoadDisplayConf();
	//Һ����ʾ��ʼ��
	BOOL InitDisplay();
	//������ý����Ϣ���������
	BOOL InitNetServer();

	//����ɫ��ʶת������ҳ����ɫ��ʶ
	CString CovertColorString(CString strSrc);

	BOOL WriteToStbHtmlFile(CString& strHtmlStr, CString strStbId, CString strHtmlFileName);

	BOOL WriteToFile(CString& strText, CString& strFilePath);

private:

	CString m_strModuleDir;//Ӧ�ó���Ŀ¼
	CString m_strWebRootDir;//��ҳ�ļ���Ŀ¼

	CString m_strHtmlTitleBegin;//�������ҳ�ļ���ʼ����
	CString m_strHtmlTitleEnd;//����ı�����ҳ�ļ����沿��
	CString m_strHtmlNoticeBegin;//���֪ͨ����ҳ�ļ���ʼ����
	CString m_strHtmlNoticeEnd;//���֪ͨ�ı�����ҳ�ļ����沿��
	CString m_strHtmlInstMsgBegin;//����֪ͨ����ҳ�ļ���ʼ����
	CString m_strHtmlInstMsgEnd;//����֪ͨ����ҳ�ļ����沿��
	CString m_strHtmlQueueInfoBegin;//�б����ҳ�ļ���ʼ����
	CString m_strHtmlQueueInfoEnd;//�б����ҳ�ļ����沿��

	PROCESS_INFORMATION m_piNetServer;//��ý����Ϣ��������˽�����Ϣ
};

