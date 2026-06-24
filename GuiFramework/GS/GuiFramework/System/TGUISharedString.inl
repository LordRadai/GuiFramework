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
			DLTX::DLBasicString<CharT, std::char_traits<CharT>> m_str;
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
		void Detatch(dl_int start, dl_int end);

		void format(const CharT* fmt, ...)
		{
			va_list args;
			va_start(args, fmt);
			formatV(fmt, args);
			va_end(args);
		}

		void formatV(const CharT* fmt, va_list args);

		void operator=(const ThisClass& other);

		DLTX::DLBasicString<CharT>* GetUnSharedString() const;

		const CharT* c_str() const { return m_pData->m_str.c_str(); }

		const CharT* safe_c_str() const 
		{
			static const DLTX::DLBasicString<CharT, std::char_traits<CharT>> c;

			return m_pData ? m_pData->m_str.c_str() : c.c_str(); 
		}

		const dl_int empty() const { return m_pData == nullptr || m_pData->m_str.empty(); }
		const dl_size size() const { return m_pData ? m_pData->m_str.size() : 0; }
		const dl_size length() const { return size(); }

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	};

	typedef void(_fastcall* TGUISharedStringCtor_t)(TGUISharedString<dl_wchar>*, const dl_wchar*);
	typedef void(_fastcall* TGUISharedStringCopyCtor_t)(TGUISharedString<dl_wchar>*, const TGUISharedString<dl_wchar>*);
	typedef void(_fastcall* TGUISharedStringDtor_t)(TGUISharedString<dl_wchar>*);

	typedef void(_fastcall* TGUISharedStringAttach_t)(TGUISharedString<dl_wchar>*, const dl_wchar*);
	typedef void(_fastcall* TGUISharedStringDetatch_t)(TGUISharedString<dl_wchar>*, dl_int, dl_int);
	typedef void(_fastcall* TGUISharedStringFormatV_t)(TGUISharedString<dl_wchar>*, const dl_wchar*, va_list);

	typedef void(_fastcall* TGUISharedStringAssign_t)(TGUISharedString<dl_wchar>*, const TGUISharedString<dl_wchar>*);

	typedef DLTX::DLBasicString<wchar_t, std::char_traits<dl_wchar>>* (*TGUISharedStringUnshared_t)(const TGUISharedString<wchar_t>*);			

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

	template<> inline void TGUISharedString<dl_wchar>::Detatch(dl_int start, dl_int end)
	{
		CALL(TGUISharedStringDetatch_t, 0x523f20, this, start, end);
	}

	template<> inline void TGUISharedString<dl_wchar>::formatV(const dl_wchar* fmt, va_list args)
	{
		CALL(TGUISharedStringFormatV_t, 0x523f80, this, fmt, args);
	}

	template<> inline void TGUISharedString<dl_wchar>::operator=(const ThisClass& other)
	{
		CALL(TGUISharedStringAssign_t, 0x5239c0, this, &other);
	}

	template<> inline DLTX::DLBasicString<dl_wchar>* TGUISharedString<dl_wchar>::GetUnSharedString() const
	{
		return CALL(TGUISharedStringUnshared_t, 0x523a20, this);
	}
}