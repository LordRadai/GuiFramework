#pragma once
#include "GuiFramework/Window/Control/GUIListViewItem.h"

namespace GuiFramework
{
	class GUIHeapList;

	class GUIHeapListItem : public GUIListViewItem
	{
		typedef GUIHeapListItem ThisClass;
		typedef GUIListViewItem SuperClass;

	public:
		GUIHeapListItem() {}
		GUIHeapListItem(TGUISharedString<dl_wchar> label, DLKR::DLAllocator* pHeap);
		GUIHeapListItem(GUIHeapList* pOwner, TGUISharedString<dl_wchar> label, DLKR::DLAllocator* pHeap);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIHeapListItem() override;
		virtual void OnDelete() override;
		virtual dl_uint GetRenderText(DLTX::DLString& out) const override;

	protected:
		DLKR::DLAllocator* m_pHeap;
	};
}