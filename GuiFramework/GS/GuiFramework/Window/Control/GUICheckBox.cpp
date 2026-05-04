#include "GUICheckBox.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUICheckBox*, TGUISharedString<dl_wchar>);
	typedef void(_fastcall* ConstructorWithCreateParams_t)(GUICheckBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(_fastcall* ConstructorWithFlags_t)(GUICheckBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	GUICheckBox::GUICheckBox(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5a3670, this, label);
	}

	GUICheckBox::GUICheckBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams)
	{
		CALL(ConstructorWithCreateParams_t, 0x5a36e0, this, pParent, label, createParams);
	}

	GUICheckBox::GUICheckBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorWithFlags_t, 0x5a3770, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUICheckBox::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5a3620, this);
	}

	GUICheckBox::~GUICheckBox()
	{
		CALL(Destructor_t, 0x5a4180, this);
	}

	void GUICheckBox::OnDelete()
	{
		CALL(OnDelete_t, 0x5a3fd0, this);
	}

	dl_uint GUICheckBox::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x5a3b70, this, input);
	}

	dl_uint GUICheckBox::OnCreate()
	{
		return CALL(OnCreate_t, 0x5a3fa0, this);
	}

	void GUICheckBox::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5a3c70, this, gc);
	}

	void GUICheckBox::OnButtonPressed()
	{
		CALL(OnButtonPressed_t, 0x5a3c20, this);
	}
}