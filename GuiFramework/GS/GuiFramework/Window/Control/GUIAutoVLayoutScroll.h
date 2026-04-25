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
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnNcMouseWheel(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_uint AdjustScrollByChildFocus(GUIWindowBase* pChild) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnVScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos) override;
		virtual dl_uint OnHScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos) override;

	protected:
		TGUIObjectPtr<GUIAutoVLayout> m_pAutoVLayout;
		Rect16 m_unk118;
		dl_uint16 m_sVar120;
		dl_uint16 m_sVar122;
	};
}