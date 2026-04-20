#pragma once
#include <Globals.h>

namespace GuiFramework
{
#define GUI_ALLOCATOR (DLKR::DLAllocator*)(MODULE_ADDR + 0x1617108)
#define GUI_STL_ALLOCATOR (DLKR::DLAllocator*)(MODULE_ADDR + 0x1617118)
}