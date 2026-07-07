#pragma once
#include "TGUIPoint.inl"

namespace GuiFramework
{
	template <typename T>
	struct TGUI_SIZE : public TGUI_POINT<T>
	{
	};
}