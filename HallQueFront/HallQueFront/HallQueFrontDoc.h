// HallQueFrontDoc.h : CHallQueFrontDoc ��Ľӿ�
//


#pragma once


class CHallQueFrontDoc : public CDocument
{
protected: // �������л�����
	CHallQueFrontDoc();
	DECLARE_DYNCREATE(CHallQueFrontDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CHallQueFrontDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


