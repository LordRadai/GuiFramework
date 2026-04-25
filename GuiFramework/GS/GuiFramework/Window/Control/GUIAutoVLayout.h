#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Layouter/GUIVertLayouter.h"

namespace GuiFramework
{
	class GUIAutoVLayout : public GUIWidget
	{
		typedef GUIAutoVLayout ThisClass;
		typedef GUIWidget SuperClass;

	public:
		GUIAutoVLayout() {}
		GUIAutoVLayout(TGUISharedString<dl_wchar>& label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIAutoVLayout() override;
		virtual void OnDelete() override;
		virtual dl_uint IsMoveSelf() const override { return false; }
		virtual dl_uint OnSize() override;
		virtual dl_uint OnRestored() override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnClose() override;
		virtual Rect GetDefaultSizeMax() const override;

	protected:
		TGUIObjectPtr<GUIVertLayouter> m_pVertLayouter;
	};
}
