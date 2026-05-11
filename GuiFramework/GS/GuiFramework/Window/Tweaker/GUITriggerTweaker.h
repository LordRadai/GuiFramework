#pragma once
#include "GUITweakerBase.h"
#include "GUITriggerTweakWidget.h"

namespace GuiFramework
{
	class GUITriggerTweaker : public GUITweakerBase
	{
		typedef GUITriggerTweaker ThisClass;
		typedef GUITweakerBase SuperClass;
	public:
		GUITriggerTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITriggerTweaker() override;
		virtual void OnDelete() override;
		virtual void Close() override;

		void AddButton(TGUISharedString<dl_wchar> label, GUICallbackObjectBase* pCallback);
	private:
		DLUT::DLVector<TGUIObjectPtr<GUICallbackObjectBase>> m_callbacks;
		TGUIObjectPtr<GUITriggerTweakWidget> m_pWidget;
	};
}