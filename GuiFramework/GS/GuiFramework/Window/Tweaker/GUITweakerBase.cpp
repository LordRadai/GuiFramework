#include "GUITweakerBase.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUITweakerBase*);

	typedef void(__fastcall* InvokeCallback_t)(GUITweakerBase*);

	GUITweakerBase::GUITweakerBase() : m_flags(0), m_pCallback(nullptr)
	{
		CALL(Constructor_t, 0x541490, this);
	}

	DLRF::DLRuntimeClass* GUITweakerBase::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x541440, this);
	}

	GUITweakerBase::~GUITweakerBase()
	{
		CALL(Destructor_t, 0x541790, this);
	}

	void GUITweakerBase::OnDelete()
	{
		CALL(OnDelete_t, 0x541560, this);
	}

	void GUITweakerBase::InvokeCallback()
	{
		CALL(InvokeCallback_t, 0x5415a0, this);
	}
}