#pragma once
#include <dantelion2.h>

#include "GuiFramework/Globals.h"

namespace GuiFramework
{
    struct GUI_MOUSE_INFO
    {
        dl_int EventID;
        dl_int iVar4;
        dl_int X;
        dl_int Y;
    };

    static void* operator new(size_t size)
    {
        return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
	}

    static void operator delete(void* block)
    {
        return DLKR::Free(block, GUI_ALLOCATOR);
	}

    typedef LRESULT GUI_NCHIT;
    typedef GUI_MOUSE_INFO MouseEvent;
}