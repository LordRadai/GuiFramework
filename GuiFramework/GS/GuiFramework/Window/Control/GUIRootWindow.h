#pragma once
#include "GuiFramework/Window/GUIWidget.h"

namespace GuiFramework
{
	class GUIRootWindow : public GUIWidget
	{
		typedef GUIRootWindow ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUIRootWindow() {}
		GUIRootWindow(TGUISharedString<dl_wchar>& label);

		virtual ~GUIRootWindow() override;
		virtual void OnRender(GraphicsContext& gc) const override {}
		virtual void OnRenderWindow(GraphicsContext& gc) const override {}
		
	protected:
	};
}