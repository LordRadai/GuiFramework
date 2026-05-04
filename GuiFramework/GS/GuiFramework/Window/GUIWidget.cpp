#include "GUIWidget.h"

namespace GuiFramework
{
	typedef void(__fastcall* ctor_t)(GUIWidget*, TGUISharedString<dl_wchar>);

	typedef void(__fastcall* Close_t)(GUIWidget*);
	typedef dl_bool(__fastcall* FadeIn_t)(GUIWidget*);

	GUIWidget::GUIWidget(TGUISharedString<dl_wchar> label) : GUIWindowBase(label)
	{
		CALL(ctor_t, 0x57a910, this, label);
	}

	DLRF::DLRuntimeClass* GUIWidget::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x57a8c0, this);
	}

	GUIWidget::~GUIWidget()
	{
		CALL(Destructor_t, 0x582120, this);
	}

	void GUIWidget::OnDelete()
	{
		CALL(OnDelete_t, 0x57abe0, this);
	}

	dl_bool GUIWidget::AddChild(GUIWindowBase* pChild)
	{
		return CALL(AddChild_t, 0x57ae10, this, pChild);
	}

	DLUT::DLVector<GUIObject*>* GUIWidget::GetChildrenVector()
	{
		return CALL(GetChildrenVector_t, 0x537a50, this);
	}

	Rect GUIWidget::GetChildrenBaseCoord() const
	{
		return CALL(GetChildrenBaseCoord_t, 0x537a00, this);
	}

	GUIWindowBase* GUIWidget::GetNextFocusWindow() const
	{
		return CALL(GetNextFocusWindow_t, 0x57ba90, this);
	}

	dl_uint GuiFramework::GUIWidget::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x57fad0, this, event);
	}

	dl_uint GuiFramework::GUIWidget::OnNcMouseMove(GUI_NCHIT ncHit, const MouseEvent& event)
	{
		return CALL(OnNcMouseMove_t, 0x57e570, this, ncHit, event);
	}

	dl_uint GUIWidget::OnNcLButtonDown(GUI_NCHIT ncHit, const MouseEvent& event)
	{
		return CALL(OnNcLButtonDown_t, 0x57edd0, this, ncHit, event);
	}

	dl_uint GUIWidget::OnNcLButtonUp(GUI_NCHIT ncHit, const MouseEvent& event)
	{
		return CALL(OnNcLButtonUp_t, 0x57f700, this, ncHit, event);
	}

	dl_uint GUIWidget::OnMouseLeave()
	{
		return CALL(OnMouseLeave_t, 0x57fb00, this);
	}

	dl_uint GUIWidget::OnNcMouseLeave()
	{
		return CALL(OnNcMouseLeave_t, 0x57fb30, this);
	}

	dl_uint GUIWidget::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x57fcf0, this, input);
	}

	dl_uint GUIWidget::OnNcCalcSize(Rect& out)
	{
		return CALL(OnNcCalcSize_t, 0x57cd90, this, out);
	}

	GUI_NCHIT GUIWidget::OnNcHitTest(const Point2D& pt)
	{
		return CALL(OnNcHitTest_t, 0x537df0, this, pt);
	}

	dl_uint GUIWidget::OnCreate()
	{
		return CALL(OnCreate_t, 0x57cb70, this);
	}

	dl_uint GUIWidget::OnPreCreate(const _GUI_CREATE_WINDOW& createParams)
	{
		return CALL(OnPreCreate_t, 0x57cc40, this, createParams);
	}

	dl_uint GUIWidget::OnClose()
	{
		return CALL(OnClose_t, 0x57e460, this);
	}

	void GUIWidget::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x57bec0, this, gc);
	}

	void GUIWidget::OnNcRender(GraphicsContext& gc) const
	{
		CALL(OnNcRender_t, 0x57bf50, this, gc);
	}

	Rect GUIWidget::GetDefaultSizeMin() const
	{
		return CALL(GetDefaultSizeMin_t, 0x57bcd0, this);
	}

	Rect GUIWidget::GetDefaultSizeMax() const
	{
		return CALL(GetDefaultSizeMax_t, 0x57bd50, this);
	}

	void GUIWidget::ComputeNcShapeInfo(const _GUI_NC_SHAPE_PROP& prop, _GUI_NC_SHAPE_INFO& info) const
	{
		CALL(ComputeNcShapeInfo_t, 0x57cec0, this, prop, info);
	}

	void GUIWidget::Close()
	{
		CALL(Close_t, 0x54fa10, this);
	}

	dl_bool GUIWidget::FadeIn()
	{
		return CALL(FadeIn_t, 0x57b1d0, this);
	}
}