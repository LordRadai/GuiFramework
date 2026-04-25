#include "GUITweakerGroup.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(const GUITweakerGroup*, TGUISharedString<dl_wchar>);

	GUITweakerGroup::GUITweakerGroup(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x54b390, this, label);
	}

	DLRF::DLRuntimeClass* GUITweakerGroup::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x54b340, this);
	}

	GUITweakerGroup::~GUITweakerGroup()
	{
		CALL(Destructor_t, 0x54e1d0, this);
	}

	void GUITweakerGroup::OnDelete()
	{
		CALL(OnDelete_t, 0x54d190, this);
	}

	dl_uint GUITweakerGroup::OnRestored()
	{
		return CALL(OnRestored_t, 0x54d310, this);
	}

	dl_uint GUITweakerGroup::OnClose()
	{
		return CALL(OnClose_t, 0x54d080, this);
	}
}
