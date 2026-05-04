#pragma once
#include "GuiFramework/Window/Control/GUIEditBox.h"
#include "GuiFramework/Window/Control/GUIRangeDataBase.h"

namespace GuiFramework
{
	class GUINumericEditBox : public GUIEditBox
	{
		typedef GUINumericEditBox ThisClass;
		typedef GUIEditBox SuperClass;
	public:
		enum NumericEditBoxFlags : dl_uint
		{
		};

		GUINumericEditBox() {}
		GUINumericEditBox(GUIRangeDataBase* pRangeData, TGUISharedString<dl_wchar> label);
		GUINumericEditBox(GUIWindowBase* pParent, GUIRangeDataBase* pRangeData, TGUISharedString<dl_wchar> label, dl_uint flags);
		GUINumericEditBox(GUIWindowBase* pParent, GUIRangeDataBase* pRangeData, TGUISharedString<dl_wchar> label, dl_uint numLines, dl_uint flags);

		DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUINumericEditBox() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnRButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnKillFocus() override;
		virtual dl_uint OnKeyDown(const KeyEvent& input) override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnEditChanged() override;
		virtual void OnReturnPressed() override;
	protected:
		dl_int m_iVar140;
		dl_int m_iVar144;
		TGUIObjectPtr<GUIRangeDataBase> m_pRangeData;
		dl_uint m_flags;
	};
}
