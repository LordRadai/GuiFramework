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

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	protected:
		TGUIObjectPtr<GUIWindowBase> m_pWindow;
		TGUIObjectPtr<GUISystem> m_pSystem;
	};
}
