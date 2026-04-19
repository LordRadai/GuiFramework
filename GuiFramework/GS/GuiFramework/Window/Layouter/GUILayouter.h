#pragma once
#include "GUILayoutItem.h"
#include "GuiFramework/System/TGUISize.inl"

namespace GuiFramework
{
	class GUIWindowBase;
	class GUIWidget;

	class GUILayouter : public GUILayoutItem
	{
		typedef GUILayouter ThisClass;
		typedef GUILayoutItem SuperClass;

	public:
		GUILayouter(GUIWidget* pOwner);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUILayouter() override;
		virtual void OnDelete() override;
		virtual GUISystem* GetGUISystem() const override;
		virtual Rect GetMaxSize() const override;
		virtual Rect GetMinSize() const override;
		virtual Rect GetIdealSize() const override;
		virtual void SetGeometry(const Rect& rect) override;
		virtual Rect GetGeometry() const override;
		virtual dl_bool IsOwn(GUIObject* pObject) const override;
		virtual void OnOwnerSizeChanged(TGUI_SIZE<int>& size) {}
		virtual void AutoAdd(GUIWindowBase* pWindow) {}
		virtual void AutoRemove(GUIWindowBase* pWindow) {}

		typedef void(__fastcall* OnOwnerSizeChanged_t)(GUILayouter*, TGUI_SIZE<int>&);
		typedef void(__fastcall* AutoAdd_t)(GUILayouter*, GUIWindowBase*);
		typedef void(__fastcall* AutoRemove_t)(GUILayouter*, GUIWindowBase*);
	};
}