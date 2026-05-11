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
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	};

	typedef void(_fastcall* TGUILiteralStringCtor_t)(TGUILiteralString<dl_wchar>*, const dl_wchar*);

	template<> inline TGUILiteralString<dl_wchar>::TGUILiteralString(const dl_wchar* str)
	{
		CALL(TGUILiteralStringCtor_t, 0x5237d0, this, str);
	}
}