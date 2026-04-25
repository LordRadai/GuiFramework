#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/System/GUISystem.h"

namespace GuiFramework
{
	class GUITimer : public GUIMsgReceiver
	{
		typedef GUITimer ThisClass;
		typedef GUIMsgReceiver SuperClass;
	public:
		GUITimer() {}
		GUITimer(GUISystem* pGUISystem);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITimer() override;

#define SIGNAL_ON_ELAPSED (GUISignalDecl*)(MODULE_ADDR + 0x1617a70);
	protected:
		dl_float32 m_fInterval;
		TGUIObjectPtr<GUISystem> m_pAppGUISystem;
		dl_uint m_iVar20;
	};
}