#include "GUITextureBase.h"
#include <Call.h>

namespace GuiFramework
{
	DLRF::DLRuntimeClass* GUITextureBase::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5270b0, this);
	}
}