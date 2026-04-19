#pragma once
#include <dantelion2.h>

struct GUI_KEYSTROKE
{
	dl_uint16 VirtualKey;
	dl_uint16 ScanCode;
	dl_uint Flags;
	dl_wchar UnicodeChar;
};

typedef GUI_KEYSTROKE KeyEvent;