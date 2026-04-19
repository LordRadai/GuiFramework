#pragma once
#include <dantelion2.h>

struct _GUI_VIRTUAL_INPUT
{
    dl_int InputID;

    bool IsKeyEvent(dl_char eventID) const
    {
        return InputID == eventID;
    }
};

typedef _GUI_VIRTUAL_INPUT VirtualInput;