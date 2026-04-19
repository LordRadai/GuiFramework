#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	class GUIInvoker
	{
		typedef GUIInvoker ThisClass;
	public:
		GUIInvoker() {}

		virtual ~GUIInvoker() {}
		virtual void Invoke(DLRF::DLMethodInvokeContext* pCtx) = 0;
		virtual void Invoke(DLRF::DLMethodInvokeContext* pCtx, dl_pointer pSignalInfo) = 0;

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	};
}