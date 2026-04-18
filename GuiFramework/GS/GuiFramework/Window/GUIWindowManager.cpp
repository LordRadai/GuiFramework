#include "GUIWindowManager.h"

namespace GuiFramework
{
	typedef void(__fastcall* GUIWindowManager_dtor_t)(GUIWindowManager*);

	typedef void(__fastcall* GUIWindowManager_SetFocus_t)(GUIWindowManager*, GUIWindowBase*);

	GUIWindowManager::~GUIWindowManager()
	{
		CALL(GUIWindowManager_dtor_t, 0x570e70, this);
	}

	void GUIWindowManager::SetFocus(GUIWindowBase* pWindow)
	{
		CALL(GUIWindowManager_SetFocus_t, 0x568640, this, pWindow);
	}
}