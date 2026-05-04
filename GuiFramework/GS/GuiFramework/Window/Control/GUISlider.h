#pragma once
#include "GuiFramework/Window/GUIWindowBase.h"

namespace GuiFramework
{
	class GUISlider : public GUIWindowBase
	{
		typedef GUISlider ThisClass;
		typedef GUIWindowBase SuperClass;
	public:
		enum SliderFlag : dl_uint
		{
		};

		GUISlider() {}
		GUISlider(TGUISharedString<dl_wchar> label);
		GUISlider(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams);
		GUISlider(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUISlider() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnMouseLeave() override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnPreCreate(const _GUI_CREATE_WINDOW& createParams) override;
		virtual void OnRender(GraphicsContext& gc) const override;
	protected:
		Rect16 m_innerRect;
		dl_uint m_min;
		dl_uint m_max;
		dl_uint m_value;
		dl_uint m_iVar8C;
		dl_uint m_flags;
	};
}