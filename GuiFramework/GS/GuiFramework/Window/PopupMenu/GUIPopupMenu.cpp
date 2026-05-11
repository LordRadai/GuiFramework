#include "GUIPopupMenu.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIPopupMenu*, GUIPopupMenuNode*);

	typedef void(_fastcall* BuildItemInfoVector_t)(GUIPopupMenu*);
	typedef GUIPopupMenu*(_fastcall* GetRootPopup_t)(const GUIPopupMenu*);
	typedef dl_bool(_fastcall* Create_t)(GUIPopupMenu*, GUIWindowBase*, GUIWindowBase*, const Rect&);
	typedef void(_fastcall* CreateSubMenu_t)(GUIPopupMenu*, GUIPopupMenuNode*, const Rect&);
	typedef void(_fastcall* FinishPopupMenu_t)(GUIPopupMenu*, GUIPopupMenuItem*);
	typedef void(_fastcall* Close_t)(GUIPopupMenu*, GUIPopupMenuItem*);

	GUIPopupMenu::GUIPopupMenu(GUIPopupMenuNode* pNode)
	{
		CALL(Constructor_t, 0x5587e0, this, pNode);
	}

	DLRF::DLRuntimeClass* GUIPopupMenu::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x558790, this);
	}

	GUIPopupMenu::~GUIPopupMenu()
	{
		CALL(Destructor_t, 0x55b1a0, this);
	}

	void GUIPopupMenu::OnDelete()
	{
		CALL(OnDelete_t, 0x5591d0, this);
	}

	dl_uint GUIPopupMenu::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5598f0, this, event);
	}

	dl_uint GUIPopupMenu::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x559b70, this, event);
	}

	dl_uint GUIPopupMenu::OnMouseLeave()
	{
		return CALL(OnMouseLeave_t, 0x559b30, this);
	}

	dl_uint GUIPopupMenu::OnCreate()
	{
		return CALL(OnCreate_t, 0x55a3e0, this);
	}

	void GUIPopupMenu::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x559310, this, gc);
	}

	GUIPopupMenu* GUIPopupMenu::GetRootPopup()
	{
		return CALL(GetRootPopup_t, 0x55a4d0, this);
	}

	dl_bool GUIPopupMenu::Create(GUIWindowBase* pParent, GUIWindowBase* param_2, const Rect& pos)
	{
		return CALL(Create_t, 0x5589f0, this, pParent, param_2, pos);
	}

	void GUIPopupMenu::CreateSubMenu(GUIPopupMenuNode* pNode, const Rect& pos)
	{
		CALL(CreateSubMenu_t, 0x558ec0, this, pNode, pos);
	}

	void GUIPopupMenu::FinishPopupMenu(GUIPopupMenuItem* pItem)
	{
		CALL(FinishPopupMenu_t, 0x558e90, this, pItem);
	}

	void GUIPopupMenu::Close(GUIPopupMenuItem* pItem)
	{
		CALL(Close_t, 0x55a360, this, pItem);
	}

	void GUIPopupMenu::_BuildItemInfoVector()
	{
		CALL(BuildItemInfoVector_t, 0x559cf0, this);
	}
}
