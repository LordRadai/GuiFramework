#pragma once
#include "GUILayoutItem.h"
#include "GuiFramework/System/TGUISize.inl"
#include "GuiFramework/System/TGUIObjectPtr.inl"

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
		virtual dl_uint OnOwnerSizeChanged(const TGUI_SIZE<int>& size) { return false; }
		virtual dl_uint AutoAdd(GUIWindowBase* pWindow) { return false; }
		virtual dl_uint AutoRemove(GUIWindowBase* pWindow) { return false; }

		typedef dl_uint(_fastcall* OnOwnerSizeChanged_t)(GUILayouter*, const TGUI_SIZE<int>&);
		typedef dl_uint(_fastcall* AutoAdd_t)(GUILayouter*, GUIWindowBase*);
		typedef dl_uint(_fastcall* AutoRemove_t)(GUILayouter*, GUIWindowBase*);

	protected:
		TGUIObjectPtr<GUIWidget> m_pOwner;
		dl_pointer m_pVar18;
		TGUIObjectPtr<GUISystem> m_pGUISystem;
		Rect16 m_geometry;
		dl_uint16 m_uVar30;
		dl_uint16 m_uVar32;
		dl_uint16 m_uVar34;
		dl_uint16 m_uVar36;
		dl_uint16 m_uVar38;
	};
}