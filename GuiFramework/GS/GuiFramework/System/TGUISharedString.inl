#pragma once
#include <dantelion2.h>
#include <Call.h>

#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	template<typename CharT>
	class TGUISharedString
	{
		typedef TGUISharedString<CharT> ThisClass;

		class StringData
		{
		public:
			DLTX::DLBasicString<CharT> m_str;
			dl_int m_nRefCount;
		};

		StringData* m_pData;
		CharT* m_pStr;
	public:
		TGUISharedString() : m_pData(nullptr), m_pStr(nullptr) {}
		TGUISharedString(const CharT* str);
		TGUISharedString(const ThisClass& other);

		~TGUISharedString();

		void Attach(const CharT* str);

		void operator=(const ThisClass& other);

		const CharT* c_str() const { return m_pData->m_str.c_str(); }

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	};

	typedef void(__fastcall* TGUISharedStringCtor_t)(TGUISharedString<dl_wchar>*, const dl_wchar*);
	typedef void(__fastcall* TGUISharedStringCopyCtor_t)(TGUISharedString<dl_wchar>*, const TGUISharedString<dl_wchar>*);
	typedef void(__fastcall* TGUISharedStringDtor_t)(TGUISharedString<dl_wchar>*);

	typedef void(__fastcall* TGUISharedStringAttach_t)(TGUISharedString<dl_wchar>*, const dl_wchar*);

	typedef void(__fastcall* TGUISharedStringAssign_t)(TGUISharedString<dl_wchar>*, const TGUISharedString<dl_wchar>*);

	template<> inline TGUISharedString<dl_wchar>::TGUISharedString(const dl_wchar* str)
	{
		CALL(TGUISharedStringCtor_t, 0x523820, this, str);
	}

	template<> inline TGUISharedString<dl_wchar>::TGUISharedString(const ThisClass& other)
	{
		CALL(TGUISharedStringCopyCtor_t, 0x523850, this, &other);
	}

	template<> inline TGUISharedString<dl_wchar>::~TGUISharedString()
	{
		CALL(TGUISharedStringDtor_t, 0x523980, this);
	}

	template<> inline void TGUISharedString<dl_wchar>::Attach(const dl_wchar* str)
	{
		CALL(TGUISharedStringAttach_t, 0x523e20, this, str);
	}

	template<> inline void TGUISharedString<dl_wchar>::operator=(const ThisClass& other)
	{
		CALL(TGUISharedStringAssign_t, 0x5239c0, this, &other);
	}
}