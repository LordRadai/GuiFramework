#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GUIListViewItem.h"

namespace GuiFramework
{
	class GUIListView : public GUIWidget
	{
		typedef GUIListView ThisClass;
		typedef GUIWidget SuperClass;
	public:
		struct Column
		{
			TGUISharedString<dl_wchar> Label;
			dl_uint16 Width;
			dl_uint16 Index;
			dl_int iVar14;

			Column(TGUISharedString<dl_wchar> label, dl_uint16 width, dl_uint16 index) : Label(label), Width(width), Index(index), iVar14(0) {}

			void operator=(const Column& other)
			{
				Label = other.Label;
				Width = other.Width;
				Index = other.Index;
				iVar14 = other.iVar14;
			}
		};

		GUIListView() {}
		GUIListView(TGUISharedString<dl_wchar> label);
		GUIListView(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createWindow);
		GUIListView(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIListView() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnRButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDblClk(const MouseEvent& event) override;
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnKeyDown(const KeyEvent& input) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnClose() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnItemDblClk(dl_int itemIndex) {}
		virtual void OnItemClick(dl_int itemIndex) {}
		virtual void OnItemRClick(dl_int itemIndex) {}

		GUIListViewItem* AddItem(TGUISharedString<dl_wchar> label, dl_uint id);
		dl_bool AddColumn(TGUISharedString<dl_wchar> label, dl_uint16 id, dl_uint size, dl_int param_4);

		typedef void(__fastcall* OnItemDblClk_t)(GUIListView*, dl_int);
		typedef void(__fastcall* OnItemClick_t)(GUIListView*, dl_int);
		typedef void(__fastcall* OnItemRClick_t)(GUIListView*, dl_int);
	protected:
		DLUT::DLVector<GUIListViewItem*> m_items;
		DLUT::DLVector<Column> m_columns;
		dl_int16 m_textHeight;
		dl_int16 m_lineHeight;
		dl_int16 m_headerHeight;
		dl_int16 m_tableWidth;
		dl_bool m_bLButtonDown;
		dl_int16 m_hoveredColumnIndex;
		dl_int16 m_lastResizeColumnWidth;
		dl_int m_lastResizeMouseX;
		dl_int m_lastResizeMouseY;
		dl_int m_selectedItem;
		dl_int m_flags;
	};
}