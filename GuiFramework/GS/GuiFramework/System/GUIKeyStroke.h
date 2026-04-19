#pragma once
#include <dantelion2.h>

#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	struct GUI_KEYSTROKE
	{
		dl_uint16 VirtualKey;
		dl_uint16 ScanCode;
		dl_uint Flags;
		dl_wchar UnicodeChar;

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	};

	typedef GUI_KEYSTROKE KeyEvent;
}