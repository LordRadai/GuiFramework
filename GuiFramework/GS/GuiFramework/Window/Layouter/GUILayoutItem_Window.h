#pragma once
#include "GUILayoutItem.h"
#include "GuiFramework/System/TGUIObjectPtr.inl"

namespace GuiFramework
{
	class GUIWindowBase;
	class GUISystem;

	class GUILayoutItem_Window : public GUILayoutItem
	{
		typedef GUILayoutItem_Window ThisClass;
		typedef GUILayoutItem SuperClass;

	public:
		GUILayoutItem_Window(GUIWindowBase* pWindow);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUILayoutItem_Window() override;
		virtual void OnDelete() override;
		virtual GUISystem* GetGUISystem() const override;
		virtual Rect GetMaxSize() const override;
		virtual Rect GetMinSize() const override;
		virtual Rect GetIdealSize() const override;
		virtual void SetGeometry(const Rect& rect) override;
		virtual Rect GetGeometry() const override;
		virtual dl_bool IsOwn(GUIObject* pObject) const override;

	private:
		TGUIObjectPtr<GUIWindowBase> m_pWindow;
		TGUIObjectPtr<GUISystem> m_pSystem;
	};
}
