#include "GUITweakerGroup.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(const GUITweakerGroup*, TGUISharedString<dl_wchar>);

	typedef void(__fastcall* AddItem_t)(GUITweakerGroup*, GUITweakerItem*);

	typedef GUITweakerGroup*(__fastcall* CreateSubGroup_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, dl_uint);

	typedef TGUIColorTweaker<DLMT::DL_COLOR_32>*(__fastcall* CreateColorTweakerInt_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, DLMT::DL_COLOR_32*, dl_uint);
	typedef TGUIColorTweaker<DLMT2::DL_COLOR_U8>*(__fastcall* CreateColorTweakerU8_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, DLMT2::DL_COLOR_U8*, dl_uint);
	typedef TGUIColorTweaker<DLMT::DL_VECTOR4>* (__fastcall* CreateColorTweakerFloat_t)(GUITweakerGroup*, TGUISharedString<dl_wchar>, DLMT::DL_VECTOR4*, dl_uint);

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

	GUITweakerGroup* GUITweakerGroup::CreateSubGroup(TGUISharedString<dl_wchar> label, dl_uint flags)
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

	TGUIComboTweaker<dl_int8>* GUITweakerGroup::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int8>* items)
	{
		TGUIValueStringPairData<dl_int8>* data = new TGUIValueStringPairData<dl_int8>(items, numItems);
		TGUIComboTweaker<dl_int8>* pTweaker = new TGUIComboTweaker<dl_int8>(this, label, v, data);

		if (pTweaker)
			this->AddItem(pTweaker);

		return pTweaker;
	}

	TGUIComboTweaker<dl_uint8>* GUITweakerGroup::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint8>* items)
	{
		TGUIValueStringPairData<dl_uint8>* data = new TGUIValueStringPairData<dl_uint8>(items, numItems);
		TGUIComboTweaker<dl_uint8>* pTweaker = new TGUIComboTweaker<dl_uint8>(this, label, v, data);

		if (pTweaker)
			this->AddItem(pTweaker);

		return pTweaker;
	}

	TGUIComboTweaker<dl_int16>* GUITweakerGroup::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int16>* items)
	{
		TGUIValueStringPairData<dl_int16>* data = new TGUIValueStringPairData<dl_int16>(items, numItems);
		TGUIComboTweaker<dl_int16>* pTweaker = new TGUIComboTweaker<dl_int16>(this, label, v, data);

		if (pTweaker)
			this->AddItem(pTweaker);

		return pTweaker;
	}

	TGUIComboTweaker<dl_uint16>* GUITweakerGroup::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint16>* items)
	{
		TGUIValueStringPairData<dl_uint16>* data = new TGUIValueStringPairData<dl_uint16>(items, numItems);
		TGUIComboTweaker<dl_uint16>* pTweaker = new TGUIComboTweaker<dl_uint16>(this, label, v, data);

		if (pTweaker)
			this->AddItem(pTweaker);

		return pTweaker;
	}

	TGUIComboTweaker<dl_int>* GUITweakerGroup::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int>* items)
	{
		TGUIValueStringPairData<dl_int>* data = new TGUIValueStringPairData<dl_int>(items, numItems);
		TGUIComboTweaker<dl_int>* pTweaker = new TGUIComboTweaker<dl_int>(this, label, v, data);

		if (pTweaker)
			this->AddItem(pTweaker);

		return pTweaker;
	}

	TGUIComboTweaker<dl_uint>* GUITweakerGroup::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint>* items)
	{
		TGUIValueStringPairData<dl_uint>* data = new TGUIValueStringPairData<dl_uint>(items, numItems);
		TGUIComboTweaker<dl_uint>* pTweaker = new TGUIComboTweaker<dl_uint>(this, label, v, data);

		if (pTweaker)
			this->AddItem(pTweaker);

		return pTweaker;
	}

	void GUITweakerGroup::SetFirstOpenCallback(FirstOpenCallback_t pCallback, dl_size param1, dl_size param2)
	{
		this->m_pRestoredCb = pCallback;
		this->m_cbParam1 = param1;
		this->m_cbParam2 = param2;
	}
}
