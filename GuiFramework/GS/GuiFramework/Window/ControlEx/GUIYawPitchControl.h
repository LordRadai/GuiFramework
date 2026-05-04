#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GUINumericEditBox.h"

namespace GuiFramework
{
	class GUIYawPitchControl : public GUIWidget
	{
		typedef GUIYawPitchControl ThisClass;
		typedef GUIWidget SuperClass;
	public:
		enum YawPitchControlFlags : dl_uint
		{
		};

		GUIYawPitchControl() {}
		GUIYawPitchControl(TGUISharedString<dl_wchar> label);
		GUIYawPitchControl(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIYawPitchControl() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;

		dl_float32 GetYaw() const;
		dl_float32 GetPitch() const;

	protected:
		TGUIObjectPtr<GUINumericEditBox> m_pYawEditBox;
		TGUIObjectPtr<GUINumericEditBox> m_pPitchEditBox;
		dl_uint m_flags;
	};
}