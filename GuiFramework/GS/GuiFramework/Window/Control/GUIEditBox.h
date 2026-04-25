#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Util/GUITextEditorUtil.h"

namespace GuiFramework
{
	class GUIEditBox : public GUIWidget
	{
		typedef GUIEditBox ThisClass;
		typedef GUIWidget SuperClass;
	public:
		enum EditBoxFlags : dl_uint
		{
		};

		GUIEditBox() {}
		GUIEditBox(TGUISharedString<dl_wchar> label);
		GUIEditBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams);
		GUIEditBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint numLines, dl_uint flags);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIEditBox() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnRButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnCommand(dl_uint commandID) override;
		virtual dl_uint OnSetFocus() override;
		virtual dl_uint OnKillFocus() override;
		virtual dl_uint OnKeyDown(const KeyEvent& input) override;
		virtual dl_uint OnKeyUp(const KeyEvent& input) override;
		virtual dl_uint OnChar(const KeyEvent& input) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnEditChanged() {}
		virtual void OnReturnPressed() {}

		typedef void(__fastcall* OnEditChanged_t)(GUIEditBox*);
		typedef void(__fastcall* OnReturnPressed_t)(GUIEditBox*);

		void CreateEasy(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint numLines, dl_uint flags);
		dl_uint SetEditText(const dl_wchar* text, dl_uint numLines);
	protected:
		TGUIObjectPtr<GUITextEditorUtil> m_pTextEditorUtil;
		dl_pointer m_pVar118;
		TGUISharedString<dl_wchar> m_backgroundText;
		Rect16 m_rect;
		dl_uint16 m_iVar138;
		dl_uint16 m_iVar13A;
		dl_uint m_flags;
	};
}