#pragma once
#include "GuiFramework/Window/Control/GUIListView.h"

namespace GuiFramework
{
	class GUIHeapList : public GUIListView
	{
		typedef GUIHeapList ThisClass;
		typedef GUIListView SuperClass;
	public:
		GUIHeapList() : GUIListView() {}
		GUIHeapList(TGUISharedString<dl_wchar> label);
		GUIHeapList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIHeapList() override;
		virtual void OnDelete() override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnClose() override;
	protected:
		dl_uint8 m_dispFormat;
		dl_float32 m_fVar178;
		dl_float32 m_fVar17C;
	};
}