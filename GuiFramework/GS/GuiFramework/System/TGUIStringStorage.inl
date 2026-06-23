#pragma once
#include <dantelion2.h>
#include <Call.h>

#include "GuiFramework/Globals.h"

template<typename T>
class TGUIStringStorage
{
	DLUT::DLVector<T> m_pStringStorageList[53];
	dl_char m_buffer[212];
public:
	TGUIStringStorage();

	virtual ~TGUIStringStorage();

	static void* operator new(size_t size)
	{
		return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
	}

	static void operator delete(void* block)
	{
		return DLKR::Free(block, GUI_ALLOCATOR);
	}
};

typedef void(_fastcall* WChar_Ctor_t)(TGUIStringStorage<dl_wchar>* This);
typedef void(_fastcall* WChar_Dtor_t)(TGUIStringStorage<dl_wchar>* This);

template<> inline TGUIStringStorage<dl_wchar>::TGUIStringStorage()
{
	CALL(WChar_Ctor_t, 0x52dba0, this);
}

template<> inline TGUIStringStorage<dl_wchar>::~TGUIStringStorage()
{
	CALL(WChar_Dtor_t, 0x52df30, this);
}
