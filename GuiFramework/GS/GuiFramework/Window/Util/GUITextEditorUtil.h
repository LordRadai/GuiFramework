#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUISystem;

	class GUITextEditorUtil : public GUIMsgReceiver
	{
		typedef GUITextEditorUtil ThisClass;
		typedef GUIMsgReceiver SuperClass;
	public:
		GUITextEditorUtil() {}
		GUITextEditorUtil(GUISystem* pGUISystem);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITextEditorUtil() override;
		virtual void OnDelete() override;
	};
}
