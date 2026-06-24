#include "GUIFormatter.h"

namespace GuiFramework 
{
	const dl_wchar* GUIPropertyFormatter::IntegerFormatString = L"%d";
	const dl_wchar* GUIPropertyFormatter::UnsignedIntegerFormatString = L"%u";
	const dl_wchar* GUIPropertyFormatter::HexFormatString = L"%x";
	const dl_wchar* GUIPropertyFormatter::FloatFormatString = L"%.3f";
	const dl_wchar* GUIPropertyFormatter::Vector2FormatString = L"%.3f, %.3f";
	const dl_wchar* GUIPropertyFormatter::Vector3FormatString = L"%.3f, %.3f, %.3f";
	const dl_wchar* GUIPropertyFormatter::Vector4FormatString = L"%.3f, %.3f, %.3f, %.3f";

	const dl_wchar* GUIBoolFormatter::TrueString = L"TRUE";
	const dl_wchar* GUIBoolFormatter::FalseString = L"FALSE";
}