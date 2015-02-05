// HallQueFrontServerDlg.h : ͷ�ļ�
//

#pragma once
//#include "SocketTcpServer.h"
#include "afxwin.h"
#include "DbaConfig.h"
#include "SelectSocketServer.h"

#define WM_MY_TRAYICON (WM_USER+100)
// CHallQueFrontServerDlg �Ի���
class CHallQueFrontServerDlg : public CDialog
{
// ����
public:
	CHallQueFrontServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_HALLQUEFRONTSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
// ʵ��
protected:
	HICON m_hIcon;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CSocketTcpServer m_socketTcpServer;
	CSelectSocketServer m_selectServer;
	afx_msg void OnBnClickedOk();
	CEdit m_ed_serverIP;
	CEdit m_ed_userName;
	CEdit m_ed_userPass;
	CEdit m_ed_serverPort;
	afx_msg LRESULT OnTrayIcon(WPARAM wParam, LPARAM lParam);
private:
	CDbaConfig m_dbaConfig;
	CString m_strConn;
private:
	void AddTrayIcon(void);
	BOOL TaskBarAddIcon(HWND hwnd, UINT uID, HICON hIcon, LPCWSTR lpszTip);
	BOOL TaskBarDeleteIcon(HWND hwnd, UINT uID);
	void RemoveTrayIcon();
public:
	afx_msg void OnMenuShow();
	afx_msg void OnMenuQuit();
	afx_msg void OnClose();
	afx_msg BOOL OnQueryOpen();
protected:
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_dataBasePort;
};
