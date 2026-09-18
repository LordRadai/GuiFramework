#pragma once
#include <Globals.h>
#include <dantelion2.h>

namespace GuiFramework
{
	namespace GUIAllocator
	{
#define GuiFramework_GUIAllocator_s_pDefaultAllocator				(*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617108))
#define GuiFramework_GUIAllocator_s_pStringAllocator				(*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617110))
#define GUIFramework_GUIAllocator_s_pSTLAllocator					(*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617118))
	}
}