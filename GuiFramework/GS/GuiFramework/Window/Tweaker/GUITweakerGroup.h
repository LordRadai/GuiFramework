#pragma once
#include "GuiFramework/Window/Control/GUIAutoVLayout.h"
#include "GUITweakerGroupItem.h"

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
