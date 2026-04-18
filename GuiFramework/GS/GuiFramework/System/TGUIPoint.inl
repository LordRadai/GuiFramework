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
    };
}
