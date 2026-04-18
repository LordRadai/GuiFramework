#include "GUIWindowManager.h"

namespace GuiFramework
{
	GUIWindowManager::~GUIWindowManager()
	{
		CALL(Destructor_t, 0x570e70, this);
	}

	void GUIWindowManager::SetFocus(GUIWindowBase* pWindow)
	{
		CALL(SetFocus_t, 0x568640, this, pWindow);
	}
}