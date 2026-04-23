#include "GUIAutoVLayout.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIAutoVLayout*, TGUISharedString<dl_wchar>&);

	GUIAutoVLayout::GUIAutoVLayout(TGUISharedString<dl_wchar>& label)
	{
		CALL(Constructor_t, 0x5a4690, this, label);
	}

	DLRF::DLRuntimeClass* GUIAutoVLayout::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5a4640, this);
	}

	GUIAutoVLayout::~GUIAutoVLayout()
	{
		CALL(Destructor_t, 0x5a5500, this);
	}

	void GUIAutoVLayout::OnDelete()
	{
		CALL(OnDelete_t, 0x5a4a00, this);
	}

	dl_bool GUIAutoVLayout::OnSize()
	{
		CALL(OnSize_t, 0x5a4a40, this);
	}

	dl_bool GUIAutoVLayout::OnRestored()
	{
		CALL(OnRestored_t, 0x5a4ac0, this);
	}

	dl_bool GUIAutoVLayout::OnCreate()
	{
		return CALL(OnCreate_t, 0x5a4870, this);
	}

	dl_bool GUIAutoVLayout::OnClose()
	{
		return CALL(OnClose_t, 0x5a49c0, this);
	}

	Rect GUIAutoVLayout::GetDefaultSizeMax() const
	{
		return CALL(GetDefaultSizeMax_t, 0x5a4840, this);
	}
}
