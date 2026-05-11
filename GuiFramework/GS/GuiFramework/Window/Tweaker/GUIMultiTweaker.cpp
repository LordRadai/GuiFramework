#include "GUIMultiTweaker.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIMultiTweaker*, dl_uint, TGUISharedString<dl_wchar>);

	typedef void(_fastcall* Destroy_t)(GUIMultiTweaker*);
	typedef dl_bool(_fastcall* Create_t)(GUIMultiTweaker*, GUIWindowBase*, TGUISharedString<dl_wchar>);

	GUIMultiTweaker::GUIMultiTweaker(dl_uint numValues, TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5b3e30, this, numValues, label);
	}

	DLRF::DLRuntimeClass* GUIMultiTweaker::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5b3de0, this);
	}

	GUIMultiTweaker::~GUIMultiTweaker()
	{
		CALL(Destructor_t, 0x5b4330, this);
	}

	void GUIMultiTweaker::OnDelete()
	{
		CALL(OnDelete_t, 0x5b40b0, this);
	}

	void GUIMultiTweaker::Close()
	{
		CALL(Close_t, 0x5b40e0, this);
	}

	void GUIMultiTweaker::_Destroy()
	{
		CALL(Destroy_t, 0x5b3f20, this);
	}

	dl_bool GUIMultiTweaker::Create(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label)
	{
		return CALL(Create_t, 0x5b3f90, this, pParent, label);
	}
}