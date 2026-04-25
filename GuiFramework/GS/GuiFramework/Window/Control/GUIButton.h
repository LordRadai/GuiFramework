#pragma once
#include "GUIButtonBase.h"

namespace GuiFramework
{
	class GUITriggerTweakWidget;

	class GUIButton : public GUIButtonBase
	{
	public:
		GUIButton() {}
		GUIButton(GUITriggerTweakWidget* pTriggerTweakWidget, TGUISharedString<dl_wchar> label, dl_uint flags);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIButton();
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnButtonPressed() override {}
	};
}