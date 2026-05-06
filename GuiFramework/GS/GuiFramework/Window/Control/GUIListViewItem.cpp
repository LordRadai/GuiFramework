#include "GUIListViewItem.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor1_t)(GUIListViewItem*, TGUISharedString<dl_wchar>);
	typedef void(_fastcall* Constructor2_t)(GUIListViewItem*, GUIListView*, TGUISharedString<dl_wchar>);

	typedef void(__fastcall* OnRemoveItem_t)(GUIListViewItem*);
	typedef dl_bool(__fastcall* SetItemText_t)(GUIListViewItem*, dl_int, TGUISharedString<dl_wchar>);
	
	GUIListViewItem::GUIListViewItem(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor1_t, 0x5d2e00, this, label);
	}

	GUIListViewItem::GUIListViewItem(GUIListView* pOwner, TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor2_t, 0x5d2d50, this, pOwner, label);
	}

	DLRF::DLRuntimeClass* GUIListViewItem::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5d2d00, this);
	}

	GUIListViewItem::~GUIListViewItem()
	{
		CALL(Destructor_t, 0x5d37f0, this);
	}

	void GUIListViewItem::OnDelete()
	{
		CALL(OnDelete_t, 0x5d3340, this);
	}

	void GUIListViewItem::OnRemoveItem()
	{
		CALL(OnRemoveItem_t, 0x5d32f0, this);
	}

	dl_bool GUIListViewItem::SetItemText(dl_int idx, TGUISharedString<dl_wchar> label)
	{
		return CALL(SetItemText_t, 0x5d2ff0, this, idx, label);
	}
}