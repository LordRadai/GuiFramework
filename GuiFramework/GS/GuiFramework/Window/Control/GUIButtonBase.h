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
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnMouseLeave() override;
		virtual void OnButtonPressed() {};

		typedef void(__fastcall* OnButtonPressed_t)(ThisClass*);
	protected:
		dl_uint m_interactionFlags;
	};
}