#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUITweakerItem : public GUIMsgReceiver
	{
		typedef GUITweakerItem ThisClass;
		typedef GUIMsgReceiver SuperClass;
	public:
		GUITweakerItem();

		virtual ~GUITweakerItem() override;
		virtual void OnDelete() override {}
		virtual void Update(dl_float32 dt) {}
		virtual void Close() {}

		typedef void(__fastcall* Update_t)(GUITweakerItem*, dl_float32);
		typedef void(__fastcall* Close_t)(GUITweakerItem*);
	protected:
		void _Destroy();
	};
}
