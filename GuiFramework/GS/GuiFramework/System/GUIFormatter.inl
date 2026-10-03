#pragma once
#include <dantelion2.h>
#include "GuiFramework/System/TGUIValueStringPair.inl"

namespace GuiFramework
{
	struct GUIPropertyFormatter
	{
		void Format(DLTX::DLString& str, dl_bool value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_int8 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_uint8 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_int16 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_uint16 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_int value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_uint value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_int64 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_uint64 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%d", value);
		}

		void Format(DLTX::DLString& str, dl_float32 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f", value);
		}

		void Format(DLTX::DLString& str, dl_float64 value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f", value);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_VECTOR2& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f", value.x, value.y);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_VECTOR2AL& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f", value.x, value.y);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_VECTOR3& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f", value.x, value.y, value.z);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_VECTOR3AL& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f", value.x, value.y, value.z);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_VECTOR4& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f , %.3f", value.x, value.y, value.z, value.w);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_VECTOR4AL& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f , %.3f", value.x, value.y, value.z, value.w);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_QUATERNION& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f , %.3f", value.x, value.y, value.z, value.w);
		}

		void Format(DLTX::DLString& str, const DLMT::DL_QUATERNIONAL& value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%.3f , %.3f , %.3f , %.3f", value.x, value.y, value.z, value.w);
		}

		void Format(DLTX::DLString& str, const dl_char* value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%hs", value);
		}

		void Format(DLTX::DLString& str, const dl_wchar* value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%s", value);
		}
	};

	struct GUIBoolFormatter
	{
		void Format(DLTX::DLString& str, dl_bool value) const
		{
			if (value)
				DLTX::DLFormat<dl_wchar>::Format(str, L"TRUE");
			else
				DLTX::DLFormat<dl_wchar>::Format(str, L"FALSE");
		}
	};

	struct GUIYesNoFormatter
	{
		void Format(DLTX::DLString& str, dl_bool value) const
		{
			if (value)
				DLTX::DLFormat<dl_wchar>::Format(str, L"Yes");
			else
				DLTX::DLFormat<dl_wchar>::Format(str, L"No");
		}
	};

	struct GUICircleCrossFormatter
	{
		void Format(DLTX::DLString& str, dl_bool value) const
		{
			if (value)
				DLTX::DLFormat<dl_wchar>::Format(str, L"O");
			else
				DLTX::DLFormat<dl_wchar>::Format(str, L"X");
		}
	};

	template<typename T>
	struct TGUIValueToStringFormatter
	{
		TGUIValueStringPairData<T> m_valueStringPairData;

		TGUIValueToStringFormatter(const TGUIValueStringPairData<T>& valueStringPairData) : m_valueStringPairData(valueStringPairData) {}

		void Format(DLTX::DLString& str, T value) const
		{
			DLTX::DLFormat<dl_wchar>::Format(str, L"%s", m_valueStringPairData.GetStringByValue(value));
		}
	};
}