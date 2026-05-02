#pragma once
#include "GuiFramework/System/TGUIValueStringPair.inl"
#include "GuiFramework/Window/GUIWidget.h"
#include "GUIDropDownList.h"
#include "GUIEditBox.h"

namespace GuiFramework
{
	class GUIComboBox : public GUIWidget
	{
	public:
		struct _ComboItem
		{
			dl_size Value;
			TGUISharedString<dl_wchar> Text;
		};

		GUIComboBox() {}
		GUIComboBox(TGUISharedString<dl_wchar> label);
		GUIComboBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, _GUI_CREATE_WINDOW& createParams);
		GUIComboBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIComboBox() override;
		virtual void OnDelete() override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
	private:
		DLUT::DLVector<_ComboItem> m_items;
		Rect16 m_itemRect;
		GUIDropDownList* m_pDropDownList;
		GUIEditBox* m_pEditBox;
		dl_int m_selectedIndex;
	};
}