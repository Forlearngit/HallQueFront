#pragma once

class CJudgeShortMsg : public CObject
{
public:
	CJudgeShortMsg(void);
	~CJudgeShortMsg(void);
	//�����͸�ֵ
	CJudgeShortMsg(const CJudgeShortMsg& obj);
	CJudgeShortMsg& operator=(const CJudgeShortMsg& obj);

	DECLARE_SERIAL(CJudgeShortMsg)
	UINT GetJudgeShortMsgSerialID(){return m_shortMsgSerialID;}
	void SetPhoneNum(CString strPhoneNum){m_strPhoneNum = strPhoneNum;}
	CString GetPhoneNum(){return m_strPhoneNum;}
	void SetShortMsg(CString strShortMsg){m_strShortMsg = strShortMsg;}
	CString GetShortMsg(){return m_strShortMsg;}
	virtual void Serialize( CArchive& ar );//֧�����л�
private:
	UINT m_shortMsgSerialID;//Ψһ���
	CString m_strPhoneNum;//�绰����
	CString m_strShortMsg;//��������
};
