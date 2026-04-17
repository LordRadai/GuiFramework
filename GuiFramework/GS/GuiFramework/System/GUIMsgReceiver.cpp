#include "GUIMsgReceiver.h"

namespace GuiFramework
{
	typedef DLRF::DLRuntimeClass* (__fastcall* GetRuntimeClass_t)(const GUIMsgReceiver*);
	typedef void(__fastcall* Destructor_t)(GUIMsgReceiver*);

	DLRF::DLRuntimeClass* GUIMsgReceiver::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClass_t, 0x527eb0, this);
	}

	GUIMsgReceiver::~GUIMsgReceiver()
	{
		CALL(Destructor_t, 0x528100, this);
	}
}