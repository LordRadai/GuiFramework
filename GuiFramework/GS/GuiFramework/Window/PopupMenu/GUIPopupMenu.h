#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GUIPopupMenuItem.h"

namespace GuiFramework
{
	class GUIPopupMenuNode;

	class GUIPopupMenu : public GUIWidget
	{
		typedef GUIPopupMenu ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUIPopupMenu() {}
		GUIPopupMenu(GUIPopupMenuNode* pNode);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIPopupMenu() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnMouseLeave() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;

		GUIPopupMenu* GetRootPopup();
		dl_bool Create(GUIWindowBase* pParent, GUIWindowBase* param_2, const Rect& pos);
		void CreateSubMenu(GUIPopupMenuNode* pNode, const Rect& pos);
	protected:
		void _BuildItemInfoVector();

		GUIWidget* m_pOwner;
		GUIPopupMenuNode* m_pNode;
		GUIPopupMenu* m_pParentPopup;
		dl_uint m_iVar128;
		dl_uint m_iVar12C;
		DLUT::DLVector<TGUIObjectPtr<GUIPopupMenuItem>> m_items;
		dl_uint m_selectedItemIndex;
		dl_uint m_iVar154;
	};
}
