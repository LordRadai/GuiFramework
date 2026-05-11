#pragma once
#include "GUITweakerBase.h"
#include "GUIComboTweakWidget.h"

namespace GuiFramework
{
	class GUIComboTweaker : public GUITweakerBase
	{
		typedef GUIComboTweaker ThisClass;
		typedef GUITweakerBase SuperClass;
	public:
		GUIComboTweaker() : SuperClass() {}
		GUIComboTweaker(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIComboTweaker() override;
		virtual void OnDelete() override;
		virtual void Update(dl_float32 dt) override {}
		virtual void Close() override;

		void SetComboCurSel(dl_int index);
	protected:
		void _Destroy();
		virtual void _OnComboSelChanged(dl_int idx) {}

		typedef void(_fastcall* OnComboSelectionChanged_t)(GUIComboTweaker*);

		TGUIObjectPtr<GUIComboTweakWidget> m_pComboTweakWidget;
	};
}