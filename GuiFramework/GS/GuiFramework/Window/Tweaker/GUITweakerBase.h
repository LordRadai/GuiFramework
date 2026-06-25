#pragma once
#include "GUITweakerItem.h"
#include "GuiFramework/System/TGUICallbackObject.inl"

namespace GuiFramework
{
	class GUITweakerBase : public GUITweakerItem
	{
		typedef GUITweakerBase ThisClass;
		typedef GUITweakerItem SuperClass;
	public:
		GUITweakerBase();

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITweakerBase() override;
		virtual void OnDelete() override;
		virtual void Update(dl_float32 dt) override {}
		virtual void Close() override {}
		
		void InvokeCallback();
		void SetOnValueChangedCb(GUICallbackObjectBase* pCallback) { m_pOnValueChangedCb = pCallback; }
	protected:
		void _Destroy();

		dl_uint m_flags;
		GUICallbackObjectBase* m_pOnValueChangedCb;
	};
}