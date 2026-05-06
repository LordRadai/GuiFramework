#pragma once
#include "GuiFramework/Window/Control/GUIAutoVLayout.h"
#include "GUITweakerGroupItem.h"
#include "TGUIColorTweaker.inl"

namespace GuiFramework
{
	class GUITweakerGroup : public GUIAutoVLayout
	{
		typedef GUITweakerGroup ThisClass;
		typedef GUIAutoVLayout SuperClass;
	public:
		GUITweakerGroup() {}
		GUITweakerGroup(TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITweakerGroup() override;
		virtual void OnDelete() override;
		virtual dl_uint OnRestored() override;
		virtual dl_uint OnClose() override;

		TGUIColorTweaker<DLMT::DL_COLOR_32>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags);

	protected:
		DLUT::DLVector<GUITweakerGroupItem*> m_items;
		dl_int m_iVar138;
		dl_int m_iVar13C;
		dl_int m_iVar140;
		dl_int m_iVar144;
		dl_int m_iVar148;
		dl_int m_iVar14C;
		dl_int m_iVar150;
	};
}
