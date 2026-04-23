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
		virtual dl_bool IsMoveSelf() const override { return false; }
		virtual dl_bool OnSize() override;
		virtual dl_bool OnRestored() override;
		virtual dl_bool OnCreate() override;
		virtual dl_bool OnClose() override;
		virtual Rect GetDefaultSizeMax() const override;

	protected:
		TGUIObjectPtr<GUIVertLayouter> m_pVertLayouter;
	};
}
