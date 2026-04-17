#pragma once
#include "GUIObject.h"

namespace GuiFramework
{
	class GUIMsgReceiver : public GUIObject
	{
		typedef GUIMsgReceiver ThisClass;
	public:
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIMsgReceiver() override;
	};
}
