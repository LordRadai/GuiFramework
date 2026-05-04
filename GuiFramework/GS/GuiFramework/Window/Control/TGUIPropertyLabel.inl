#pragma once
#include "GUIPropertyLabel.h"

namespace GuiFramework
{
	static struct GUIPropertyFormatter
	{
		static constexpr const dl_char* FormatString = "%d";
	};

	static struct GUIBoolFormatter
	{
		static constexpr const dl_char* TrueString = "TRUE";
		static constexpr const dl_char* FalseString = "FALSE";
	};;

	template<typename T, typename Formatter = GUIPropertyFormatter>
	class TGUIPropertyLabel : public GUIPropertyLabel
	{
		typedef TGUIPropertyLabel<T, Formatter> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
		virtual dl_bool GetValueString(DLTX::DLString& str) const override
		{
			DLTX::DLFormat::Format(&str, Formatter::FormatString, *m_value);

			return true;
		}

	private:
		T* m_value;
		Formatter m_formatter;
	};
}