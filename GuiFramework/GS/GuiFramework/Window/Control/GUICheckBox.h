#pragma once
#include "GUIButtonBase.h"

namespace GuiFramework
{
	class GUICheckBox : public GUIButtonBase
	{
		typedef GUICheckBox ThisClass;
		typedef GUIButtonBase SuperClass;
	public:
		GUICheckBox() {}
		GUICheckBox(TGUISharedString<dl_wchar> label);
		GUICheckBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams);
		GUICheckBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUICheckBox() override;
		virtual void OnDelete() override;
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnButtonPressed() override;
	protected:
		dl_uint16 m_state;
	};
}