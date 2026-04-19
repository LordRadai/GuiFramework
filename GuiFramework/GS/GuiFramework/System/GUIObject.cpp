#include <Call.h>
#include "GUIObject.h"
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	typedef void(__fastcall* GUIObject_ctor_t)(GUIObject*);
	typedef void(__fastcall* AddRef_t)(GUIObject*);
	typedef void(__fastcall* UnRef_t)(GUIObject*);

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

	void GUIObject::AddRef()
	{
		CALL(AddRef_t, 0x30b460, this);
	}

	void GUIObject::UnRef()
	{
		CALL(UnRef_t, 0x30b4e0, this);
	}
}