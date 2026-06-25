#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"

#include <functional>

namespace GuiFramework
{
	class GUICallbackObjectBase : public GUIMsgReceiver
	{
	public:
		GUICallbackObjectBase() : GUIMsgReceiver() {}

		virtual ~GUICallbackObjectBase() override {}
		virtual void OnDelete() override {};
		virtual void Invoke() {};
	};
}