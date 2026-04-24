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

		dl_uint Copy();
		dl_uint Cut();
		dl_uint Paste();
		dl_uint SelectAll();
		dl_uint Insert(const dl_wchar* str);
	private:
		dl_uint _Insert(const dl_wchar* str, dl_uint size);
	};
}
