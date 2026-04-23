#include "GUITweakerItem.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUITweakerItem*);

	GUITweakerItem::GUITweakerItem()
	{
		CALL(Constructor_t, 0x555680, this);
	}

	GUITweakerItem::~GUITweakerItem()
	{
		CALL(Destructor_t, 0x555cf0, this);
	}
}
