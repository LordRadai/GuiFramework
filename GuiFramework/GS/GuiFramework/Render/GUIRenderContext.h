#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	class GUIRenderContext
	{
		typedef GUIRenderContext ThisClass;
	public:
		// Empty for now

		static void* operator new(dl_size size)
		{
			return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Allocate(size, 8, GUIAllocator::s_pDefaultAllocator);
		}

		static void operator delete(void* p)
		{
			DLKRD::AllocationSupporter<DLKR::DLAllocator>::Deallocate(p, GUIAllocator::s_pDefaultAllocator);
		}
	};

	typedef GUIRenderContext GraphicsContext;
}
