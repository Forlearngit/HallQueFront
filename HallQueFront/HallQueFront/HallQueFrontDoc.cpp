// HallQueFrontDoc.cpp : CHallQueFrontDoc ���ʵ��
//

#include "stdafx.h"
#include "HallQueFront.h"

#include "HallQueFrontDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHallQueFrontDoc

IMPLEMENT_DYNCREATE(CHallQueFrontDoc, CDocument)

BEGIN_MESSAGE_MAP(CHallQueFrontDoc, CDocument)
END_MESSAGE_MAP()


// CHallQueFrontDoc ����/����

CHallQueFrontDoc::CHallQueFrontDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CHallQueFrontDoc::~CHallQueFrontDoc()
{
}

BOOL CHallQueFrontDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CHallQueFrontDoc ���л�

void CHallQueFrontDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CHallQueFrontDoc ���

#ifdef _DEBUG
void CHallQueFrontDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHallQueFrontDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHallQueFrontDoc ����
