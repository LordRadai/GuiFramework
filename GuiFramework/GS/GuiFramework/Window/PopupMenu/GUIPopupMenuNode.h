#pragma once
#include "GUIPopupMenuItem.h"
#include "GUIPopupMenuSeparator.h"
#include "GUIPopupMenuString.h"

namespace GuiFramework
{
	class GUIPopupMenuNode : public GUIPopupMenuItem
	{
		typedef GUIPopupMenuNode ThisClass;
		typedef GUIPopupMenuItem SuperClass;
	public:
		enum StatusFlags : dl_uint
		{
		};

		GUIPopupMenuNode() {}
		GUIPopupMenuNode(GUISystem* pSystem, TGUISharedString<wchar_t> label, dl_uint id);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIPopupMenuNode() override;
		virtual dl_uint IsNode() const override { return true; }
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event, const Rect& rect) override;

		GUIPopupMenuItem* AddItem(GUIPopupMenuItem* item, dl_uint idx = -1);
		GUIPopupMenuString* AddString(TGUISharedString<dl_wchar> str, dl_uint id, dl_uint idx = -1);
		GUIPopupMenuSeparator* AddSeparator(dl_uint id, dl_uint idx = -1);
		GUIPopupMenuNode* AddSubNode(TGUISharedString<dl_wchar> label, dl_uint id, dl_uint idx = -1);
	protected:
		DLUT::DLVector<TGUIObjectPtr<GUIPopupMenuItem>> m_items;
		TGUISharedString<wchar_t> m_label;
		dl_bool m_bDisallowChildren;
		dl_uint m_flags;
	};
}
