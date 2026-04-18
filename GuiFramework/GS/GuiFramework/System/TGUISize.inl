#pragma once

namespace GuiFramework
{
	template<typename T>
	struct TGUI_SIZE
	{
		T Width;
		T Height;

		TGUI_SIZE() : Width(0), Height(0) {}
		TGUI_SIZE(T width, T height) : Width(width), Height(height) {}
	};
}