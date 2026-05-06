#pragma once
#include "GuiFramework/System/GUIObject.h"
#include "GuiFramework/System/TGUISharedString.inl"

namespace GuiFramework
{
	class GUIListView;

	class GUIListViewItem : public GUIObject
	{
		typedef GUIListViewItem ThisClass;
		typedef GUIObject SuperClass;
	public:
		GUIListViewItem() {}
		GUIListViewItem(TGUISharedString<dl_wchar> label);
		GUIListViewItem(GUIListView* pOwner, TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIListViewItem() override;
		virtual void OnDelete() override;
		virtual dl_uint GetRenderText(DLTX::DLString& out) const { return false; }

		void OnRemoveItem();
		dl_bool SetItemText(dl_int idx, TGUISharedString<dl_wchar> label);

		typedef dl_uint(__fastcall* GetRenderText_t)(const GUIListViewItem*, DLTX::DLString&);
	protected:
		GUIListView* m_pOwner;
		TGUISharedString<dl_wchar> m_label;
		dl_pointer m_pVar28;
		dl_pointer m_pVar30;
	};
}