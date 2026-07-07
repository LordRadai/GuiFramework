#include "GUICallbackObjectBase.h"

DLRF::DLRuntimeClass* GuiFramework::GUICallbackObjectBase::GetRuntimeClassOfThis() const
{
	return CALL(GetRuntimeClassOfThis_t, 0x530340, this);
}