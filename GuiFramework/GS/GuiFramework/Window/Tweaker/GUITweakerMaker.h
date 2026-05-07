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

		GUITweakerGroup* BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags);
		void EndGroup();
		GUITweakerGroup* GetCurrentGroup();

		void AddItem(GUITweakerGroupItem* pItem);
		void SetFirstOpenCallback(GUITweakerGroup::FirstOpenCallback_t pCallback, dl_size param1, dl_size param2);

		TGUIColorTweaker<DLMT::DL_COLOR_32>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags);
	protected:
		void _PushGroup(GUITweakerGroup* pGroup);
		void _PopGroup();

		DLUT::DLVector<GUITweakerGroup*> m_groups;
	};
}