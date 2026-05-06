#include "GUIHeapList.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIHeapList*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* ConstructorWithCreateParams_t)(GUIHeapList*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);

	GUIHeapList::GUIHeapList(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0xc53170, this, label);
	}

	GUIHeapList::GUIHeapList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams)
	{
		CALL(ConstructorWithCreateParams_t, 0xc531e0, this, pParent, label, createParams);
	}

	DLRF::DLRuntimeClass* GUIHeapList::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0xc53120, this);
	}

	GUIHeapList::~GUIHeapList()
	{
		CALL(Destructor_t, 0xc54670, this);
	}

	void GUIHeapList::OnDelete()
	{
		CALL(OnDelete_t, 0xc53ba0, this);
	}

	dl_uint GUIHeapList::OnCreate()
	{
		return CALL(OnCreate_t, 0xc535d0, this);
	}

	dl_uint GUIHeapList::OnClose()
	{
		return CALL(OnClose_t, 0xc53bd0, this);
	}
}