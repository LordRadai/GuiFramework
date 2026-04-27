#pragma once
#include <dantelion2.h>
#include "TGUIPoint.inl"

namespace GuiFramework
{
    struct GUI_MOUSE_INFO
    {
        Point2D Pos;
        dl_int EventID;
        dl_int iVar4;

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GUI_ALLOCATOR);
        }
    };

    typedef GUI_MOUSE_INFO MouseEvent;
}