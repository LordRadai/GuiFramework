#include "GUIListView.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIListView*, TGUISharedString<dl_wchar>);
	typedef void(_fastcall* ConstructorWithCreateParams_t)(GUIListView*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(_fastcall* ConstructorWithFlags_t)(GUIListView*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	typedef dl_int(_fastcall* AddItem_t)(GUIListView*, TGUISharedString<dl_wchar>, dl_int);
	typedef dl_int(_fastcall* AddItemWithIndex_t)(GUIListView*, GUIListViewItem*, dl_int);
	typedef dl_bool(_fastcall* AddColumn_t)(GUIListView*, TGUISharedString<dl_wchar>, dl_uint16, dl_uint, dl_int);

	typedef dl_bool(_fastcall* SetColumnHeaderLabel_t)(GUIListView*, dl_uint16, TGUISharedString<dl_wchar>);
	typedef dl_bool(_fastcall* SetColumnHeaderWidth_t)(GUIListView*, dl_uint16, dl_uint16);
	typedef void(_fastcall* RemoveAllItem_t)(GUIListView*);
	typedef dl_bool(_fastcall* RemoveItem_t)(GUIListView*, GUIListViewItem*);
	typedef GUIListViewItem*(_fastcall* GetItemFromIndex_t)(const GUIListView*, dl_int);

	GUIListView::GUIListView(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5ca3b0, this, label);
	}

	GUIListView::GUIListView(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createWindow)
	{
		CALL(ConstructorWithCreateParams_t, 0x5ca450, this, pParent, label, createWindow);
	}

	GUIListView::GUIListView(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorWithFlags_t, 0x5ca510, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUIListView::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5ca360, this);
	}

	GUIListView::~GUIListView()
	{
		CALL(Destructor_t, 0x5d12b0, this);
	}

	void GUIListView::OnDelete()
	{
		CALL(OnDelete_t, 0x5cd450, this);
	}

	dl_uint GUIListView::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5ccf90, this, event);
	}

	dl_uint GUIListView::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x5ccb10, this, event);
	}

	dl_uint GUIListView::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x5ccf10, this, event);
	}

	dl_uint GUIListView::OnRButtonDown(const MouseEvent& event)
	{
		return CALL(OnRButtonDown_t, 0x5cccb0, this, event);
	}

	dl_uint GUIListView::OnLButtonDblClk(const MouseEvent& event)
	{
		return CALL(OnLButtonDblClk_t, 0x5ccd60, this, event);
	}

	dl_uint GUIListView::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x5cd140, this, event);
	}

	dl_uint GUIListView::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x5cbfe0, this, input);
	}

	dl_uint GUIListView::OnKeyDown(const KeyEvent& input)
	{
		return CALL(OnKeyDown_t, 0x5cd240, this, input);
	}

	dl_uint GUIListView::OnSize()
	{
		return CALL(OnSize_t, 0x5ccae0, this);
	}

	dl_uint GUIListView::OnCreate()
	{
		return CALL(OnCreate_t, 0x5cc930, this);
	}

	dl_uint GUIListView::OnClose()
	{
		return CALL(OnClose_t, 0x5cd570, this);
	}

	void GUIListView::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5cc3f0, this, gc);
	}

	dl_int GUIListView::AddItem(TGUISharedString<dl_wchar> label, dl_int id)
	{
		return CALL(AddItem_t, 0x5ca7e0, this, label, id);
	}

	dl_int GUIListView::AddItem(GUIListViewItem* pItem, dl_int idx)
	{
		return CALL(AddItemWithIndex_t, 0x5ca910, this, pItem, idx);
	}

	dl_bool GUIListView::AddColumn(TGUISharedString<dl_wchar> label, dl_uint16 id, dl_uint size, dl_int param_4)
	{
		return CALL(AddColumn_t, 0x5ca970, this, label, id, size, param_4);
	}

	dl_bool GUIListView::SetColumnHeaderLabel(dl_uint16 id, TGUISharedString<dl_wchar> label)
	{
		return CALL(SetColumnHeaderLabel_t, 0x5cac70, this, id, label);
	}

	dl_bool GUIListView::SetColumnHeaderWidth(dl_uint16 id, dl_uint16 width)
	{
		return CALL(SetColumnHeaderWidth_t, 0x5cad90, this, id, width);
	}

	GUIListView::Column* GUIListView::GetColumn(dl_uint16 id)
	{
		for (dl_size i = 0; i < m_columns.size(); i++)
		{
			if (m_columns[i].ID == id)
				return &m_columns[i];
		}

		return nullptr;
	}

	void GUIListView::RemoveAllItem()
	{
		CALL(RemoveAllItem_t, 0x5caf40, this);
	}

	dl_bool GUIListView::RemoveItem(GUIListViewItem* pItem)
	{
		return CALL(RemoveItem_t, 0x5caef0, this, pItem);
	}

	dl_bool GUIListView::RemoveItem(dl_uint16 idx)
	{
		if (idx >= m_items.size())
			return false;

		return RemoveItem(m_items[idx].Get());
	}

	GUIListViewItem* GUIListView::GetItemFromIndex(dl_int index) const
	{
		return CALL(GetItemFromIndex_t, 0x5cb270, this, index);
	}

	dl_int GUIListView::GetItemIndex(GUIListViewItem* pItem) const
	{
		for (dl_size i = 0; i < m_items.size(); i++)
		{
			if (m_items[i].Get() == pItem)
				return static_cast<dl_int>(i);
		}

		return -1;
	}
}