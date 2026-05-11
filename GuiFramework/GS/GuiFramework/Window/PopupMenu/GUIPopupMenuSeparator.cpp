#include "GUIPopupMenuSeparator.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIPopupMenuSeparator*, GUISystem*, dl_uint);

	GUIPopupMenuSeparator::GUIPopupMenuSeparator(GUISystem* pSystem, dl_uint id)
	{
		CALL(Constructor_t, 0x5577f0, this, pSystem, id);
	}

	DLRF::DLRuntimeClass* GUIPopupMenuSeparator::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5577a0, this);
	}

	GUIPopupMenuSeparator::~GUIPopupMenuSeparator()
	{
		CALL(Destructor_t, 0x557a60, this);
	}

	void GUIPopupMenuSeparator::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x557880, this, gc);
	}
}