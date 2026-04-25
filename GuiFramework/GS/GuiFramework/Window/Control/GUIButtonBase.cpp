#include "GUIButtonBase.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(const GUIButtonBase*, TGUISharedString<dl_wchar>);

	GUIButtonBase::GUIButtonBase(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x596ac0, this, label);
	}

	DLRF::DLRuntimeClass* GUIButtonBase::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x596a70, this);
	}

	GUIButtonBase::~GUIButtonBase()
	{
		CALL(Destructor_t, 0x5971a0, this);
	}

	void GUIButtonBase::OnDelete()
	{
		CALL(OnDelete_t, 0x596c70, this);
	}

	dl_uint GuiFramework::GUIButtonBase::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x596c90, this, event);
	}

	dl_uint GuiFramework::GUIButtonBase::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x596db0, this, event);
	}

	dl_uint GuiFramework::GUIButtonBase::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x596e20, this, event);
	}

	dl_uint GUIButtonBase::OnMouseLeave()
	{
		return CALL(OnMouseLeave_t, 0x596f30, this);
	}
}
