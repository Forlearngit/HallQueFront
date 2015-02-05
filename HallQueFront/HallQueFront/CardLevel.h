#pragma once

class CCardLevel : public CObject
{
public:
	CCardLevel(void);
	~CCardLevel(void);
	//�����͸�ֵ
	CCardLevel(const CCardLevel& obj);
	CCardLevel& operator=(const CCardLevel& obj);
	///////////���ȼ�
	void SetCardLevel(const int level){m_cardLevel = level;}
	int GetCardLevel(){return m_cardLevel;}
	//////////���ȼ�����
	void SetCardLevelName(const CString& levName){m_cardLevName = levName;}
	CString GetCardLevelName(){return m_cardLevName;}
	//////////�ÿ��ȼ���Ӧ���ŶӶ���
	void SetCardLevAttchToQue(const CString& queID){m_levAttchToQueID = queID;}
	CString GetCardLevAttchToQue(){return m_levAttchToQueID;}
	/////////���ȼ�ΨһID�����
//	void SetCardLevSerialID(const UINT serialID){m_cardLevSerialID = serialID;}
	UINT GetCardLecSerialID(){return m_cardLevSerialID;}
	////////////////////////////
	virtual void Serialize( CArchive& ar );//֧�����л�
	DECLARE_SERIAL(CCardLevel)
	//////////////////////////
	void SetCardLevAttchToPageID(int nPageID){m_nLevAttchToPageID = nPageID;}
	int GetCardLevAttchToPageID(){return m_nLevAttchToPageID;}
private:
	int m_cardLevel;//���ȼ��磺��,�׽𿨵ȴ�
	CString m_cardLevName;//���ȼ�����
	CString m_levAttchToQueID;//���ȼ�������ID
	UINT m_cardLevSerialID;//���ȼ�ΨһID�����
	int m_nLevAttchToPageID;//���ȼ���������ID
};
