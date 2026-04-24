#pragma once

#include "GuiFramework/Globals.h"

namespace GuiFramework
{
    template<typename T>
    struct TGUI_RECT
    {
        T MinX;
        T MinY;
        T MaxX;
        T MaxY;

        TGUI_RECT() : MinX(0), MinY(0), MaxX(0), MaxY(0) {}
        TGUI_RECT(T minX, T minY, T maxX, T maxY) : MinX(minX), MinY(minY), MaxX(maxX), MaxY(maxY) {}

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GUI_ALLOCATOR);
		}

        TGUI_RECT operator+(const TGUI_RECT& other) const
        {
            return TGUI_RECT(MinX + other.MinX, MinY + other.MinY, MaxX + other.MaxX, MaxY + other.MaxY);
		}

        TGUI_RECT operator+(dl_uint value) const
        {
            return TGUI_RECT(MinX + value, MinY + value, MaxX + value, MaxY + value);
        }
    };

	typedef TGUI_RECT<dl_int16> Rect16;
    typedef TGUI_RECT<dl_int> Rect;
}