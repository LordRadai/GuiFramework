#include "GUIButton.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(const GUIButton*, GUITriggerTweakWidget*, TGUISharedString<dl_wchar>, dl_uint);

	GUIButton::GUIButton(GUITriggerTweakWidget* pTriggerTweakWidget, TGUISharedString<dl_wchar> label, dl_uint flags)
	{
		CALL(Constructor_t, 0x5b8570, this, pTriggerTweakWidget, label, flags);
	}

	DLRF::DLRuntimeClass* GUIButton::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5b8420, this);
	}

	GUIButton::~GUIButton()
	{
		CALL(Destructor_t, 0x5b9950, this);
	}

	dl_uint GUIButton::OnCreate()
	{
		return CALL(OnCreate_t, 0x5b8b50, this);
	}

	void GUIButton::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5b8940, this, gc);
	}
}
