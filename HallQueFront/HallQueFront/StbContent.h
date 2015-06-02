#pragma once

class CStbContent : public CObject
{
public:
	CStbContent(void);
	~CStbContent(void);
	CStbContent(const CStbContent& obj);
	CStbContent& operator=(const CStbContent& obj);


	UINT GetSerialID()const {return m_nSerialID;}

	CString GetStbName()const {return m_strName;}
	void SetStbName(const CString& stbName){m_strName = stbName;}

	CString GetStbTitle()const {return m_strTitle;}
	void SetStbTitle(const CString& stbTitle){m_strTitle = stbTitle;}

	CString GetStbNotice()const {return m_strNotice;}
	void SetStbNotice(const CString& stbNotice){m_strNotice = stbNotice;}

	CString GetStbTitlePicPath()const {return m_strTitlePicPath;}
	void SetStbTitlePicPath(const CString& strTitlePicPath){m_strTitlePicPath = strTitlePicPath;}

	CString GetStbNum()const {return m_strNum;}
	void SetStbNum(const CString& strNum){m_strNum = strNum;}

	int GetStbLineNum()const {return m_nLineNum;}
	void SetStbLineNum(int nLineNum){m_nLineNum = nLineNum;}
	//֧�����л�
	virtual void Serialize( CArchive& ar );
	DECLARE_SERIAL(CStbContent)
private:
	UINT m_nSerialID;
	CString m_strName;//����
	CString m_strTitle;//����
	CString m_strNotice;//֪ͨ
	CString m_strTitlePicPath;//ͼƬ·��
	CString m_strNum;//�����к���
	int m_nLineNum;//��ʾ����
};
