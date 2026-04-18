#include "GUIFont.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* GUIFont_ctor_t)(GUIFont*);
	typedef void(__fastcall* GUIFont_dtor_t)(GUIFont*);

	typedef DLRF::DLRuntimeClass* (__fastcall* GUIFont_GetRuntimeClassOfThis_t)(const GUIFont*);

	GUIFont::GUIFont()
	{
		CALL(GUIFont_ctor_t, 0x562be0, this);
	}

	GUIFont::~GUIFont()
	{
		CALL(GUIFont_dtor_t, 0x564c40, this);
	}

	DLRF::DLRuntimeClass* GUIFont::GetRuntimeClassOfThis() const
	{
		return CALL(GUIFont_GetRuntimeClassOfThis_t, 0x562b90, this);
	}
}