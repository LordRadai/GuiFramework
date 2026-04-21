#include "GUITweakerDialog.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* GUITweakerDialogCtorWithLabel_t)(GUITweakerDialog*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* GUITweakerDialogCtorWithParentAndLabelAndCreate_t)(GUITweakerDialog*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(__fastcall* GUITweakerDialogCtorWithParentAndLabelAndFlags_t)(GUITweakerDialog*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint);

	typedef GUITweakerGroup*(__fastcall* BeginGroup_t)(GUITweakerDialog*, TGUISharedString<dl_wchar>, dl_uint);
	typedef void(__fastcall* EndGroup_t)(GUITweakerDialog*);

	typedef GUITweakerGroup*(__fastcall* GetCurrentGroup_t)(GUITweakerDialog*);

	typedef GUIYawPitchTweaker*(__fastcall* CreateYawPitchTweaker_t)(GUITweakerDialog*, TGUISharedString<dl_wchar>, DLMT::DL_VECTOR2&, dl_uint);

	typedef GUIColorTweaker* (__fastcall* CreateColorTweakerWithVector4_t)(GUITweakerDialog*, TGUISharedString<dl_wchar>, DLMT::DL_VECTOR4&, dl_uint);
	typedef GUIColorTweaker* (__fastcall* CreateColorTweakerWithColor32_t)(GUITweakerDialog*, TGUISharedString<dl_wchar>, DLMT::DL_COLOR_32&, dl_uint);

	GUITweakerDialog::GUITweakerDialog(TGUISharedString<dl_wchar> label)
	{
		CALL(GUITweakerDialogCtorWithLabel_t, 0x5388e0, this, label);
	}

	GUITweakerDialog::GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createData)
	{
		CALL(GUITweakerDialogCtorWithParentAndLabelAndCreate_t, 0x538980, this, pParent, label, createData);
	}

	GUITweakerDialog::GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags)
	{
		CALL(GUITweakerDialogCtorWithParentAndLabelAndFlags_t, 0x538a30, this, pParent, label, flags);
	}

	DLRF::DLRuntimeClass* GUITweakerDialog::GetRuntimeClassOfThis() const
	{
		CALL(GetRuntimeClass_t, 0x538b00, this);
	}

	GUITweakerDialog::~GUITweakerDialog()
	{
		CALL(Destructor_t, 0x538b10, this);
	}

	void GUITweakerDialog::OnDelete()
	{
		CALL(OnDelete_t, 0x538b20, this);
	}

	dl_bool GUITweakerDialog::OnMouseWheel(const MouseEvent& event)
	{
		CALL(OnMouseWheel_t, 0x539840, this, event);
	}

	dl_bool GUITweakerDialog::OnUpdate(dl_float32 fDeltaTime)
	{
		CALL(OnUpdate_t, 0x5396d0, this, fDeltaTime);
	}

	dl_bool GUITweakerDialog::OnCreate()
	{
		CALL(OnCreate_t, 0x539870, this);
	}

	dl_bool GUITweakerDialog::OnClose()
	{
		CALL(OnClose_t, 0x539d80, this);
	}

	GUITweakerGroup* GUITweakerDialog::BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags)
	{
		CALL(BeginGroup_t, 0x538c40, this, label, flags);
	}

	void GUITweakerDialog::EndGroup()
	{
		CALL(EndGroup_t, 0x538d60, this);
	}

	GUITweakerGroup* GUITweakerDialog::GetCurrentGroup()
	{
		CALL(GetCurrentGroup_t, 0x539650, this);
	}

	GUIYawPitchTweaker* GUITweakerDialog::CreateYawPitchTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR2& value, dl_uint flags)
	{
		CALL(CreateYawPitchTweaker_t, 0x539300, this, label, value, flags);
	}

	GUIColorTweaker* GUITweakerDialog::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4& value, dl_uint flags)
	{
		CALL(CreateColorTweakerWithVector4_t, 0x539200, this, label, value, flags);
	}

	GUIColorTweaker* GUITweakerDialog::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32& value, dl_uint flags)
	{
		CALL(CreateColorTweakerWithColor32_t, 0x538e00, this, label, value, flags);
	}
}
