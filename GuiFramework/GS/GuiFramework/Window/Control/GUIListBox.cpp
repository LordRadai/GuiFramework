#include "GUIListBox.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIListBox*, TGUISharedString<dl_wchar>);
	typedef void(_fastcall* Constructor_Create_t)(GUIListBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(_fastcall* Constructor_Full_t)(GUIListBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	typedef void(_fastcall* SetCurSel_t)(GUIListBox*, dl_int, dl_int);
	typedef void(_fastcall* CenteringItem_t)(GUIListBox*, dl_int);
	typedef GUIListBoxItem*(_fastcall* AddItem_t)(GUIListBox*, TGUISharedString<dl_wchar>, dl_int, dl_float32);

	GUIListBox::GUIListBox(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5b9e60, this, label);
	}

	GUIListBox::GUIListBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createWindow)
	{
		CALL(Constructor_Create_t, 0x5b9ef0, this, pParent, label, createWindow);
	}

	GUIListBox::GUIListBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(Constructor_Full_t, 0x5b9f90, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUIListBox::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5b9e10, this);
	}

	GUIListBox::~GUIListBox()
	{
		CALL(Destructor_t, 0x5bcf10, this);
	}

	void GUIListBox::OnDelete()
	{
		CALL(OnDelete_t, 0x5bb630, this);
	}

	dl_uint GUIListBox::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5bb540, this, event);
	}

	dl_uint GUIListBox::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x5bb440, this, event);
	}

	dl_uint GUIListBox::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x5bb4a0, this, event);
	}

	dl_uint GUIListBox::OnMouseLeave()
	{
		return CALL(OnMouseLeave_t, 0x5bb590, this);
	}

	dl_uint GUIListBox::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x5bac50, this, input);
	}

	dl_uint GUIListBox::OnSize()
	{
		return CALL(OnSize_t, 0x5bb5d0, this);
	}

	dl_uint GUIListBox::OnCreate()
	{
		return CALL(OnCreate_t, 0x5bad50, this);
	}

	dl_uint GUIListBox::OnPreCreate(const _GUI_CREATE_WINDOW& createParams)
	{
		return CALL(OnPreCreate_t, 0x5badc0, this, createParams);
	}

	void GUIListBox::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5bae00, this, gc);
	}

	dl_uint GUIListBox::OnVScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos)
	{
		return CALL(OnVScroll_t, 0x5bb600, this, event, pos);
	}

	void GUIListBox::SetCurSel(dl_int idx, dl_int param_2)
	{
		CALL(SetCurSel_t, 0x5ba9e0, this, idx, param_2);
	}

	void GUIListBox::CenteringItem(dl_int idx)
	{
		CALL(CenteringItem_t, 0x5baad0, this, idx);
	}

	GUIListBoxItem* GUIListBox::AddItem(TGUISharedString<dl_wchar> label, dl_int param_2, dl_float32 param_3)
	{
		return CALL(AddItem_t, 0x5ba220, this, label, param_2, param_3);
	}
}