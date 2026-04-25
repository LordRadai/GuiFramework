#pragma once
#include "GUIPopupMenuItem.h"

namespace GuiFramework
{
	class GUIPopupMenuSeparator : public GUIPopupMenuItem
	{
	public:
		GUIPopupMenuSeparator() {}
		GUIPopupMenuSeparator(GUISystem* pSystem, dl_uint id);

		DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIPopupMenuSeparator();
		virtual void OnRender(GraphicsContext& gc) const override;
	};
}