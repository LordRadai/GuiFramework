#pragma once
#include <dantelion2.h>
#include <Call.h>

template<typename T>
class TGUIStringStorage
{
	DLUT::DLVector<T> m_pStringStorageList[53];
	dl_char m_buffer[212];
public:
	TGUIStringStorage();

	virtual ~TGUIStringStorage();
};

typedef void(__fastcall* TGUIStringStorage_ctor_t)(TGUIStringStorage<dl_wchar>* This);
typedef void(__fastcall* TGUIStringStorage_dtor_t)(TGUIStringStorage<dl_wchar>* This);

template<> TGUIStringStorage<dl_wchar>::TGUIStringStorage()
{
	CALL(TGUIStringStorage_ctor_t, 0x52dba0, this);
}

template<> TGUIStringStorage<dl_wchar>::~TGUIStringStorage()
{
	CALL(TGUIStringStorage_dtor_t, 0x52df30, this);
}
