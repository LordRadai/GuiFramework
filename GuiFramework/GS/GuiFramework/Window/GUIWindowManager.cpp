#include "GUIWindowManager.h"

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIWindowManager*, GUISystem*);

	typedef dl_int(__fastcall* SetFocus_t)(GUIWindowManager*, GUIWindowBase*);
	typedef dl_bool(__fastcall* SetAfterWindow_t)(GUIWindowManager*, GUIWindowBase*, GUIWindowBase*);
	typedef dl_int(__fastcall* RegisterWindow_t)(GUIWindowManager*, GUIWindowBase*);

	typedef dl_bool(__fastcall* BeginVirtualInput_t)(GUIWindowManager*, GUIWindowBase*);
	typedef void(__fastcall* UpdateVirtualInput_t)(GUIWindowManager*, GUIVirtualInput&);
	typedef void(__fastcall* EndVirtualInput_t)(GUIWindowManager*);

	GUIWindowManager::GUIWindowManager(GUISystem* pGUISystem)
	{
		CALL(Constructor_t, 0x567130, this, pGUISystem);
	}

	GUIWindowManager::~GUIWindowManager()
	{
		CALL(Destructor_t, 0x570e70, this);
	}

	dl_int GUIWindowManager::SetFocus(GUIWindowBase* pWindow)
	{
		return CALL(SetFocus_t, 0x568640, this, pWindow);
	}

	dl_bool GUIWindowManager::SetAfterWindow(GUIWindowBase* pWindow, GUIWindowBase* pAfter)
	{
		return CALL(SetAfterWindow_t, 0x568960, this, pWindow, pAfter);
	}

	dl_int GUIWindowManager::RegisterWindow(GUIWindowBase* pWindow)
	{
		return CALL(RegisterWindow_t, 0x567520, this, pWindow);
	}

	dl_bool GUIWindowManager::BeginVirtualInput(GUIWindowBase* pWindow)
	{
		return CALL(BeginVirtualInput_t, 0x568540, this, pWindow);
	}

	void GUIWindowManager::UpdateVirtualInput(GUIVirtualInput& input)
	{
		CALL(UpdateVirtualInput_t, 0x5685e0, this, input);
	}

	void GUIWindowManager::EndVirtualInput()
	{
		CALL(EndVirtualInput_t, 0x568620, this);
	}
}