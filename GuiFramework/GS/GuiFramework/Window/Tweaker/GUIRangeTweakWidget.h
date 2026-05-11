#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Control/GUISlider.h"
#include "GuiFramework/Window/ControlEx/GUINumericEditBox.h"
#include "GuiFramework/Window/Control/GUIRangeDataBase.h"

namespace GuiFramework
{
	class GUIRangeTweakWidget : public GUIWidget
	{
		typedef GUIRangeTweakWidget ThisClass;
		typedef GUIWidget SuperClass;
	public:

	protected:
		TGUIObjectPtr<GUISlider> m_pSlider;
		TGUIObjectPtr<GUINumericEditBox> m_pEditBox;
		TGUIObjectPtr<GUIRangeDataBase> m_pRangeData;
		dl_uint16 m_iVar128;
	};
}