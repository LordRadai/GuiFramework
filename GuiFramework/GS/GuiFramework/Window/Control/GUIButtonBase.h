#pragma once
#include "GuiFramework/Window/GUIWindowBase.h"

namespace GuiFramework
{
	class GUIButtonBase : public GUIWindowBase
	{
		typedef GUIButtonBase ThisClass;
		typedef GUIWindowBase SuperClass;
	public:
		enum InteractionFlag : dl_uint
		{

		};

		GUIButtonBase() {}
		GUIButtonBase(TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIButtonBase() override;
		virtual void OnDelete() override;
		virtual dl_bool OnMouseMove(const MouseEvent& event) override;
		virtual dl_bool OnLButtonDown(const MouseEvent& event) override;
		virtual dl_bool OnLButtonUp(const MouseEvent& event) override;
		virtual dl_bool OnMouseLeave() override;
		virtual void OnButtonPressed() {};

		typedef void(__fastcall* OnButtonPressed_t)();
	protected:
		dl_uint m_interactionFlags;
	};
}