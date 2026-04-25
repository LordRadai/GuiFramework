#pragma once
#include "GUIPopupMenuItem.h"

namespace GuiFramework
{
	class GUIPopupMenuString : public GUIPopupMenuItem
	{
	public:
		GUIPopupMenuString() {}
		GUIPopupMenuString(GUISystem* pSystem, TGUISharedString<dl_wchar> str, dl_uint id);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIPopupMenuString() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event, const Rect& rect) override;
	protected:
		TGUISharedString<dl_wchar> m_label;
	};
}
