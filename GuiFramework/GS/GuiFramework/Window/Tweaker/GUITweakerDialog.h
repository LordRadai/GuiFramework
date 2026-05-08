#pragma once
#include "GuiFramework/Window/Control/GUIAutoVLayoutScroll.h"
#include "GUITweakerGroup.h"

namespace GuiFramework
{
	class GUITweakerDialog : public GUIAutoVLayoutScroll
	{
		typedef GUITweakerDialog ThisClass;
		typedef GUIAutoVLayoutScroll SuperClass;
	public:
		GUITweakerDialog() {}
		GUITweakerDialog(TGUISharedString<dl_wchar> label);
		GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW&);
		GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITweakerDialog() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnUpdate(dl_float32 fDeltaTime) override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnClose() override;

		GUITweakerGroup* GetCurrentGroup();

		GUITweakerGroup* BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags);
		void EndGroup();

		TGUIColorTweaker<DLMT::DL_COLOR_32>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags);

		TGUIComboTweaker<dl_int8>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int8>* items);
		TGUIComboTweaker<dl_uint8>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint8>* items);
		TGUIComboTweaker<dl_int16>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int16>* items);
		TGUIComboTweaker<dl_uint16>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint16>* items);
		TGUIComboTweaker<dl_int>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int>* items);
		TGUIComboTweaker<dl_uint>* CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint>* items);
	private:
		DLUT::DLVector<GUITweakerGroupItem*> m_items;
		DLUT::DLVector<GUITweakerGroup*> m_groups;
	};
}