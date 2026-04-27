#include "GUIListBoxItem.h"
#include "GUIListBox.h"

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIListBoxItem*, TGUISharedString<dl_wchar>, dl_float32);

	GUIListBoxItem::GUIListBoxItem()
	{
	}

	GUIListBoxItem::GUIListBoxItem(TGUISharedString<dl_wchar> label, dl_float32 param_2)
	{
		CALL(Constructor_t, 0x5e1bc0, this, label, param_2);
	}

	DLRF::DLRuntimeClass* GUIListBoxItem::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5e1b70, this);
	}

	GUIListBoxItem::~GUIListBoxItem()
	{
		CALL(Destructor_t, 0x5e2320, this);
	}

	void GUIListBoxItem::OnDelete()
	{
		CALL(OnDelete_t, 0x5e2120, this);
	}

	Rect GUIListBoxItem::GetSize() const
	{
		return CALL(GetSize_t, 0x5e1e50, this);
	}
}