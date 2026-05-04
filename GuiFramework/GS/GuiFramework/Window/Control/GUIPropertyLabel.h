#pragma once
#include "GuiFramework/Window/GUIWindowBase.h"

namespace GuiFramework
{
	class GUIPropertyLabel : public GUIWindowBase
	{
		typedef GUIPropertyLabel ThisClass;
		typedef GUIWindowBase SuperClass;
	public:
		GUIPropertyLabel() {}
		GUIPropertyLabel(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_int flags);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIPropertyLabel() override;
		virtual void OnDelete() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual dl_bool GetValueString(DLTX::DLString& str) const { return false; }

		typedef dl_bool(__fastcall* GetValueString_t)(const ThisClass*, DLTX::DLString&);
	};
}