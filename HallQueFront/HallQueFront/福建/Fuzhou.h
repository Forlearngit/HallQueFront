#ifndef FUZHOU_H
#define FUZHOU_H
#include <string>
using namespace std;
typedef struct recvCustLev
{
	BOOL isSucced;//�Ƿ�ɹ�
	int highestCardLev;//��߿�����
	int cardLev;//ˢ������
	int custLev;//���пͻ�����
	int custLevAll;//���м���
	int creditCardLev;//���ÿ���߼���
	string strAubm;//�����ʲ��ܶ�
	string strAubmMavg;//�����ʲ��ܶ����վ�
	string strAubmQavg;//�����ʲ����վ�
	string strAubmYavg;//�����ʲ����վ�
	int proForCust[15];//�ͻ����в�Ʒ,����Ϊ:��ơ����𡢵��ӹ�ծ��ƾ֤��ծ�����������ա����������ÿ�������֪ͨ����ӯ��ͨ�˻��������������ƶ����С�ATM����ת�ˡ������޿�֧�������ÿ����������������
}CustLev;

#endif