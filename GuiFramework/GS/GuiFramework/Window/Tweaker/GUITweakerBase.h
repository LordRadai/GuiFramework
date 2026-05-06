#pragma once
#include "GUITweakerItem.h"
#include "GuiFramework/Callback/TGUICallbackObject.inl"

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

		typedef void(__fastcall* Update_t)(GUITweakerBase*, dl_float32);
		typedef void(__fastcall* Close_t)(GUITweakerBase*);
	protected:
		dl_uint m_flags;
		GUICallbackObjectBase* m_pCallback;
	};
}