#include "GUITimer.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUITimer*, GUISystem*);

	GUITimer::GUITimer(GUISystem* pGUISystem)
	{
		CALL(Constructor_t, 0x5901d0, this, pGUISystem);
	}

	DLRF::DLRuntimeClass* GUITimer::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x590180, this);
	}

	GUITimer::~GUITimer()
	{
		CALL(Destructor_t, 0x5908d0, this);
	}
}