#include "GUILayoutItem.h"

namespace GuiFramework
{
	DLRF::DLRuntimeClass* GUILayoutItem::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5c9330, this);
	}

	GUILayoutItem::~GUILayoutItem()
	{
		CALL(Destructor_t, 0x5c95c0, this);
	}
}