#pragma once
#include "GUITweakerBase.h"
#include "GUIRangeTweakWidget.h"

namespace GuiFramework
{
	class GUIRangeTweaker : public GUITweakerBase
	{
		typedef GUIRangeTweaker ThisClass;
		typedef GUITweakerBase SuperClass;
	public:
		GUIRangeTweaker(TGUISharedString<dl_wchar> label, GUIRangeDataBase* pRangeData);
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const;
		virtual ~GUIRangeTweaker() override;
		virtual void OnDelete() override;
		virtual void Close() override;
		virtual void OnValueChanged() const {}
		virtual GUIRangeDataBase* GetRangeData() const = 0;

		void Create(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label);

		typedef void(_fastcall* OnValueChanged_t)(const GUIRangeTweaker*);
		typedef GUIRangeDataBase*(_fastcall* GetRangeData_t)(const GUIRangeTweaker*);
	protected:
		void _Destroy();

		TGUIObjectPtr<GUIRangeTweakWidget> m_pWidget;
	};
}