#pragma once
#include "TGUISharedString.inl"

namespace GuiFramework
{
	template<typename T>
	class TGUI_VALUE_STRING_PAIR
	{
	public:
		TGUI_VALUE_STRING_PAIR() : m_value(), m_string() {}
		TGUI_VALUE_STRING_PAIR(const T& value, const TGUI_SHARED_STRING& str) : m_value(value), m_string(str) {}

		operator=(const TGUI_VALUE_STRING_PAIR& other)
		{
			m_string = other.m_string;
			m_value = other.m_value;

			return *this;
		}

		TGUISharedString<T> m_string;
		T m_value;
	};
}