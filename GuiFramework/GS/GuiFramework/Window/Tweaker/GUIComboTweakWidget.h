#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Control/GUIComboBox.h"

namespace GuiFramework
{
	class GUIComboTweakWidget : public GUIWidget
	{
		typedef GUIComboTweakWidget ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUIComboTweakWidget() : SuperClass() {}
		GUIComboTweakWidget(TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIComboTweakWidget() override;
		virtual void OnDelete() override;
		virtual dl_uint IsMoveChild() const override { return false; }
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void InitComboBox(GUIComboBox* pComboBox) {}

		typedef void(_fastcall* InitComboBox_t)(GUIComboTweakWidget*, GUIComboBox*);
	protected:
		TGUIObjectPtr<GUIComboBox> m_pComboBox;
		dl_uint16 m_iVar118;
	};
}