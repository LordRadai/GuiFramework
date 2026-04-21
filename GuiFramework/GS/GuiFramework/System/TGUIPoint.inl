#pragma once

namespace GuiFramework
{
    template<typename T>
    struct TGUI_POINT
    {
        T X;
        T Y;

        TGUI_POINT() : X(0), Y(0) {}
        TGUI_POINT(T x, T y) : X(x), Y(y) {}

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
        }
    };

    typedef TGUI_POINT<int> Point2D;
}
