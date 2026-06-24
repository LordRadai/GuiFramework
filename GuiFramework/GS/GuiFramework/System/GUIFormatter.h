#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	static struct GUIPropertyFormatter
	{
		static const dl_wchar* IntegerFormatString;
		static const dl_wchar* UnsignedIntegerFormatString;
		static const dl_wchar* HexFormatString;
		static const dl_wchar* FloatFormatString;
		static const dl_wchar* Vector2FormatString;
		static const dl_wchar* Vector3FormatString;
		static const dl_wchar* Vector4FormatString;
	};

	static struct GUIBoolFormatter
	{
		static const dl_wchar* TrueString;
		static const dl_wchar* FalseString;
	};
}