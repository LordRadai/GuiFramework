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
            return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Allocate(size, 8, GuiFramework_GUIAllocator_s_pDefaultAllocator);
        }

        static void operator delete(void* p)
        {
            DLKRD::AllocationSupporter<DLKR::DLAllocator>::Deallocate(p, GuiFramework_GUIAllocator_s_pDefaultAllocator);
        }
    };

    typedef TGUI_POINT<dl_int> Point2D;
}
