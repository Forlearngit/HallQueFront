#ifndef  PRINTDEF_H
#define PRINTDEF_H

typedef enum _tagEnumPrintObjectEnum
{
	enumPrintType = 0,//ҵ������(����)
	enumPrintWaitNum = 1,//�Ŷ�����
	enumPrintClientNum = 2,//�ͻ�����
	enumPrintClientName = 3,//�ͻ�����
	enumPrintClientLevel  = 4, //�ͻ��Ǽ�
	enumPrintCustProduct = 5 //�ͻ����в�Ʒ
}EnumPrintObject;

typedef enum _tagEnumPrintStatus
{
	enumPrintErr = -1,//��ӡ����
	enumPrintPaperOut = -2,//ȱֽ
	enumPrintOffline = -3,//����
	enumPrintPrinting = 0,//���ڴ�ӡ�����ܴ�ӡ�����ֹ���
	enumPrintNormal = 1,//��ӡ������
	enumPrintNoDefPrinter = -4,//û��Ĭ�ϴ�ӡ��
	enumPrintFailedJob = -5//��ȡjobʧ��
}EnumPrintStaus;

const CString CS_printType = _T("���ڶ���");
const CString CS_printWaitNum = _T("�Ⱥ�����");
const CString CS_printClientNum = _T("�ͻ�����");
const CString CS_printClientName = _T("�ͻ�����");
const CString CS_printClientLevel = _T("�ͻ��Ǽ�");
const CString CS_printCustProduct = _T("�ͻ����в�Ʒ");

const double PI = 3.14159265359;
#endif