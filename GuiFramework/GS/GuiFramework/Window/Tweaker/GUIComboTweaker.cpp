#include "GUIComboTweaker.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIComboTweaker*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint);

	typedef void(__fastcall* SetComboCurSel_t)(GUIComboTweaker*, dl_int);

	GUIComboTweaker::GUIComboTweaker(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags) : SuperClass()
	{
		CALL(Constructor_t, 0x59c3e0, this, pParent, label, flags);
	}

	DLRF::DLRuntimeClass* GUIComboTweaker::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x547b90, this);
	}

	GUIComboTweaker::~GUIComboTweaker()
	{
		CALL(Destructor_t, 0x5488d0, this);
	}

	void GUIComboTweaker::OnDelete()
	{
		CALL(OnDelete_t, 0x547f60, this);
	}

	void GUIComboTweaker::Close()
	{
		CALL(Close_t, 0x547fb0, this);
	}

	void GUIComboTweaker::_Destroy()
	{
		CALL(_Destroy_t, 0x547ec0, this);
	}

	void GUIComboTweaker::SetComboCurSel(dl_int index)
	{
		CALL(SetComboCurSel_t, 0x548000, this, index);
	}
}