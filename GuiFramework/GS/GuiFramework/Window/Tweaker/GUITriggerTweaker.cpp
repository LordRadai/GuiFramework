#include "GUITriggerTweaker.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(const GUITriggerTweaker*, GUIWidget*, TGUISharedString<dl_wchar>);

	typedef void(_fastcall* AddButton_t)(GUITriggerTweaker*, TGUISharedString<dl_wchar>, GUICallbackObjectBase*);

	GUITriggerTweaker::GUITriggerTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x53d010, this, pParent, label);
	}

	DLRF::DLRuntimeClass* GUITriggerTweaker::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x53cfc0, this);
	}

	GUITriggerTweaker::~GUITriggerTweaker()
	{
		CALL(Destructor_t, 0x53e160, this);
	}

	void GUITriggerTweaker::OnDelete()
	{
		CALL(OnDelete_t, 0x53d4d0, this);
	}

	void GUITriggerTweaker::Close()
	{
		CALL(Close_t, 0x53d570, this);
	}

	void GUITriggerTweaker::AddButton(TGUISharedString<dl_wchar> label, GUICallbackObjectBase* pCallback)
	{
		CALL(AddButton_t, 0x53d260, this, label, pCallback);
	}
}