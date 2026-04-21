#pragma once
#include <dantelion2.h>

#include "GUISignal.h"

namespace GuiFramework
{
	class GUISignalManager
	{
	public:
		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}

	private:
		DLUT::DLVector<GUISignal*> m_pSignals[31];
		DLUT::DLVector<dl_pointer> m_pVar3E0[2];
		dl_int m_state;
	};
}