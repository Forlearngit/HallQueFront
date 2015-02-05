#pragma once
#include "ConfigCardDef.h"
class CSwingCard : public CObject
{
public:
	CSwingCard(void);
	~CSwingCard(void);
	//////////////////////////////////////��������͸�ֵ
	CSwingCard(const CSwingCard& obj);
	CSwingCard& operator=(const CSwingCard& obj);
	///////////////////////////////////////////////////////
	UINT GetCardInfoID()const {return m_cardInofID;}//ΨһID
	CString GetAttchQueID()const {return m_attchQueID;}
	void SetAttchQueID(const CString& queID){m_attchQueID = queID;}
	void SetCardName(const CString& cardName){m_cardName = cardName;}
	CString GetCardName()const {return m_cardName;}
	int GetAttchPageID()const {return m_nAttchPageID;}
	void SetAttchPageID(int nAttchPageID){m_nAttchPageID = nAttchPageID;}
private:
	CString m_cardName;//����
	UINT m_cardInofID;//ˢ�����ID
	CString m_attchQueID;//�����Ķ���ID
	int m_nAttchPageID;//������ҳ��ID
//	UINT m_count;//CArray�Ĵ�С
public:
	////��ʶ����Ϣ
//	CArray<DISTINGUISHCARD>m_disTinguishCard;
	DISTINGUISHCARD m_disTinguishCard[4];
	virtual void Serialize( CArchive& ar );//֧�����л�
	DECLARE_SERIAL(CSwingCard)
};
