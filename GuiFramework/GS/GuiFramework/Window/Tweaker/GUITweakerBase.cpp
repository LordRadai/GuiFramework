#include "GUITweakerBase.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUITweakerBase*);

	typedef void(_fastcall* InvokeCallback_t)(GUITweakerBase*);

	GUITweakerBase::GUITweakerBase() : m_flags(0), m_pOnValueChangedCb(nullptr)
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

	void GUITweakerBase::_Destroy()
	{
		CALL(_Destroy_t, 0x5414f0, this);
	}
}