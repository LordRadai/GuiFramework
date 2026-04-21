#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	class GUIRenderContext
	{
		typedef GUIRenderContext ThisClass;
	public:
		// Empty for now

		static void* operator new(dl_size size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* p)
		{
			DLKR::Free(p, GUI_ALLOCATOR);
		}
	};

	typedef GUIRenderContext GraphicsContext;
}
