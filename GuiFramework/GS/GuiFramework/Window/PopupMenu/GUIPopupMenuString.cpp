#include "GUIPopupMenuString.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIPopupMenuString*, GUISystem*, TGUISharedString<dl_wchar>, dl_uint);

	GUIPopupMenuString::GUIPopupMenuString(GUISystem* pSystem, TGUISharedString<dl_wchar> str, dl_uint id)
	{
		CALL(Constructor_t, 0x557f70, this, pSystem, str, id);
	}

	DLRF::DLRuntimeClass* GUIPopupMenuString::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x557f20, this);
	}

	GUIPopupMenuString::~GUIPopupMenuString()
	{
		CALL(Destructor_t, 0x5582d0, this);
	}

	void GUIPopupMenuString::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x558030, this, gc);
	}

	dl_uint GUIPopupMenuString::OnLButtonDown(const MouseEvent& event, const Rect& rect)
	{
		return CALL(OnLButtonDown_t, 0x558100, this, event, rect);
	}
}