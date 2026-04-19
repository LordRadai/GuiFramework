#include "GUILayoutItem_Window.h"
#include "GuiFramework/Window/GUIWindowBase.h"

namespace GuiFramework
{
	typedef void(__fastcall* Ctor_t)(GUILayoutItem_Window*, GUIWindowBase*);

	GUILayoutItem_Window::GUILayoutItem_Window(GUIWindowBase* pWindow)
	{
		CALL(Ctor_t, 0x5e2830, this, pWindow);
	}

	DLRF::DLRuntimeClass* GUILayoutItem_Window::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClass_t, 0x5e27e0, this);
	}

	GUILayoutItem_Window::~GUILayoutItem_Window()
	{
		CALL(Destructor_t, 0x5e3560, this);
	}

	void GUILayoutItem_Window::OnDelete()
	{
		CALL(OnDelete_t, 0x5e3060, this);
	}

	GUISystem* GUILayoutItem_Window::GetGUISystem() const
	{
		return CALL(GetGUISystem_t, 0x5e2c00, this);
	}

	Rect GUILayoutItem_Window::GetMaxSize() const
	{
		return CALL(GetMaxSize_t, 0x5e2c30, this);
	}

	Rect GUILayoutItem_Window::GetMinSize() const
	{
		return CALL(GetMinSize_t, 0x5e2d00, this);
	}

	Rect GUILayoutItem_Window::GetIdealSize() const
	{
		return CALL(GetIdealSize_t, 0x5e2dd0, this);
	}

	void GUILayoutItem_Window::SetGeometry(const Rect& rect)
	{
		CALL(SetGeometry_t, 0x5e2ea0, this, rect);
	}

	Rect GUILayoutItem_Window::GetGeometry() const
	{
		return CALL(GetGeometry_t, 0x5e2f50, this);
	}

	dl_bool GUILayoutItem_Window::IsOwn(GUIObject* pObject) const
	{
		return CALL(IsOwn_t, 0x5e3000, this, pObject);
	}
}