#pragma once
#include "DataDef.h"

class SLZStaff : public CObject
{
public:
	SLZStaff(void);
	~SLZStaff(void);
	SLZStaff(const SLZStaff& staff);
	SLZStaff& operator=(const SLZStaff& staff);

	DECLARE_SERIAL(SLZStaff)

	//��ȡԱ�����
	CString GetStaffId() const
	{
		return m_strStaffId;
	}
	//����Ա�����
	void SetStaffId(const CString& strStaffId)
	{
		m_strStaffId = strStaffId;
	}
	//��ȡԱ������
	CString GetStaffName() const
	{
		return m_strStaffName;
	}
	//����Ա������
	void SetStaffName(const CString& strStaffName)
	{
		m_strStaffName = strStaffName;
	}
	//��ȡԱ���Ա�
	GENDER GetStaffGender() const
	{
		return m_iGender;
	}
	//����Ա���Ա�
	void SetStaffGender(GENDER gender)
	{
		m_iGender = gender;
	}
	//��ȡԱ����Ƭ
	CString GetStaffPhoto() const
	{
		return m_strPhotoPath;
	}
	//����Ա����Ƭ
	void SetStaffPhoto(CString strPhotoPath)
	{
		m_strPhotoPath = strPhotoPath;
	}
	////��ȡ��������ַ
	//int GetCallerId() const
	//{
	//	return m_iCallerId;
	//}
	////���ú�������ַ
	//void SetCallerId(int iCallerId)
	//{
	//	m_iCallerId = iCallerId;
	//}
	////��ȡ��������ַ
	//int GetEvaluatorId() const
	//{
	//	return m_iEvaluatorId;
	//}
	////������������ַ
	//void SetEvaluatorId(int iEvaluatorId)
	//{
	//	m_iEvaluatorId = iEvaluatorId;
	//}
	virtual void Serialize( CArchive& ar );

private:
	CString m_strStaffId;	//Ա�����
	CString m_strStaffName;	//Ա������
	GENDER m_iGender;		//�Ա�
	CString m_strPhotoPath;	//��Ƭ·��


	//int m_iBirthYear;		//������
	//int m_iBirthMon;		//������
	//int m_iBirthDay;		//������
	////int m_iAge;				//����
	//int m_iEntryYear;		//��ְ��
	//int m_iEntryMon;		//��ְ��
	//int m_iEntryDay;		//��ְ��
	////int m_iSeniority;		//����
};

//IMPLEMENT_SERIAL(SLZStaff,CObject,1)

