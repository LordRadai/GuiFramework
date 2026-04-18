#include <Call.h>
#include "GUIObject.h"
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	typedef void(__fastcall* GUIObject_ctor_t)(GUIObject*);

	typedef DLRF::DLRuntimeClass* (__fastcall* GetRuntimeClass_t)(const GUIObject*);
	typedef void(__fastcall* Destructor_t)(GUIObject*);
	typedef void(__fastcall* OnDelete_t)(GUIObject*);

	GUIObject::GUIObject()
	{
		CALL(GUIObject_ctor_t, 0x527790, this);
	}

	DLRF::DLRuntimeClass* GUIObject::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClass_t, 0x527740, this);
	}

	GUIObject::~GUIObject()
	{
		CALL(Destructor_t, 0x5279f0, this);
	}

	void GUIObject::DeleteThis()
	{
		CALL(OnDelete_t, 0x527840, this);
	}
}