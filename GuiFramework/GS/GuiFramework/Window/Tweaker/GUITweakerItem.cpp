#include "GUITweakerItem.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUITweakerItem*);

	GUITweakerItem::GUITweakerItem()
	{
		CALL(Constructor_t, 0x555680, this);
	}

	GUITweakerItem::~GUITweakerItem()
	{
		CALL(Destructor_t, 0x555cf0, this);
	}

	void GUITweakerItem::_Destroy()
	{
		CALL(_Destroy_t, 0x5556c0, this);
	}
}
