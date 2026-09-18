#pragma once
#include <dantelion2.h>

#include "GUISignalDecl.h"
#include "GuiFramework/System/GUIObject.h"
#include "GuiFramework/System/GUIInvoker.h"

namespace GuiFramework
{
	class GUISignal
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
		GUIObject* m_pSender;
		GUISignalDecl* m_pDecl;
		GUIInvoker* m_pInvoker;
	};
}