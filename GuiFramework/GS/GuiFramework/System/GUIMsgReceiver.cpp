#include "GUIMsgReceiver.h"

namespace GuiFramework
{
	DLRF::DLRuntimeClass* GUIMsgReceiver::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x527eb0, this);
	}

	GUIMsgReceiver::~GUIMsgReceiver()
	{
		CALL(Destructor_t, 0x528100, this);
	}

	void GUIMsgReceiver::_Destroy()
	{
		CALL(_Destroy_t, 0x527f40, this);
	}
}