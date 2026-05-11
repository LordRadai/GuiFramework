#include "GUIRangeTweaker.h"

namespace GuiFramework
{
	typedef void(_fastcall* Constructor1_t)(GUIRangeTweaker*);
	typedef void(_fastcall* Constructor2_t)(GUIRangeTweaker*, TGUISharedString<dl_wchar>, GUIRangeDataBase*);

	typedef void(_fastcall* Create_t)(GUIRangeTweaker*, GUIWindowBase*, TGUISharedString<dl_wchar>);

	GUIRangeTweaker::GUIRangeTweaker() 
	{
		CALL(Constructor1_t, 0x541ca0, this);
	}

	GUIRangeTweaker::GUIRangeTweaker(TGUISharedString<dl_wchar> label, GUIRangeDataBase* pRangeData) 
	{
		CALL(Constructor2_t, 0x541ca0, this, label, pRangeData);
	}

	DLRF::DLRuntimeClass* GUIRangeTweaker::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x541c50, this);
	}

	GUIRangeTweaker::~GUIRangeTweaker()
	{
		CALL(Destructor_t, 0x5424d0, this);
	}

	void GUIRangeTweaker::OnDelete()
	{
		CALL(OnDelete_t, 0x541fc0, this);
	}

	void GUIRangeTweaker::Close()
	{
		CALL(Close_t, 0x541ff0, this);
	}

	void GUIRangeTweaker::Create(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label)
	{
		CALL(Create_t, 0x541d60, this, pParent, label);
	}

	void GUIRangeTweaker::_Destroy()
	{
		CALL(_Destroy_t, 0x541cf0, this);
	}
}