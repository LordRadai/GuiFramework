#include "GUIRangeDataBase.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(const GUIRangeDataBase*);

	GUIRangeDataBase::GUIRangeDataBase()
	{
		CALL(Constructor_t, 0x540d80, this);
	}

	DLRF::DLRuntimeClass* GUIRangeDataBase::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x540d30, this);
	}

	GUIRangeDataBase::~GUIRangeDataBase()
	{
		CALL(Destructor_t, 0x540f80, this);
	}
}