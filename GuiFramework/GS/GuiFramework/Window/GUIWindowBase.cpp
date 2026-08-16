#include "GUIWindowBase.h"

namespace GuiFramework
{
	typedef void(_fastcall* GUIWindowBase_ctor_t)(GUIWindowBase*, TGUISharedString<dl_wchar>);

	typedef dl_bool(_fastcall* SetAfterWindow_t)(GUIWindowBase*, GUIWindowBase*);
	typedef void(_fastcall* SetForeground_t)(GUIWindowBase*);
	typedef GUIWindowBase* (_fastcall* Create_t)(GUIWindowBase*, GUIWindowBase*, const _GUI_CREATE_WINDOW&);

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

	void GUIWindowBase::SetForeground()
	{
		CALL(SetForeground_t, 0x550b20, this);
	}

	GUIWindowBase* GUIWindowBase::Create(GUIWindowBase* pRoot, const _GUI_CREATE_WINDOW& createParams)
	{
		return CALL(Create_t, 0x54f930, this, pRoot, createParams);
	}
}
