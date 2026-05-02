#include "GUIComboBox.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* GUIComboBox_Ctor_t)(GUIComboBox*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* GUIComboBox_Ctor_2_t)(GUIComboBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, _GUI_CREATE_WINDOW&);
	typedef void(__fastcall* GUIComboBox_Ctor_3_t)(GUIComboBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	GUIComboBox::GUIComboBox(TGUISharedString<dl_wchar> label)
	{
		CALL(GUIComboBox_Ctor_t, 0x59d7c0, this, label);
	}

	GUIComboBox::GUIComboBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, _GUI_CREATE_WINDOW& createParams)
	{
		CALL(GUIComboBox_Ctor_2_t, 0x59d880, this, pParent, label, createParams);
	}

	GUIComboBox::GUIComboBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(GUIComboBox_Ctor_3_t, 0x59d960, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUIComboBox::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x59d770, this);
	}

	GUIComboBox::~GUIComboBox()
	{
		CALL(Destructor_t, 0x5a0b10, this);
	}

	void GUIComboBox::OnDelete()
	{
		CALL(OnDelete_t, 0x59e900, this);
	}

	dl_uint GUIComboBox::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x59ea00, this, event);
	}

	dl_uint GUIComboBox::OnCreate()
	{
		return CALL(OnCreate_t, 0x59e7b0, this);
	}

	void GUIComboBox::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x59eed0, this, gc);
	}
}