#include "GUIPopupMenuNode.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIPopupMenuNode*, GUISystem*, TGUISharedString<wchar_t>, dl_uint);

	typedef GUIPopupMenuItem*(__fastcall* AddItem_t)(GUIPopupMenuNode*, GUIPopupMenuItem*, dl_uint);
	typedef GUIPopupMenuString*(__fastcall* AddString_t)(GUIPopupMenuNode*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);
	typedef GUIPopupMenuSeparator*(__fastcall* AddSeparator_t)(GUIPopupMenuNode*, dl_uint, dl_uint);
	typedef GUIPopupMenuNode*(__fastcall* AddSubNode_t)(GUIPopupMenuNode*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

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

	GUIPopupMenuSeparator* GUIPopupMenuNode::AddSeparator(dl_uint id, dl_uint idx)
	{
		return CALL(AddSeparator_t, 0x5250c0, this, id, idx);
	}

	GUIPopupMenuNode* GUIPopupMenuNode::AddSubNode(TGUISharedString<dl_wchar> label, dl_uint id, dl_uint idx)
	{
		return CALL(AddSubNode_t, 0x5251d0, this, label, id, idx);
	}
}