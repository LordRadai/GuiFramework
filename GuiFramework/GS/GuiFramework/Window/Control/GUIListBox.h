#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GUIListBoxItem.h"

namespace GuiFramework
{
	class GUIListBox : public GUIWidget
	{
		typedef GUIListBox ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUIListBox() {}
		GUIListBox(TGUISharedString<dl_wchar> label);
		GUIListBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createWindow);
		GUIListBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIListBox() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnMouseLeave() override;
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnPreCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual dl_uint OnVScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos) override;
		virtual void OnItemSelected() {}

	protected:
		DLUT::DLVector<TGUIObjectPtr<GUIListBoxItem>> m_items;
		dl_int m_iVar130;
		dl_int m_firstVisibleItem;
		dl_int m_selectedItem;
		dl_int m_hoveredItem;
		dl_int m_iVar140;
		dl_int m_iVar144;
		dl_uint16 m_itemHeight;
		dl_uint16 m_itemPadding;
	};
}
