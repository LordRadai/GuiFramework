#include "GUIEditBox.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(const GUIEditBox*, TGUISharedString<dl_wchar>);
	typedef void(_fastcall* ConstructorWithCreateParams_t)(const GUIEditBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(_fastcall* ConstructorWithNumLines_t)(const GUIEditBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);
	
	typedef void(_fastcall* CreateEasy_t)(GUIEditBox*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);
	typedef dl_uint(_fastcall* SetEditText_t)(GUIEditBox*, const dl_wchar*, dl_uint);

	GUIEditBox::GUIEditBox(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x532640, this, label);
	}

	GUIEditBox::GUIEditBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams)
	{
		CALL(ConstructorWithCreateParams_t, 0x532700, this, pParent, label, createParams);
	}

	GUIEditBox::GUIEditBox(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint numLines, dl_uint flags)
	{
		CALL(ConstructorWithNumLines_t, 0x5327d0, this, pParent, label, numLines, flags);
	}

	DLRF::DLRuntimeClass* GUIEditBox::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5325f0, this);
	}

	GUIEditBox::~GUIEditBox()
	{
		CALL(Destructor_t, 0x536350, this);
	}

	void GUIEditBox::OnDelete()
	{
		CALL(OnDelete_t, 0x5341a0, this);
	}

	dl_uint GUIEditBox::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x534b60, this, event);
	}

	dl_uint GUIEditBox::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x5341f0, this, event);
	}

	dl_uint GUIEditBox::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x534350, this, event);
	}

	dl_uint GUIEditBox::OnRButtonDown(const MouseEvent& event)
	{
		return CALL(OnRButtonDown_t, 0x5343b0, this, event);
	}

	dl_uint GUIEditBox::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x534ca0, this, event);
	}

	dl_uint GUIEditBox::OnCommand(dl_uint commandID)
	{
		return CALL(OnCommand_t, 0x535170, this, commandID);
	}

	dl_uint GUIEditBox::OnSetFocus()
	{
		return CALL(OnSetFocus_t, 0x5350c0, this);
	}

	dl_uint GUIEditBox::OnKillFocus()
	{
		return CALL(OnKillFocus_t, 0x5350f0, this);
	}

	dl_uint GUIEditBox::OnKeyDown(const KeyEvent& input)
	{
		return CALL(OnKeyDown_t, 0x534f50, this, input);
	}

	dl_uint GUIEditBox::OnKeyUp(const KeyEvent& input)
	{
		return CALL(OnKeyUp_t, 0x535080, this, input);
	}

	dl_uint GUIEditBox::OnChar(const KeyEvent& input)
	{
		return CALL(OnChar_t, 0x534d00, this, input);
	}

	dl_uint GUIEditBox::OnSize()
	{
		return CALL(OnSize_t, 0x535140, this);
	}

	dl_uint GUIEditBox::OnCreate()
	{
		return CALL(OnCreate_t, 0x532de0, this);
	}

	void GUIEditBox::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5330d0, this, gc);
	}

	void GUIEditBox::CreateEasy(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint numLines, dl_uint flags)
	{
		CALL(CreateEasy_t, 0x532940, this, pParent, label, numLines, flags);
	}

	dl_uint GUIEditBox::SetEditText(const dl_wchar* text, dl_uint numLines)
	{
		return CALL(SetEditText_t, 0x532c70, this, text, numLines);
	}
}