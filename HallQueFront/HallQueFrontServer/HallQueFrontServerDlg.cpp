// HallQueFrontServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HallQueFrontServer.h"
#include "HallQueFrontServerDlg.h"
#include "ConnectToMySql.h"
#include "../HallQueFront/CommonConvert.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CHallQueFrontServerDlg �Ի���




CHallQueFrontServerDlg::CHallQueFrontServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHallQueFrontServerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAINFRAME);
}

void CHallQueFrontServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ED_SERVERIP, m_ed_serverIP);
	DDX_Control(pDX, IDC_ED_USERNAME, m_ed_userName);
	DDX_Control(pDX, IDC_ED_PASS, m_ed_userPass);
	DDX_Control(pDX, IDC_ED_SERVERPORT, m_ed_serverPort);
	DDX_Control(pDX, IDC_ED_DATABASEPORT, m_dataBasePort);
}

BEGIN_MESSAGE_MAP(CHallQueFrontServerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CHallQueFrontServerDlg::OnBnClickedOk)
	ON_MESSAGE(WM_MY_TRAYICON, OnTrayIcon)
	ON_COMMAND(ID_MENU_SHOW, &CHallQueFrontServerDlg::OnMenuShow)
	ON_COMMAND(ID_MENU_QUIT, &CHallQueFrontServerDlg::OnMenuQuit)
	ON_WM_CLOSE()
	ON_WM_QUERYOPEN()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CHallQueFrontServerDlg ��Ϣ�������

BOOL CHallQueFrontServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
// 	CConnectToMySql mySql;
// 	int i_port = 0;
// 	CCommonConvert::CStringToint(i_port,m_dbaConfig.GetDBPort());
// 	mySql.ConnectToDB(m_dbaConfig.GetServerIP(),
// 		i_port,m_dbaConfig.GetServerAcount(),
// 		m_dbaConfig.GetServerPassword());
	//
	m_selectServer.InitServer();
	/////////////////////////////////
	m_ed_serverIP.SetWindowText(m_dbaConfig.GetServerIP());
	m_ed_serverPort.SetWindowText(m_dbaConfig.GetServerPort());
	m_ed_userName.SetWindowText(m_dbaConfig.GetServerAcount());
	m_ed_userPass.SetWindowText(m_dbaConfig.GetServerPassword());
	m_dataBasePort.SetWindowText(m_dbaConfig.GetDBPort());
	//////
	AddTrayIcon();
	/////

	SetTimer(11,10,NULL);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHallQueFrontServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
// 		if(nID == SC_MINIMIZE)
// 		{
// 			ShowWindow(SW_HIDE);
// 			UpdateWindow();
// 		}
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHallQueFrontServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHallQueFrontServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CHallQueFrontServerDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString userName,userPass,userIP,userPort,DBPort;
	m_ed_userName.GetWindowText(userName);
	m_dbaConfig.SetServerAcount(userName);
	m_ed_serverIP.GetWindowText(userIP);
	m_dbaConfig.SetServerIP(userIP);
	m_ed_serverPort.GetWindowText(userPort);
	m_dbaConfig.SetServerPort(userPort);
	m_ed_userPass.GetWindowText(userPass);
	m_dbaConfig.SetServerPassword(userPass);
	m_dataBasePort.GetWindowText(DBPort);
	m_dbaConfig.SetDBPort(DBPort);
	m_dbaConfig.Save();
	////////////////////////////�������ݿ�
	/*
	CADODatabase dataBase;
	m_strConn.Format(_T("Driver={SQL Server};Server=%s;Database=InfoMan;Uid=%s;Pwd=%s;"),
		m_dbaConfig.GetServerIP(),
		m_dbaConfig.GetServerAcount(), m_dbaConfig.GetServerPassword());
	dataBase.SetConnectionString(m_strConn);
	try
	{
	if(dataBase.Open())
	{
		MessageBox(_T("���ӳɹ�"),_T("ע��"),MB_OK|MB_ICONINFORMATION);
		dataBase.Close();
	}
	else
	{
		MessageBox(_T("�������ݿ�ʧ��"),_T("ע��"),MB_OK|MB_ICONINFORMATION);
	}
	}
	catch(...)
	{
		MessageBox(_T("�������ݿ�ʧ��"),_T("ע��"),MB_OK|MB_ICONINFORMATION);
		return;
	}
	*/
	CConnectToMySql mySql;
	int i_port = 0;
	CCommonConvert::CStringToint(i_port,DBPort);
	if(mySql.ConnectToDB(userIP,i_port,userName,userPass))
	{
		MessageBox(_T("���ݿ����ӳɹ�"),_T("ע��"),MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		MessageBox(_T("���ݿ�����ʧ��"),_T("ע��"),MB_OK|MB_ICONINFORMATION);
	}
}


