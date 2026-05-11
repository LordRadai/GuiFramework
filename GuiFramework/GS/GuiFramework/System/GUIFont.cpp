#include "GUIFont.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Ctor_t)(GUIFont*);

	typedef void(_fastcall* CreateTweaker_t)(GUIFont*, TGUISharedString<dl_wchar>&, GUITweakerDialog*);

	GUIFont::GUIFont()
	{
		CALL(Ctor_t, 0x562be0, this);
	}

	GUIFont::~GUIFont()
	{
		CALL(Destructor_t, 0x564c40, this);
	}

	DLRF::DLRuntimeClass* GUIFont::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x562b90, this);
	}

	void GUIFont::CreateTweaker(TGUISharedString<dl_wchar>& title, GUITweakerDialog* pWnd)
	{
		CALL(CreateTweaker_t, 0x562cb0, this, title, pWnd);
	}
}