#ifndef CONFIGCARDDEF_H
#define CONFIGCARDDEF_H
#include "TrackDef.h"
////////////ʶ����Ϣ
typedef struct _tagDistinguishCard
{
	UINT postion;//λ��
	UINT toValue;//��Ӧ��ֵ
}DISTINGUISHCARD,*LPDISTINGUISHCARD;
////////////////////////////
/////////////���Խ�������Ϣ
typedef struct _tagCardConnectInfo
{
public:
	_tagCardConnectInfo(){
		IsConnect = FALSE;
		memset(ServerIP,0,addNum);
		ServerPort = 0;
		OverTime = 0;
		memset(RegAttchQueID,0,addNum);
		RegAttchPageID = -1;
	}
	~_tagCardConnectInfo(){}
public:
	BOOL IsConnect;//�Ƿ�ͷ������Խ�
	WCHAR ServerIP[addNum];//ip
	UINT ServerPort;//�˿�
	UINT OverTime;//��ʱʱ��
	WCHAR RegAttchQueID[addNum];//���֤����ID
	int RegAttchPageID;//���֤��������ID
}CARDCONNECTINFO,*LPCARDCONNECTINFO;
/////////////////////////////////
#endif