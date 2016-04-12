#pragma once
#include "THashTable.h"
#include "TBitmap.h"
class TBitmapMgr
{
public:
	static TBitmapMgr& GetInstance()
	{
		static TBitmapMgr  mgr;
		return mgr;
	}
public:
	TLinkedList<TBitmap>   m_List;
	THashTable<TBitmap>    m_Hash;
private:
	TLinkedList<TBitmap>   m_InitList;
public:
	TBitmap*  Load(TCHAR* pszLoadFile);
	TBitmap*  Find(int iIndex);
	void    Sort(bool bUp = true);
	void    Release();
	void    ShowData();
	void    ShowData(TBitmap* pStd);
	void    Delete(int iIndex) {};
	void    Delete(TBitmap* iData) {};
	TNode<TBitmap> * Swap(
		TNode<TBitmap>* a,
		TNode<TBitmap>* b);
	TBitmap*  Find(TCHAR* pszName);
private:
	TBitmapMgr();
public:
	~TBitmapMgr();
};
