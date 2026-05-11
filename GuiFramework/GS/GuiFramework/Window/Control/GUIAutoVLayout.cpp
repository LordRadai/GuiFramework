#include "GUIAutoVLayout.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIAutoVLayout*, TGUISharedString<dl_wchar>&);

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

	dl_uint GUIAutoVLayout::OnSize()
	{
		return CALL(OnSize_t, 0x5a4a40, this);
	}

	dl_uint GUIAutoVLayout::OnRestored()
	{
		return CALL(OnRestored_t, 0x5a4ac0, this);
	}

	dl_uint GUIAutoVLayout::OnCreate()
	{
		return CALL(OnCreate_t, 0x5a4870, this);
	}

	dl_uint GUIAutoVLayout::OnClose()
	{
		return CALL(OnClose_t, 0x5a49c0, this);
	}

	Rect GUIAutoVLayout::GetDefaultSizeMax() const
	{
		return CALL(GetDefaultSizeMax_t, 0x5a4840, this);
	}
}
