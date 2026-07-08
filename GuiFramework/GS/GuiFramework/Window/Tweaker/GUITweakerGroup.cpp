#include "GUITweakerGroup.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(const GUITweakerGroup*, TGUISharedString<dl_wchar>);

	typedef void(_fastcall* AddItem_t)(GUITweakerGroup*, GUITweakerItem*);

	typedef GUITweakerGroupItem*(_fastcall* CreateSubGroup_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, dl_uint);

	typedef TGUIColorTweaker<DLMT::DL_COLOR_32>*(_fastcall* CreateColorTweakerInt_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, DLMT::DL_COLOR_32*, dl_uint);
	typedef TGUIColorTweaker<DLMT2::DL_COLOR_U8>*(_fastcall* CreateColorTweakerU8_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, DLMT2::DL_COLOR_U8*, dl_uint);
	typedef TGUIColorTweaker<DLMT::DL_VECTOR4>* (_fastcall* CreateColorTweakerFloat_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, DLMT::DL_VECTOR4*, dl_uint);

	typedef GUITextureList*(_fastcall* CreateTextureList_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>);
	typedef GUITextureViewer*(_fastcall* CreateTextureViewer_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, GUITextureBase*);

	typedef GUITriggerTweaker*(_fastcall* CreateTrigger_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>);

	GUITweakerGroup::GUITweakerGroup(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x54b390, this, label);
	}

	DLRF::DLRuntimeClass* GUITweakerGroup::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x54b340, this);
	}

	GUITweakerGroup::~GUITweakerGroup()
	{
		CALL(Destructor_t, 0x54e1d0, this);
	}

	void GUITweakerGroup::OnDelete()
	{
		CALL(OnDelete_t, 0x54d190, this);
	}

	dl_uint GUITweakerGroup::OnRestored()
	{
		return CALL(OnRestored_t, 0x54d310, this);
	}

	dl_uint GUITweakerGroup::OnClose()
	{
		return CALL(OnClose_t, 0x54d080, this);
	}

	void GUITweakerGroup::AddItem(GUITweakerItem* pItem)
	{
		CALL(AddItem_t, 0x54d3a0, this, pItem);
	}

	GUITweakerGroupItem* GUITweakerGroup::CreateSubGroup(TGUISharedString<dl_wchar> label, dl_uint flags)
	{
		return CALL(CreateSubGroup_t, 0x54b630, this, label, flags);
	}

	TGUIColorTweaker<DLMT::DL_COLOR_32>* GUITweakerGroup::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags)
	{
		return CALL(CreateColorTweakerInt_t, 0x54b900, this, label, v, flags);
	}

	TGUIColorTweaker<DLMT2::DL_COLOR_U8>* GUITweakerGroup::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags)
	{
		return CALL(CreateColorTweakerU8_t, 0x54ba40, this, label, v, flags);
	}

	TGUIColorTweaker<DLMT::DL_VECTOR4>* GUITweakerGroup::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags)
	{
		return CALL(CreateColorTweakerFloat_t, 0x54bb80, this, label, v, flags);
	}

	GUITextureList* GUITweakerGroup::CreateTextureList(TGUISharedString<dl_wchar> label)
	{
		return CALL(CreateTextureList_t, 0x54cd00, this, label);
	}

	GUITextureViewer* GUITweakerGroup::CreateTextureViewer(TGUISharedString<dl_wchar> label, GUITextureBase* pTexture)
	{
		return CALL(CreateTextureViewer_t, 0x54ca80, this, label, pTexture);
	}

	GUITriggerTweaker* GUITweakerGroup::CreateTrigger(TGUISharedString<dl_wchar> label)
	{
		return CALL(CreateTrigger_t, 0x54cf60, this, label);
	}

	void GUITweakerGroup::SetFirstOpenCallback(FirstOpenCallback_t pCallback, dl_size param1, dl_size param2)
	{
		this->m_pRestoredCb = pCallback;
		this->m_cbParam1 = param1;
		this->m_cbParam2 = param2;
	}
}
