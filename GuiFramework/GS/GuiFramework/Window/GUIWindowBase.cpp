#include "GUIWindowBase.h"

namespace GuiFramework
{
	typedef void(__fastcall* GUIWindowBase_ctor_t)(GUIWindowBase*, TGUISharedString<dl_wchar>);

	typedef dl_bool(__fastcall* SetAfterWindow_t)(GUIWindowBase*, GUIWindowBase*);

	typedef dl_bool(__fastcall* Close_t)(GUIWindowBase*);
	typedef dl_bool(__fastcall* Minimize_t)(GUIWindowBase*, dl_int);
	typedef dl_bool(__fastcall* Restore_t)(GUIWindowBase*, dl_int);

	typedef dl_bool(__fastcall* FadeIn_t)(GUIWindowBase*);

	GUIWindowBase::GUIWindowBase(TGUISharedString<dl_wchar> label)
	{
		CALL(GUIWindowBase_ctor_t, 0x54f610, this, label);
	}

	DLRF::DLRuntimeClass* GUIWindowBase::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x54f5c0, this);
	}

	GUIWindowBase::~GUIWindowBase()
	{
		CALL(Destructor_t, 0x554000, this);
	}

	void GUIWindowBase::OnDelete()
	{
		CALL(OnDelete_t, 0x551c50, this);
	}

	dl_uint GuiFramework::GUIWindowBase::OnMouseEvent(const MouseEvent& event)
	{
		return CALL(OnMouseEvent_t, 0x550f90, this, event);
	}

	dl_uint GUIWindowBase::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x551670, this, input);
	}

	dl_uint GUIWindowBase::OnNcCalcSize(Rect& out)
	{
		return CALL(OnNcCalcSize_t, 0x3c2300, this, out);
	}

	GUI_NCHIT GUIWindowBase::OnNcHitTest(const Point2D& pt)
	{
		return CALL(OnNcHitTest_t, 0x551870, this, pt);
	}

	void GUIWindowBase::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x551d60, this, gc);
	}

	void GUIWindowBase::OnNcRender(GraphicsContext& gc) const
	{
		CALL(OnNcRender_t, 0x551e40, this, gc);
	}

	void GUIWindowBase::OnRenderWindow(GraphicsContext& gc) const
	{
		CALL(OnRenderWindow_t, 0x5520c0, this, gc);
	}

	dl_bool GUIWindowBase::SetAfterWindow(GUIWindowBase* pAfter)
	{
		return CALL(SetAfterWindow_t, 0x550c20, this, pAfter);
	}

	dl_bool GUIWindowBase::Close()
	{
		return CALL(Close_t, 0x54fa10, this);
	}

	dl_bool GUIWindowBase::Minimize(dl_int smooth)
	{
		return CALL(Minimize_t, 0x57b580, this, smooth);
	}

	dl_bool GUIWindowBase::Restore(dl_int smooth)
	{
		return CALL(Restore_t, 0x57b7c0, this, smooth);
	}

	dl_bool GUIWindowBase::FadeIn()
	{
		return CALL(FadeIn_t, 0x57b1d0, this);
	}
}
