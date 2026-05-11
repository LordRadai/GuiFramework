#include "GUIHeapListItem.h"
#include "GUIHeapList.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIHeapListItem*, TGUISharedString<dl_wchar>, DLKR::DLAllocator*);
	typedef void(_fastcall* ConstructorWithOwner_t)(GUIHeapListItem*, GUIHeapList*, TGUISharedString<dl_wchar>, DLKR::DLAllocator*);

	GUIHeapListItem::GUIHeapListItem(TGUISharedString<dl_wchar> label, DLKR::DLAllocator* pHeap)
	{
		CALL(Constructor_t, 0xc53d10, this, label, pHeap);
	}

	GUIHeapListItem::GUIHeapListItem(GUIHeapList* pOwner, TGUISharedString<dl_wchar> label, DLKR::DLAllocator* pHeap)
	{
		CALL(ConstructorWithOwner_t, 0xc53c90, this, pOwner, label, pHeap);
	}

	DLRF::DLRuntimeClass* GUIHeapListItem::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0xc53c40, this);
	}

	GUIHeapListItem::~GUIHeapListItem()
	{
		CALL(Destructor_t, 0xc546b0, this);
	}

	void GUIHeapListItem::OnDelete()
	{
		CALL(OnDelete_t, 0xc54320, this);
	}

	dl_uint GUIHeapListItem::GetRenderText(DLTX::DLString& out) const
	{
		return CALL(GetRenderText_t, 0xc53de0, this, out);
	}
}