#pragma once
#include <dantelion2.h>

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
}