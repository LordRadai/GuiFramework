#pragma once
#include <dantelion2.h>
#include "GuiFramework/System/GUIObject.h"
#include "GuiFramework/System/GUIInvoker.h"

namespace GuiFramework
{
	class GUISignal
	{
	public:
		class GUISignalDecl
		{
			const dl_wchar* m_name;
			dl_uint m_flags;
		};

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}

	private:
		GUIObject* m_pSender;
		GUISignalDecl* m_pDecl;
		GUIInvoker* m_pInvoker;
	};
}