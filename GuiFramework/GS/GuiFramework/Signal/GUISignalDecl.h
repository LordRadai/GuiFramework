#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	class GUISignalDecl
	{
	public:
		GUISignalDecl() : m_name(""), m_flags(0) {}
		GUISignalDecl(const dl_char* name, dl_uint flags) : m_name(name), m_flags(flags) {}

		static void* operator new(size_t size)
		{
			return DLKR::AllocationSupporter<DLKR::DLAllocator>::Allocate(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::AllocationSupporter<DLKR::DLAllocator>::Deallocate(block, GUI_ALLOCATOR);
		}
	private:
		const dl_char* m_name;
		dl_uint m_flags;
	};
}