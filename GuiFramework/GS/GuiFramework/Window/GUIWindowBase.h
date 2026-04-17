#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUIWindowBase : public GUIMsgReceiver
	{
		typedef GUIWindowBase ThisClass;
	public:
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIWindowBase() override;
	};
}
