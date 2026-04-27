#include "GUIDropDownList.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIDropDownList*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	GUIDropDownList::GUIDropDownList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(Constructor_t, 0, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUIDropDownList::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5be920, this);
	}

	GUIDropDownList::~GUIDropDownList()
	{
		CALL(Destructor_t, 0x5bfaf0, this);
	}

	void GUIDropDownList::OnDelete()
	{
		CALL(OnDelete_t, 0x5bedf0, this);
	}

	void GUIDropDownList::OnItemSelected(dl_int idx)
	{
		CALL(OnItemSelected_t, 0x5bee10, this, idx);
	}
}