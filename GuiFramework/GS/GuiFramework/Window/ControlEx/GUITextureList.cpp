#include "GUITextureList.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUITextureList*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* ConstructorWithCreateParams_t)(GUITextureList*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(__fastcall* ConstructorWithFlags_t)(GUITextureList*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	typedef dl_uint(__fastcall* AddTexture_t)(GUITextureList*, TGUISharedString<dl_wchar>, GUITextureBase*, TGUISharedString<dl_wchar>);

	GUITextureList::GUITextureList(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5aafc0, this, label);
	}

	GUITextureList::GUITextureList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams)
	{
		CALL(ConstructorWithCreateParams_t, 0x5ab060, this, pParent, label, createParams);
	}

	GUITextureList::GUITextureList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorWithFlags_t, 0x5ab120, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUITextureList::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5aaf70, this);
	}

	GUITextureList::~GUITextureList()
	{
		CALL(Destructor_t, 0x5ad360, this);
	}

	void GUITextureList::OnDelete()
	{
		CALL(OnDelete_t, 0x5ac420, this);
	}

	dl_uint GUITextureList::OnSize()
	{
		return CALL(OnSize_t, 0x5ac3f0, this);
	}

	dl_uint GUITextureList::OnCreate()
	{
		return CALL(OnCreate_t, 0x5abd30, this);
	}

	dl_uint GUITextureList::OnClose()
	{
		return CALL(OnClose_t, 0x5ac3c0, this);
	}

	dl_uint GUITextureList::AddTexture(TGUISharedString<dl_wchar> name, GUITextureBase* pTexture, TGUISharedString<dl_wchar> path)
	{
		return CALL(AddTexture_t, 0x5ab370, this, name, pTexture, path);
	}
}