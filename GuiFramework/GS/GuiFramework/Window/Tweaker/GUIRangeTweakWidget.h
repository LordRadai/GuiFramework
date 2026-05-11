#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Control/GUISlider.h"
#include "GuiFramework/Window/ControlEx/GUINumericEditBox.h"
#include "GuiFramework/Window/Control/GUIRangeDataBase.h"

namespace GuiFramework
{
	class GUIRangeTweakWidget : public GUIWidget
	{
		typedef GUIRangeTweakWidget ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUIRangeTweakWidget(TGUISharedString<dl_wchar> label, GUIRangeDataBase* pRangeData);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const;
		virtual ~GUIRangeTweakWidget() override;
		virtual void OnDelete() override;
		virtual dl_uint IsMoveChild() const override { return false; }
		virtual dl_uint OnMButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual GUINumericEditBox* CreateEditBox();

		typedef GUINumericEditBox* (_fastcall* CreateEditBox_t)(GUIRangeTweakWidget*);
	protected:
		void _Destroy();

		TGUIObjectPtr<GUISlider> m_pSlider;
		TGUIObjectPtr<GUINumericEditBox> m_pEditBox;
		TGUIObjectPtr<GUIRangeDataBase> m_pRangeData;
		dl_uint16 m_iVar128;
	};
}