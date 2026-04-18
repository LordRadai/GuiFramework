#pragma once
#include <dantelion2.h>
#include "GUISignal.h"

namespace GuiFramework
{
	class GUISignalManager
	{
		DLUT::DLVector<GUISignal*> m_pSignals[31];
		DLUT::DLVector<dl_pointer> m_pVar3E0[2];
		dl_int m_state;
	public:
	};
}