void CHallQueFrontServerDlg::AddTrayIcon(void)
{
	wchar_t tip[128] = {0};
	wsprintf(tip, _T("�����Ŷ�ϵͳ�����"));
	//wchar_t tip[] = _T("�Ŷ�ϵͳӲ��������ʽ\0");
	//CHAR tip[] = "�ŶӶԽ�\0";
	TaskBarAddIcon(this->m_hWnd, IDI_MAINFRAME, m_hIcon, (LPCWSTR)tip);
}

BOOL CHallQueFrontServerDlg::TaskBarAddIcon(HWND hwnd, UINT uID, HICON hIcon, LPCWSTR lpszTip)
{
	BOOL res;
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hwnd;
	nid.uID = uID;
	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP | NIF_INFO;
	nid.uCallbackMessage = WM_MY_TRAYICON;
	nid.hIcon = hIcon;
	if (lpszTip)
	{
		//lstrcpyn(nid.szTip, lpszTip, sizeof(nid.szTip));
		wcscpy_s(nid.szTip, sizeof(nid.szTip), lpszTip);
	}
	else
	{
		nid.szTip[0] = '\0';
	}
	res = Shell_NotifyIcon(NIM_ADD, &nid);

	if (hIcon)
	{
		DestroyIcon(hIcon);
	}
	return res;
}

BOOL CHallQueFrontServerDlg::TaskBarDeleteIcon(HWND hwnd, UINT uID)
{
	NOTIFYICONDATA nid;
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hwnd;
	nid.uID = uID;
	return Shell_NotifyIcon(NIM_DELETE, &nid);
}

void CHallQueFrontServerDlg::RemoveTrayIcon()
{
	TaskBarDeleteIcon(this->m_hWnd, IDI_MAINFRAME);
}

LRESULT CHallQueFrontServerDlg::OnTrayIcon(WPARAM wParam, LPARAM lParam)
{
	if(wParam != IDI_MAINFRAME)
	{
		return 1;
	}
	switch(lParam)
	{
	case WM_LBUTTONUP:
	case WM_LBUTTONDBLCLK:
		{
			this->ShowWindow(SW_SHOW);
			this->ShowWindow(SW_NORMAL);
		}
		break;
	case WM_RBUTTONUP:
		{
			SetForegroundWindow();//�����������λ�����½ǵ����˵���ʧ
			CMenu menu;
			menu.LoadMenu(IDR_MYMENU);
			CMenu   *pContextMenu=menu.GetSubMenu(0); //��ȡ��һ�������˵������Ե�һ���˵��������Ӳ˵� 
			CPoint point;//����һ������ȷ�����λ�õ�λ��  
			GetCursorPos(&point);//��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����  
			pContextMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,AfxGetMainWnd()); //��ָ��λ����ʾ�����˵�
		}
		break;
	}
	return 0;
}

void CHallQueFrontServerDlg::OnMenuShow()
{
	// TODO: �ڴ���������������
	ShowWindow(SW_NORMAL);
}

void CHallQueFrontServerDlg::OnMenuQuit()
{
	// TODO: �ڴ���������������
	if(IDOK==MessageBox(_T("ȷ���˳���?"),_T("����"),MB_OKCANCEL | MB_ICONINFORMATION))
	{
		RemoveTrayIcon();
		DestroyWindow();
	}
}

void CHallQueFrontServerDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ShowWindow(SW_HIDE);
//	CDialog::OnClose();
}

BOOL CHallQueFrontServerDlg::OnQueryOpen()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return CDialog::OnQueryOpen();
}

LRESULT CHallQueFrontServerDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���
	LONG lRes = CDialog::DefWindowProc(message, wParam, lParam);
	switch(message)
	{
	case WM_SYSCOMMAND:
		if(wParam == SC_MINIMIZE)
		{
			ShowWindow(SW_HIDE);
		}
		break;
	}
	return lRes;
}

void CHallQueFrontServerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent)
	{
	case 11:
		ShowWindow(SW_HIDE);
		UpdateWindow();
		KillTimer(11);
		break;
	}
	CDialog::OnTimer(nIDEvent);
}