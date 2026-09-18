#pragma once
#include "TGUISharedString.inl"
#include <Call.h>

namespace GuiFramework
{
	template<typename CharT>
	class TGUILiteralString : public TGUISharedString<CharT>
	{
		typedef TGUILiteralString<CharT> ThisClass;
		typedef TGUISharedString<CharT> SuperClass;
	public:
		TGUILiteralString() : TGUISharedString<CharT>() {}
		TGUILiteralString(const CharT* str);

		static void* operator new(size_t size)
		{
			return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Allocate(size, 8, GUIAllocator::s_pDefaultAllocator);
		}

		static void operator delete(void* block)
		{
			return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Deallocate(block, GUIAllocator::s_pDefaultAllocator);
		}
	};

	typedef void(_fastcall* TGUILiteralStringCtor_t)(TGUILiteralString<dl_wchar>*, const dl_wchar*);

	template<> inline TGUILiteralString<dl_wchar>::TGUILiteralString(const dl_wchar* str)
	{
		CALL(TGUILiteralStringCtor_t, 0x5237d0, this, str);
	}

	typedef TGUILiteralString<dl_wchar> GUIString;
}