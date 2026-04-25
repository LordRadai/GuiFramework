#include "GUINumericEditBox.h"

namespace GuiFramework
{
	typedef void(__fastcall* ConstructorWithRangeData_t)(const GUINumericEditBox*, GUIRangeDataBase*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* ConstructorWithRangeDataAndFlags_t)(const GUINumericEditBox*, GUIWindowBase*, GUIRangeDataBase*, TGUISharedString<dl_wchar>, dl_uint);
	typedef void(__fastcall* ConstructorWithRangeDataNumLinesAndFlags_t)(const GUINumericEditBox*, GUIWindowBase*, GUIRangeDataBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);
	
	GUINumericEditBox::GUINumericEditBox(GUIRangeDataBase* pRangeData, TGUISharedString<dl_wchar> label)
	{
		CALL(ConstructorWithRangeData_t, 0x599b10, this, pRangeData, label);
	}

	GUINumericEditBox::GUINumericEditBox(GUIWindowBase* pParent, GUIRangeDataBase* pRangeData, TGUISharedString<dl_wchar> label, dl_uint flags)
	{
		CALL(ConstructorWithRangeDataAndFlags_t, 0x599bb0, this, pParent, pRangeData, label, flags);
	}

	GUINumericEditBox::GUINumericEditBox(GUIWindowBase* pParent, GUIRangeDataBase* pRangeData, TGUISharedString<dl_wchar> label, dl_uint numLines, dl_uint flags)
	{
		CALL(ConstructorWithRangeDataNumLinesAndFlags_t, 0x599c70, this, pParent, pRangeData, label, numLines, flags);
	}

	DLRF::DLRuntimeClass* GUINumericEditBox::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x599ac0, this);
	}

	GUINumericEditBox::~GUINumericEditBox()
	{
		CALL(Destructor_t, 0x59b9c0, this);
	}

	void GUINumericEditBox::OnDelete()
	{
		CALL(OnDelete_t, 0x59b260, this);
	}

	dl_uint GUINumericEditBox::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x59a990, this, event);
	}

	dl_uint GUINumericEditBox::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x59a630, this, event);
	}

	dl_uint GUINumericEditBox::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x59aed0, this, event);
	}

	dl_uint GUINumericEditBox::OnRButtonDown(const MouseEvent& event)
	{
		return CALL(OnRButtonDown_t, 0x59a940, this, event);
	}

	dl_uint GUINumericEditBox::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x59ae10, this, event);
	}

	dl_uint GUINumericEditBox::OnKillFocus()
	{
		return CALL(OnKillFocus_t, 0x59b200, this);
	}

	dl_uint GUINumericEditBox::OnKeyDown(const KeyEvent& input)
	{
		return CALL(OnKeyDown_t, 0x59b030, this, input);
	}

	dl_uint GUINumericEditBox::OnCreate()
	{
		return CALL(OnCreate_t, 0x59a590, this);
	}

	void GUINumericEditBox::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x59b150, this, gc);
	}

	void GUINumericEditBox::OnEditChanged()
	{
		CALL(OnEditChanged_t, 0x59a040, this);
	}

	void GUINumericEditBox::OnReturnPressed()
	{
		CALL(OnReturnPressed_t, 0x599e30, this);
	}
}