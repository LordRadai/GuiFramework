#pragma once
#include "GUITweakerGroup.h"
#include "GUITweakerDialog.h"

namespace GuiFramework
{
	class GUITweakerMaker
	{
	public:
		GUITweakerMaker(GUITweakerMaker* pTweakerMaker);
		GUITweakerMaker(GUITweakerGroup* pGroup);
		GUITweakerMaker(GUITweakerDialog* pDialog);

		~GUITweakerMaker();

		GUITweakerGroup* BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags);
		void EndGroup();
		GUITweakerGroup* GetCurrentGroup();

		void AddItem(GUITweakerGroupItem* pItem);
		void SetFirstOpenCallback(GUITweakerGroup::FirstOpenCallback_t pCallback, dl_size param1, dl_size param2);

		TGUIColorTweaker<DLMT::DL_COLOR_32>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags);

		TGUIComboTweaker<dl_int8>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int8>* items);
		TGUIComboTweaker<dl_uint8>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint8>* items);
		TGUIComboTweaker<dl_int16>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int16>* items);
		TGUIComboTweaker<dl_uint16>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint16>* items);
		TGUIComboTweaker<dl_int>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int>* items);
		TGUIComboTweaker<dl_uint>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint>* items);
	protected:
		void _PushGroup(GUITweakerGroup* pGroup);
		void _PopGroup();

		DLUT::DLVector<GUITweakerGroup*> m_groups;
	};
}