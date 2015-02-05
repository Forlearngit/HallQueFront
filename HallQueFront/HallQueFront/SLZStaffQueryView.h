#pragma once
#include "SLZStaff.h"
#include <map>
using namespace std;

class SLZStaffQueryView
{
public:
	SLZStaffQueryView(void);
	~SLZStaffQueryView(void);
	//���������ļ��е�Ա����Ϣ�����ڴ�
	BOOL LoadStaffs();
	//
	SLZStaff* QueryStaffById(CString strStaffId);
	//
	void Clear();
public:
//	CMap<CString, LPCTSTR, SLZStaff*, SLZStaff*&> m_mapIdStaff;
	std::map<CString,SLZStaff*> m_mapIdStaff;
};
