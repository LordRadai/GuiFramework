#pragma once
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/ControlEx/GUIButton.h"

namespace GuiFramework
{
	class GUITriggerTweakWidget : public GUIWidget
	{
		typedef GUITriggerTweakWidget ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUITriggerTweakWidget(TGUISharedString<dl_wchar> label);

		DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITriggerTweakWidget() override;
		virtual void OnDelete() override;
		virtual dl_uint IsMoveChild() const override { return false; }
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnVirtualInputRender(GraphicsContext& gc) const override;

		GUIButton* AddButton(TGUISharedString<dl_wchar> label);
	private:
		DLUT::DLVector<TGUIObjectPtr<GUIButton>> m_buttons;
		dl_uint16 m_iVar130;
		dl_int8 m_selectedButtonIdx;
	};
}