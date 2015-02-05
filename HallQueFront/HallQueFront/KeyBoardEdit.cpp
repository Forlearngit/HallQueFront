// KeyBoardEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KeyBoardEdit.h"
#include "resource.h"
#include "DoFile.h"
#include "HallQueFront.h"
// CKeyBoardEdit
UINT g_clickNum;
extern void MyWriteConsole(CString str);

IMPLEMENT_DYNAMIC(CKeyBoardEdit, CEdit)

CKeyBoardEdit::CKeyBoardEdit()
{
	CDoFile keyboardfile;
	m_strKey = keyboardfile.GetExeFullFilePath();
	m_strKey+=L"\\KeyBoard.exe";
}

CKeyBoardEdit::~CKeyBoardEdit()
{
}


BEGIN_MESSAGE_MAP(CKeyBoardEdit, CEdit)

	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CKeyBoardEdit::OnEnKillfocus)
	ON_WM_LBUTTONDOWN()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_ACTIVATE()
END_MESSAGE_MAP()



// CKeyBoardEdit ��Ϣ�������





void CKeyBoardEdit::OnEnKillfocus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
 	
//  ::SendMessage(hwnd,WM_CLOSE,0,0);
	
}

void CKeyBoardEdit::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CEdit::OnLButtonDown(nFlags, point);
	CWnd* pKeypWnd = FindWindow(NULL,L"��Ļ����");
	if(!pKeypWnd)
	{
		STARTUPINFO si = {sizeof(si)} ;  
		PROCESS_INFORMATION pi ; 
		si.dwFlags = STARTF_USESHOWWINDOW;   
		si.wShowWindow = TRUE; //TRUE��ʾ��ʾ�����Ľ��̵Ĵ���
		TCHAR szCommandLine[] = TEXT("osk.exe") ;  
		BOOL flag = CreateProcess(NULL,szCommandLine,NULL,NULL,  
			FALSE,0,NULL,NULL,&si,&pi) ;
	}
	int x, y; 
	x = GetSystemMetrics(SM_CXSCREEN); //��Ļ��� 
	y = GetSystemMetrics(SM_CYSCREEN);
	pKeypWnd = FindWindow(NULL,L"��Ļ����");
	if(g_clickNum==0)
	{
		if(pKeypWnd)
		{
			//pKeypWnd->MoveWindow(0,y/2,x/2,y/3,1);
			g_clickNum++;
		}
	}
// 	else
// 	{
// 		if(pKeypWnd)
// 		{
// 			DWORD dStyle = pKeypWnd->GetStyle();
// 			if(dStyle & WS_MINIMIZE)
// 			{
// 				pKeypWnd->ModifyStyle(WS_MINIMIZE,0,0);
// 				pKeypWnd->ShowWindow(SW_SHOWNORMAL);
// 			}
// 		}
// 	}
	//ShellExecute(NULL, L"open", _T("osk.exe"), NULL, NULL,SW_NORMAL);
}
void CKeyBoardEdit::OnKillFocus(CWnd* pNewWnd)
{
	CEdit::OnKillFocus(pNewWnd);
// 	g_clickNum--;
// #ifdef _DEBUG
// 	CString str;
// 	str.Format(_T("%d"),g_clickNum);
// 	MyWriteConsole(str);
// #endif
// 	if(!g_clickNum)
// 	{
// 		CWnd* pWnd = FindWindow(NULL,L"��Ļ����");
// 		if(pWnd)
// 		{
// 			::SendMessage(pWnd->m_hWnd,WM_CLOSE,0,0);
// 		}
// 	}
	// TODO: �ڴ˴������Ϣ����������
}

void CKeyBoardEdit::OnSetFocus(CWnd* pOldWnd)
{
	CEdit::OnSetFocus(pOldWnd);
	
	// TODO: �ڴ˴������Ϣ����������
}

void CKeyBoardEdit::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CEdit::OnActivate(nState, pWndOther, bMinimized);

	// TODO: �ڴ˴������Ϣ����������
}
