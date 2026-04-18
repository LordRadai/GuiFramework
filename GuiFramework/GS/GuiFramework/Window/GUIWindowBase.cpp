#include "GUIWindowBase.h"

namespace GuiFramework
{
	typedef void(__fastcall* GUIWindowBase_ctor_t)(GUIWindowBase*, TGUISharedString<dl_wchar>);

	typedef DLRF::DLRuntimeClass* (__fastcall* GetRuntimeClass_t)(const GUIWindowBase*);
	typedef void(__fastcall* Destructor_t)(GUIWindowBase*);
	typedef void(__fastcall* OnDelete_t)(GUIWindowBase*);
	typedef dl_bool(__fastcall* OnMouseEvent_t)(GUIWindowBase*, const MouseEvent&);
	typedef dl_bool(__fastcall* OnVirtualInput_t)(GUIWindowBase*, const GUIWindowBase::VirtualInput&);
	typedef dl_bool(__fastcall* OnNcCalcSize_t)(GUIWindowBase*, Rect&);
	typedef dl_int(__fastcall* OnNcHitTest_t)(GUIWindowBase*, const Point2D&);
	typedef void(__fastcall* OnRender_t)(const GUIWindowBase*, GraphicsContext&);
	typedef void(__fastcall* OnNcRender_t)(const GUIWindowBase*, GraphicsContext&);
	typedef void(__fastcall* OnRenderWindow_t)(const GUIWindowBase*, GraphicsContext&);

	GUIWindowBase::GUIWindowBase(TGUISharedString<dl_wchar> label)
	{
		CALL(GUIWindowBase_ctor_t, 0x54f610, this, label);
	}

	DLRF::DLRuntimeClass* GUIWindowBase::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClass_t, 0x54f5c0, this);
	}

	GUIWindowBase::~GUIWindowBase()
	{
		CALL(Destructor_t, 0x554000, this);
	}

	void GUIWindowBase::OnDelete()
	{
		CALL(OnDelete_t, 0x551c50, this);
	}

	dl_bool GUIWindowBase::OnMouseEvent(const MouseEvent& event)
	{
		return CALL(OnMouseEvent_t, 0x550f90, this, event);
	}

	dl_bool GUIWindowBase::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x551670, this, input);
	}

	dl_bool GUIWindowBase::OnNcCalcSize(Rect& out)
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
}
