#include "GUIPopupMenuItem.h"

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIPopupMenuItem*, GUISystem*, dl_uint);

	GUIPopupMenuItem::GUIPopupMenuItem(GUISystem* pGUISystem, dl_uint id)
	{
		CALL(Constructor_t, 0x5574c0, this, pGUISystem, id);
	}

	GUIPopupMenuItem::~GUIPopupMenuItem()
	{
		CALL(Destructor_t, 0x55b1c0, this);
	}

	void GUIPopupMenuItem::OnRenderIcon(GraphicsContext& gc) const
	{
		CALL(OnRenderIcon_t, 0x5575c0, this, gc);
	}
}
