#include "GUIOnOffTweaker.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIOnOffTweaker*, GUIWidget*, TGUISharedString<dl_wchar>);

	typedef void(__fastcall* SetCheckBoxToggle_t)(GUIOnOffTweaker*, dl_bool);
	typedef dl_bool(__fastcall* IsCheckBoxToggled_t)(const GUIOnOffTweaker*);

	GUIOnOffTweaker::GUIOnOffTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x54a880, this, pParent, label);
	}

	DLRF::DLRuntimeClass* GUIOnOffTweaker::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x54a830, this);
	}

	GUIOnOffTweaker::~GUIOnOffTweaker()
	{
		CALL(Destructor_t, 0x54ad90, this);
	}

	void GUIOnOffTweaker::OnDelete()
	{
		CALL(OnDelete_t, 0x54aa60, this);
	}

	void GUIOnOffTweaker::Close()
	{
		CALL(Close_t, 0x54aa00, this);
	}

	void GUIOnOffTweaker::SetCheckBoxToggle(dl_bool bToggled)
	{
		CALL(SetCheckBoxToggle_t, 0x54ab00, this, bToggled);
	}

	dl_bool GUIOnOffTweaker::IsCheckBoxToggled() const
	{
		return CALL(IsCheckBoxToggled_t, 0x54aa90, this);
	}
}