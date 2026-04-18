#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
    struct GUI_MOUSE_INFO
    {
        dl_int EventID;
        dl_int iVar4;
        dl_int X;
        dl_int Y;
    };

    typedef LRESULT GUI_NCHIT;
    typedef GUI_MOUSE_INFO MouseEvent;
}