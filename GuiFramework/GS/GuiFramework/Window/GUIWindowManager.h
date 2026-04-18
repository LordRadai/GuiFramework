#pragma once
#include "GuiFramework/System/GUIObject.h"

namespace GuiFramework
{
	class GUISystem;
	class GUIRootWindow;
	class GUIWindowBase;

	class GUIWindowManager : public GUIObject
	{
		typedef GUIWindowManager ThisClass;
		typedef GUIObject SuperClass;

	public:
		virtual ~GUIWindowManager() override;

		void SetFocus(GUIWindowBase* pWindow);
	private:
		GUISystem* m_pAppGUISystem;
		GUIRootWindow* m_pRootWindow;
		GUIWindowBase* m_pActiveWindow;
		GUIWindowBase* m_pLastActiveWindow;
		DLUT::DLVector<GUIWindowBase*> m_pWindows;
		DLUT::DLVector<GUIWindowBase*> m_pCreateWindows;
		dl_int16 m_sVar70;
		dl_int16 m_sVar72;
		dl_int m_mouseX;
		dl_int m_mouseY;
		dl_uint m_mouseActionFlags;
		dl_int m_iVar80;
		dl_int m_iVar84;
		GUIWindowBase* m_pInteractingWindow;
		dl_uint m_interactingWindowIdx;
		DLUT::DLVector<dl_pointer> m_vVar98;
		DLUT::DLVector<dl_pointer> m_vVarB8;
		dl_int m_nextWindowX;
		dl_int m_nextWindowY;
		dl_int m_iVarE0;
		dl_int m_iVarE4;
		dl_uint m_width;
		dl_uint m_height;
		dl_int m_iVarF0;
		dl_float32 m_timeSinceLastClick;
		dl_float32 m_timeSinceLastClickPrev;
		dl_int m_lastClickX;
		dl_int m_lastClickY;

		typedef void(__fastcall* SetFocus_t)(GUIWindowManager*, GUIWindowBase*);
	};
}