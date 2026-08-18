#pragma once
#include <Globals.h>
#include <dantelion2.h>

namespace GuiFramework
{
	namespace GUIAllocator
	{
#define GUI_ALLOCATOR       (*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617108))
#define STRING_ALLOCATOR    (*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617110))
#define GUI_STL_ALLOCATOR   (*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617118))
	}
}