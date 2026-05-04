#include "GUIListView.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIListView*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* ConstructorWithCreateParams_t)(GUIListView*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(__fastcall* ConstructorWithFlags_t)(GUIListView*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	GUIListView::GUIListView(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5ca3b0, this, label);
	}

	GUIListView::GUIListView(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createWindow)
	{
		CALL(ConstructorWithCreateParams_t, 0x5ca450, this, pParent, label, createWindow);
	}

	GUIListView::GUIListView(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorWithFlags_t, 0x5ca510, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUIListView::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5ca360, this);
	}

	GUIListView::~GUIListView()
	{
		CALL(Destructor_t, 0x5d12b0, this);
	}

	void GUIListView::OnDelete()
	{
		CALL(OnDelete_t, 0x5cd450, this);
	}

	dl_uint GUIListView::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5ccf90, this, event);
	}

	dl_uint GUIListView::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x5ccb10, this, event);
	}

	dl_uint GUIListView::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x5ccf10, this, event);
	}

	dl_uint GUIListView::OnRButtonDown(const MouseEvent& event)
	{
		return CALL(OnRButtonDown_t, 0x5cccb0, this, event);
	}

	dl_uint GUIListView::OnLButtonDblClk(const MouseEvent& event)
	{
		return CALL(OnLButtonDblClk_t, 0x5ccd60, this, event);
	}

	dl_uint GUIListView::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x5cd140, this, event);
	}

	dl_uint GUIListView::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x5cbfe0, this, input);
	}

	dl_uint GUIListView::OnKeyDown(const KeyEvent& input)
	{
		return CALL(OnKeyDown_t, 0x5cd240, this, input);
	}

	dl_uint GUIListView::OnSize()
	{
		return CALL(OnSize_t, 0x5ccae0, this);
	}

	dl_uint GUIListView::OnCreate()
	{
		return CALL(OnCreate_t, 0x5cc930, this);
	}

	dl_uint GUIListView::OnClose()
	{
		return CALL(OnClose_t, 0x5cd570, this);
	}

	void GUIListView::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5cc3f0, this, gc);
	}
}