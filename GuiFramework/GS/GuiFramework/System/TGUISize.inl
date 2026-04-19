#pragma once
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	template<typename T>
	struct TGUI_SIZE
	{
		T Width;
		T Height;

		TGUI_SIZE() : Width(0), Height(0) {}
		TGUI_SIZE(T width, T height) : Width(width), Height(height) {}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	};
}