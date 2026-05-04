#pragma once
#include "GUIPropertyLabel.h"

namespace GuiFramework
{
	static struct GUIPropertyFormatter
	{
		static constexpr const dl_wchar* IntegerFormatString = L"%d";
		static constexpr const dl_wchar* UnsignedIntegerFormatString = L"%u";
		static constexpr const dl_wchar* HexFormatString = L"%x";
		static constexpr const dl_wchar* FloatFormatString = L"%.3f";
		static constexpr const dl_wchar* Vector2FormatString = L"%.3f, %.3f";
		static constexpr const dl_wchar* Vector3FormatString = L"%.3f, %.3f, %.3f";
		static constexpr const dl_wchar* Vector4FormatString = L"%.3f, %.3f, %.3f, %.3f";
	};

	static struct GUIBoolFormatter
	{
		static constexpr const dl_wchar* TrueString = L"TRUE";
		static constexpr const dl_wchar* FalseString = L"FALSE";
	};

	template<typename T, typename Formatter = GUIPropertyFormatter>
	class TGUIPropertyLabel : public GUIPropertyLabel
	{
		typedef TGUIPropertyLabel<T, Formatter> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
		virtual dl_bool GetValueString(DLTX::DLString& str) const override
		{
			DLTX::DLFormat::Format(&str, Formatter::IntegerFormatString, *m_value);

			return true;
		}

	private:
		T* m_value;
		Formatter m_formatter;
	};

	template<>
	inline dl_bool TGUIPropertyLabel<dl_bool, GUIBoolFormatter>::GetValueString(DLTX::DLString& str) const
	{
		str = (*m_value) ? GUIBoolFormatter::TrueString : GUIBoolFormatter::FalseString;
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<dl_float32, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat::Format(&str, GUIPropertyFormatter::FloatFormatString, *m_value);
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<DLMT::DL_VECTOR2, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat::Format(&str, GUIPropertyFormatter::Vector2FormatString, m_value->x, m_value->y);
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<DLMT::DL_VECTOR3, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat::Format(&str, GUIPropertyFormatter::Vector3FormatString, m_value->x, m_value->y, m_value->z);
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<DLMT::DL_VECTOR4, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat::Format(&str, GUIPropertyFormatter::Vector4FormatString, m_value->x, m_value->y, m_value->z, m_value->w);
		return true;
	}
}