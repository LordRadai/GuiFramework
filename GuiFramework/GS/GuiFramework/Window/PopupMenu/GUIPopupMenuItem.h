#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/System/GUISystem.h"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/GUIMouseEvent.h"
#include "GuiFramework/Render/GUIRenderContext.h"

namespace GuiFramework
{
	class GUIPopupMenuItem : public GUIMsgReceiver
	{
		typedef GUIPopupMenuItem ThisClass;
		typedef GUIMsgReceiver SuperClass;
	public:
		GUIPopupMenuItem() {}
		GUIPopupMenuItem(GUISystem* pGUISystem, dl_uint id);

		virtual ~GUIPopupMenuItem() override;
		virtual dl_uint IsNode() const { return false; }
		virtual void OnRender(GraphicsContext& gc) const {}
		virtual void OnRenderIcon(GraphicsContext& gc) const;
		virtual dl_uint OnLButtonDown(const MouseEvent& event, const Rect& rect) { return false; }

		typedef dl_uint(__fastcall* IsNode_t)(const GUIPopupMenuItem*);
		typedef void(__fastcall* OnRender_t)(const GUIPopupMenuItem*, GraphicsContext&);
		typedef void(__fastcall* OnRenderIcon_t)(const GUIPopupMenuItem*, GraphicsContext&);
		typedef dl_uint(__fastcall* OnLButtonDown_t)(const GUIPopupMenuItem*, const MouseEvent&, const Rect&);
	};
}