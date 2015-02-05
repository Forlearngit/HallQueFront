#pragma once
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class CConnectToMySql
{
public:
	CConnectToMySql(void);
	~CConnectToMySql(void);
private:
	sql::Driver* m_pSqlDriver;
//	std::auto_ptr<sql::Connection> m_sqlCon;
	sql::Connection* m_pSqlCon;
//	std::auto_ptr<sql::Statement> m_sqlStatement;
	sql::Statement* m_pSqlState;
//	std::auto_ptr<sql::ResultSet> m_sqlRes;
public:
	BOOL ConnectToDB(const CString& IP,const USHORT port,const CString& UserName,
		const CString& passWord);//�������ݿ�
public:
	BOOL Execute(const CString& sql);//ִ����䲻�������ݼ�
	std::auto_ptr<sql::ResultSet> ExecuteQuery(const CString& sql);//ִ��sql��䷵�����ݼ�
	//ע���ж�ִ���������쳣����ָ��Ϊ�յ�����
public:
	BOOL IsConnect();
//	CString m_dataBasePath;
//	BOOL ReadDataBaseInfo();
};
