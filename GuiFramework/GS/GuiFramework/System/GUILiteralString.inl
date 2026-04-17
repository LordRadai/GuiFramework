#pragma once
#include "GUISharedString.inl"
#include <Call.h>

namespace GuiFramework
{
	template<typename CharT>
	class TGUILiteralString : public TGUISharedString<CharT>
	{
		typedef TGUILiteralString<CharT> ThisClass;
	public:
		TGUILiteralString() : TGUISharedString<CharT>() {}
		TGUILiteralString(const CharT* str);
	};

	typedef void(__fastcall* TGUILiteralStringCtor_t)(TGUILiteralString<dl_wchar>*, const dl_wchar*);

	template<> inline TGUILiteralString<dl_wchar>::TGUILiteralString(const dl_wchar* str)
	{
		CALL(TGUILiteralStringCtor_t, 0x5237d0, this, str);
	}
}