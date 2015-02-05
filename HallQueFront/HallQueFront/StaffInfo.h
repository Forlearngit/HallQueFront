#pragma once

// CStaffInfo ����Ŀ��

class CStaffInfo : public CObject
{
public:
	CStaffInfo();
	 ~CStaffInfo();
	 CStaffInfo(const CStaffInfo& obj);//���ؿ�������͸�ֵ
	 CStaffInfo& operator=(const CStaffInfo& obj);
private:
	CString m_StaffName;
	CString m_StaffId;//Ա����
	CString m_StaffGender;//Ա���Ա�
	CString m_StaffPhotoPath;//��Ƭ·��
	
public:
	CString GetStaffName()const {return m_StaffName;}
	void SetStaffName(const CString& StaffName){m_StaffName=StaffName;}
	CString GetStaffId()const {return m_StaffId;}
	void SetStaffId(const CString& StaffId){m_StaffId=StaffId;}
	CString GetStaffSex()const {return m_StaffGender;}
	void SetStaffSex(const CString& StaffGender){m_StaffGender=StaffGender;}
	CString GetStaffPhotoPath()const {return m_StaffPhotoPath;}
	void SetStaffPhotoPath(const CString& StaffPhotoPath){m_StaffPhotoPath=StaffPhotoPath;}

	virtual void Serialize( CArchive& ar );
	DECLARE_SERIAL(CStaffInfo)
};


