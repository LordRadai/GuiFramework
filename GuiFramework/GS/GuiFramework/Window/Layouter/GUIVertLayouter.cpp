#include "GUIVertLayouter.h"

namespace GuiFramework
{
	typedef void(__fastcall* Ctor_t)(GUIVertLayouter*, GUIWidget*);

	GUIVertLayouter::GUIVertLayouter(GUIWidget* pOwner) : GUILayouter(pOwner)
	{
		CALL(Ctor_t, 0x5c4c90, this, pOwner);
	}

	DLRF::DLRuntimeClass* GUIVertLayouter::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClass_t, 0x5c4c40, this);
	}

	GUIVertLayouter::~GUIVertLayouter()
	{
		CALL(Destructor_t, 0x5c78f0, this);
	}

	void GUIVertLayouter::OnDelete()
	{
		CALL(OnDelete_t, 0x5c6720, this);
	}

	dl_bool GUIVertLayouter::OnOwnerSizeChanged(const TGUI_SIZE<int>& size)
	{
		return CALL(OnOwnerSizeChanged_t, 0x5c6440, this, size);
	}

	dl_bool GUIVertLayouter::AutoAdd(GUIWindowBase* pWindow)
	{
		return CALL(AutoAdd_t, 0x5c6100, this, pWindow);
	}

	dl_bool GUIVertLayouter::AutoRemove(GUIWindowBase* pWindow)
	{
		return CALL(AutoRemove_t, 0x5c62a0, this, pWindow);
	}
}