#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

class GUISignalDecl
{
public:
	GUISignalDecl() : m_name(L""), m_flags(0) {}
	GUISignalDecl(const dl_wchar* name, dl_uint flags) : m_name(name), m_flags(flags) {}

	static void* operator new(size_t size)
	{
		return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
	}

	static void operator delete(void* block)
	{
		return DLKR::Free(block, GUI_ALLOCATOR);
	}
private:
	const dl_wchar* m_name;
	dl_uint m_flags;
};