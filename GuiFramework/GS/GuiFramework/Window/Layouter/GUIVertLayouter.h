#pragma once
#include "GUILayouter.h"

namespace GuiFramework
{
	class GUIVertLayouter : public GUILayouter
	{
		typedef GUIVertLayouter ThisClass;
		typedef GUILayouter SuperClass;
	public:
		GUIVertLayouter(GUIWidget* pOwner);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIVertLayouter() override;
		virtual void OnDelete() override;
		virtual dl_bool OnOwnerSizeChanged(const TGUI_SIZE<int>& size) override;
		virtual dl_bool AutoAdd(GUIWindowBase* pWindow) override;
		virtual dl_bool AutoRemove(GUIWindowBase* pWindow) override;

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	protected:
	};
}
