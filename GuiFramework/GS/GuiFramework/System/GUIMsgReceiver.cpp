#include "GUIMsgReceiver.h"

namespace GuiFramework
{
	DLRF::DLRuntimeClass* GUIMsgReceiver::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClass_t, 0x527eb0, this);
	}

	GUIMsgReceiver::~GUIMsgReceiver()
	{
		CALL(Destructor_t, 0x528100, this);
	}
}