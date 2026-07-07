#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUICallbackObjectBase : public GUIMsgReceiver
	{
	public:
		GUICallbackObjectBase() : GUIMsgReceiver() {}

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUICallbackObjectBase() override {}
		virtual void OnDelete() override {};
		virtual void Invoke() {};
	};
}