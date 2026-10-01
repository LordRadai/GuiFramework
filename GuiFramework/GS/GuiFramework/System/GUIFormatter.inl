#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	struct GUIPropertyFormatter
	{
		static void Format(DLTX::DLString& str, dl_int8 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_uint8 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_int16 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_uint16 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_int value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_uint value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_int64 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_uint64 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		static void Format(DLTX::DLString& str, dl_float32 value)
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f", value);
		}

		static void Format(DLTX::DLString& str, dl_float64 value)
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
			if (value)
				DLTX::DLFormat<dl_wchar>::Format(str, L"TRUE");
			else
				DLTX::DLFormat<dl_wchar>::Format(str, L"FALSE");
		}
	};

	struct GUIYesNoFormatter
	{
		static void Format(DLTX::DLString& str, dl_bool value)
		{
			if (value)
				DLTX::DLFormat<dl_wchar>::Format(str, L"Yes");
			else
				DLTX::DLFormat<dl_wchar>::Format(str, L"No");
		}
	};

	struct GUICircleCrossFormatter
	{
		static void Format(DLTX::DLString& str, dl_bool value)
		{
			if (value)
				DLTX::DLFormat<dl_wchar>::Format(str, L"○");
			else
				DLTX::DLFormat<dl_wchar>::Format(str, L"×");
		}
	};
}