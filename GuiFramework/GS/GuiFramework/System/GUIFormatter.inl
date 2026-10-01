#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	struct GUIPropertyFormatter
	{
		static void Format(DLTX::DLString& str, dl_int value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_float32 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f", value);
		}

		static void Format(DLTX::DLString& str, const DLMT::DL_VECTOR2& value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f", value.x, value.y);
		}

		static void Format(DLTX::DLString& str, const DLMT::DL_VECTOR3& value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f", value.x, value.y, value.z);
		}

		static void Format(DLTX::DLString& str, const DLMT::DL_VECTOR4& value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f , %.3f", value.x, value.y, value.z, value.w);
		}
	};

	struct GUIBoolFormatter
	{
		static void Format(DLTX::DLString& str, dl_bool value)
		{
			str = value ? L"TRUE" : L"FALSE";
		}
	};

	static struct GUICircleCrossFormatter
	{
		static void Format(DLTX::DLString& str, dl_bool value)
		{
			str = value ? L"○" : L"×";
		}
	};
}