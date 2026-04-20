#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GUIAutoVLayout.h"

namespace GuiFramework
{
	class GUIAutoVLayoutScroll : public GUIWidget
	{
		typedef GUIAutoVLayoutScroll ThisClass;
		typedef GUIWidget SuperClass;

	public:
		GUIAutoVLayoutScroll() {}
		GUIAutoVLayoutScroll(TGUISharedString<dl_wchar>& label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIAutoVLayoutScroll() override;
		virtual void OnDelete() override;
		virtual dl_bool OnMouseWheel(const MouseEvent& event) override;
		virtual dl_bool OnNcMouseWheel(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_bool AdjustScrollByChildFocus(GUIWindowBase* pChild) override;
		virtual dl_bool OnSize() override;
		virtual dl_bool OnCreate() override;
		virtual dl_bool OnVScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos) override;
		virtual dl_bool OnHScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos) override;

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}
		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}

	protected:
		TGUIObjectPtr<GUIAutoVLayout> m_pAutoVLayout;
		Rect16 m_unk118;
		dl_uint16 m_sVar120;
		dl_uint16 m_sVar122;
	};
}