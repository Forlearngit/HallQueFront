#pragma once


// COwnerDrawListBox

class COwnerDrawListBox : public CListBox
{
	DECLARE_DYNAMIC(COwnerDrawListBox)

public:
	COwnerDrawListBox();
	virtual ~COwnerDrawListBox();
public:
	//����ͼ������־����Լ��ҵ�enum
	static enum Item_Pos{ITEM_RIGHT,ITEM_LEFT};
	void SetTextPosition(Item_Pos txPos);//�������־�����
	void SetIconPosition(Item_Pos icPos);//����ͼƬ������
	int AddListBoxItem(const CString strItemName, HICON hDataIcon);//����item
	void DeleteListBoxItem(UINT nItem);
protected:
	//ListBox���ݽṹ��
	struct DataItems
	{
		CString strItemData;
		HICON hIcon;
	};
	DECLARE_MESSAGE_MAP()
private:
	Item_Pos m_textPos;
	Item_Pos m_iconPos;
	DataItems *m_pListBoxDataItems;
	CRect m_rectListBoxItem;
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	void Destroy();
	afx_msg void OnDestroy();
};


