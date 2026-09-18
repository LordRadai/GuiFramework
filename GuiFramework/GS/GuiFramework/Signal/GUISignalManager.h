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
			return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Allocate(size, 8, GUIAllocator::s_pDefaultAllocator);
		}

		static void operator delete(void* block)
		{
			return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Deallocate(block, GUIAllocator::s_pDefaultAllocator);
		}

	private:
		DLUT::DLVector<GUISignal*> m_pSignals[31];
		DLUT::DLVector<dl_pointer> m_pVar3E0[2];
		dl_int m_state;
	};
}