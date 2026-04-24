#include "GUIWindowManager.h"

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIWindowManager*, GUISystem*);

	typedef void(__fastcall* SetFocus_t)(GUIWindowManager*, GUIWindowBase*);

	GUIWindowManager::GUIWindowManager(GUISystem* pGUISystem)
	{
		CALL(Constructor_t, 0x567130, this, pGUISystem);
	}

	GUIWindowManager::~GUIWindowManager()
	{
		CALL(Destructor_t, 0x570e70, this);
	}

	void GUIWindowManager::SetFocus(GUIWindowBase* pWindow)
	{
		CALL(SetFocus_t, 0x568640, this, pWindow);
	}
}