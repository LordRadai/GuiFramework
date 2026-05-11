#include "GUIAutoVLayoutScroll.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIAutoVLayoutScroll*, TGUISharedString<dl_wchar>&);

	GUIAutoVLayoutScroll::GUIAutoVLayoutScroll(TGUISharedString<dl_wchar>& label)
	{
		CALL(Constructor_t, 0x591580, this, label);
	}

	DLRF::DLRuntimeClass* GUIAutoVLayoutScroll::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x591530, this);
	}

	GUIAutoVLayoutScroll::~GUIAutoVLayoutScroll()
	{
		CALL(Destructor_t, 0x592b40, this);
	}

	void GUIAutoVLayoutScroll::OnDelete()
	{
		CALL(OnDelete_t, 0x591cf0, this);
	}

	dl_uint GUIAutoVLayoutScroll::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x591d30, this, event);
	}

	dl_uint GUIAutoVLayoutScroll::OnNcMouseWheel(GUI_NCHIT ncHit, const MouseEvent& event)
	{
		return CALL(OnNcMouseWheel_t, 0x591d70, this, ncHit, event);
	}

	dl_uint GUIAutoVLayoutScroll::AdjustScrollByChildFocus(GUIWindowBase* pChild)
	{
		return CALL(AdjustScrollByChildFocus_t, 0x591f00, this, pChild);
	}

	dl_uint GUIAutoVLayoutScroll::OnSize()
	{
		return CALL(OnSize_t, 0x591910, this);
	}

	dl_uint GUIAutoVLayoutScroll::OnCreate()
	{
		return CALL(OnCreate_t, 0x591a10, this);
	}

	dl_uint GUIAutoVLayoutScroll::OnVScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos)
	{
		return CALL(OnVScroll_t, 0x591dc0, this, event, pos);
	}

	dl_uint GUIAutoVLayoutScroll::OnHScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos)
	{
		return CALL(OnHScroll_t, 0x591df0, this, event, pos);
	}
}
