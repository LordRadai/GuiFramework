#pragma once
#include "GUITweakerBase.h"
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Control/GUICheckBox.h"

namespace GuiFramework
{
	class GUIOnOffTweaker : public GUITweakerBase
	{
		typedef GUIOnOffTweaker ThisClass;
		typedef GUITweakerBase SuperClass;
	public:
		GUIOnOffTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIOnOffTweaker() override;
		virtual void OnDelete() override;
		virtual void Close() override;

		void SetCheck(dl_uint check);
		dl_bool IsChecked() const;
	protected:
		TGUIObjectPtr<GUICheckBox> m_pCheckBox;
	};
}