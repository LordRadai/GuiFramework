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
		return CALL(GetRuntimeClassOfThis_t, 0x538b00, this);
	}

	GUITweakerDialog::~GUITweakerDialog()
	{
		CALL(Destructor_t, 0x538b10, this);
	}

	void GUITweakerDialog::OnDelete()
	{
		CALL(OnDelete_t, 0x538b20, this);
	}

	dl_uint GUITweakerDialog::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x539840, this, event);
	}

	dl_uint GUITweakerDialog::OnUpdate(dl_float32 fDeltaTime)
	{
		return CALL(OnUpdate_t, 0x5396d0, this, fDeltaTime);
	}

	dl_uint GUITweakerDialog::OnCreate()
	{
		return CALL(OnCreate_t, 0x539870, this);
	}

	dl_uint GUITweakerDialog::OnClose()
	{
		return CALL(OnClose_t, 0x539d80, this);
	}

	GUITweakerGroup* GUITweakerDialog::BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags)
	{
		return CALL(BeginGroup_t, 0x538c40, this, label, flags);
	}

	void GUITweakerDialog::EndGroup()
	{
		CALL(EndGroup_t, 0x538d60, this);
	}

	GUITweakerGroup* GUITweakerDialog::GetCurrentGroup()
	{
		return CALL(GetCurrentGroup_t, 0x539650, this);
	}

	TGUIColorTweaker<DLMT::DL_COLOR_32>* GUITweakerDialog::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags)
	{
		GUITweakerGroup* pGroup = GetCurrentGroup();

		DL_ASSERT(pGroup);

		if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateColorTweaker(label, v, flags);
	}

	TGUIColorTweaker<DLMT2::DL_COLOR_U8>* GUITweakerDialog::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags)
	{
		GUITweakerGroup* pGroup = GetCurrentGroup();

		DL_ASSERT(pGroup);

		if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateColorTweaker(label, v, flags);
	}

	TGUIColorTweaker<DLMT::DL_VECTOR4>* GUITweakerDialog::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags)
	{
		GUITweakerGroup* pGroup = GetCurrentGroup();

		DL_ASSERT(pGroup);

		if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateColorTweaker(label, v, flags);
	}

	GUITextureList* GUITweakerDialog::CreateTextureList(TGUISharedString<dl_wchar> label)
	{
		GUITweakerGroup* pGroup = GetCurrentGroup();

		DL_ASSERT(pGroup);

		if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateTextureList(label);
	}

	GUITextureViewer* GUITweakerDialog::CreateTextureViewer(TGUISharedString<dl_wchar> label, GUITextureBase* pTexture)
	{
		GUITweakerGroup* pGroup = GetCurrentGroup();

		DL_ASSERT(pGroup);

		if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateTextureViewer(label, pTexture);
	}
}