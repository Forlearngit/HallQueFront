#ifndef COMMDAODATA_H
#define COMMDAODATA_H
#include <string>
using namespace std;
struct CommDaoOrg
{
	std::string parOrgID;
	std::string parOrgName;
	std::string curOrgID;
	std::string curOrgName;
//	std::string onlyID;//���ݿ�Ψһ��ʶ
};

struct CommDaoQue
{
	std::string queID;
	std::string queName;
	std::string orgID;
//	std::string onlyID;//���ݿ�Ψһ��ʶ
};

struct CommDaoWnd
{
	std::string wndID;
	std::string wndName;
	std::string orgID;
//	std::string onlyID;//���ݿ�Ψһ��ʶ
};

struct CommDaoStaff
{
	std::string staffID;
	std::string staffName;
	std::string orgID;
//	std::string onlyID;//���ݿ�Ψһ��ʶ
};
#endif