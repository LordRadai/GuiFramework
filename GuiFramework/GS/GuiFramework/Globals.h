#pragma once
#include <Globals.h>
#include <dantelion2.h>

namespace GuiFramework
{
	namespace GUIAllocator
	{
		static DLKR::DLAllocator*& s_pDefaultAllocator = (*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617108));
		static DLKR::DLAllocator*& s_pStringAllocator = (*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617110));
		static DLKR::DLAllocator*& s_pSTLAllocator = (*(DLKR::DLAllocator**)(MODULE_ADDR + 0x1617118));
	}
}