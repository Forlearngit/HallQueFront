#ifndef CONFIGCARDDEF_H
#define CONFIGCARDDEF_H
#ifndef MAXBUFFERLEN
#define MAXBUFFERLEN 255
#endif
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
		memset(ServerIP,0,MAXBUFFERLEN);
		ServerPort = 0;
		OverTime = 0;
		memset(RegAttchQueID,0,MAXBUFFERLEN);
		RegAttchPageID = -1;
	}
	~_tagCardConnectInfo(){}
public:
	BOOL IsConnect;//�Ƿ�ͷ������Խ�
	WCHAR ServerIP[MAXBUFFERLEN];//ip
	UINT ServerPort;//�˿�
	UINT OverTime;//��ʱʱ��
	WCHAR RegAttchQueID[MAXBUFFERLEN];//���֤����ID
	int RegAttchPageID;//���֤��������ID
}CARDCONNECTINFO,*LPCARDCONNECTINFO;
/////////////////////////////////
#endif