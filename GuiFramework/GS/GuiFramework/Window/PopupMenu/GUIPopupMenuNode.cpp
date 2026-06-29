#include "GUIPopupMenuNode.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIPopupMenuNode*, GUISystem*, TGUISharedString<wchar_t>, dl_uint);

	typedef GUIPopupMenuItem*(_fastcall* AddItem_t)(GUIPopupMenuNode*, GUIPopupMenuItem*, dl_uint);
	typedef GUIPopupMenuString*(_fastcall* AddString_t)(GUIPopupMenuNode*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);
	typedef GUIPopupMenuSeparator*(_fastcall* AddSeparator_t)(GUIPopupMenuNode*, dl_uint, dl_uint);
	typedef GUIPopupMenuNode*(_fastcall* AddSubNode_t)(GUIPopupMenuNode*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);
	typedef void(_fastcall* SetItemFlags_t)(GUIPopupMenuNode*, dl_uint, dl_uint, dl_uint);

	GUIPopupMenuNode::GUIPopupMenuNode(GUISystem* pSystem, TGUISharedString<wchar_t> label, dl_uint id)
	{
		CALL(Constructor_t, 0x524b50, this, pSystem, label, id);
	}

	DLRF::DLRuntimeClass* GUIPopupMenuNode::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x524b00, this);
	}

	GUIPopupMenuNode::~GUIPopupMenuNode()
	{
		CALL(Destructor_t, 0x5261f0, this);
	}

	void GUIPopupMenuNode::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x525590, this, gc);
	}

	dl_uint GUIPopupMenuNode::OnLButtonDown(const MouseEvent& event, const Rect& rect)
	{
		return CALL(OnLButtonDown_t, 0x5256d0, this, event, rect);
	}

	GUIPopupMenuItem* GUIPopupMenuNode::AddItem(GUIPopupMenuItem* item, dl_uint idx)
	{
		return CALL(AddItem_t, 0x524f70, this, item, idx);
	}

	GUIPopupMenuString* GUIPopupMenuNode::AddString(TGUISharedString<dl_wchar> str, dl_uint id, dl_uint idx)
	{
		return CALL(AddString_t, 0x524c60, this, str, id, idx);
	}

	GUIPopupMenuString* GUIPopupMenuNode::AddCheckBox(TGUISharedString<dl_wchar> str, dl_uint id, dl_bool bChecked, dl_bool bAllowInteraction, dl_uint idx)
	{
		GUIPopupMenuString* pItem = AddString(str, id, idx);

		if (bAllowInteraction)
		{
			if (bChecked)
				this->SetItemFlags(id, GUIPopupMenuNode::STATUS_SELECTABLE | GUIPopupMenuNode::STATUS_CHECKBOX | GUIPopupMenuNode::STATUS_ENABLED, 0);
			else
				this->SetItemFlags(id, GUIPopupMenuNode::STATUS_SELECTABLE | GUIPopupMenuNode::STATUS_CHECKBOX, 0);
		}
		else
		{
			if (bChecked)
				this->SetItemFlags(id, GUIPopupMenuNode::STATUS_CHECKBOX | GUIPopupMenuNode::STATUS_ENABLED, 0);
			else
				this->SetItemFlags(id, GUIPopupMenuNode::STATUS_CHECKBOX, 0);
		}

		return pItem;
	}

	GUIPopupMenuSeparator* GUIPopupMenuNode::AddSeparator(dl_uint id, dl_uint idx)
	{
		return CALL(AddSeparator_t, 0x5250c0, this, id, idx);
	}

	GUIPopupMenuNode* GUIPopupMenuNode::AddSubNode(TGUISharedString<dl_wchar> label, dl_uint id, dl_uint idx)
	{
		return CALL(AddSubNode_t, 0x5251d0, this, label, id, idx);
	}

	void GUIPopupMenuNode::SetItemFlags(dl_uint id, dl_uint setMask, dl_uint clearMask)
	{
		CALL(SetItemFlags_t, 0x525350, this, id, setMask, clearMask);
	}
}