#include "GUISlider.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUISlider*, TGUISharedString<dl_wchar>);
	typedef void(_fastcall* ConstructorWithCreateParams_t)(GUISlider*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(_fastcall* ConstructorWithFlags_t)(GUISlider*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	typedef void(_fastcall* SetPos_t)(GUISlider*, dl_int, dl_uint);
	typedef void(_fastcall* SetRange_t)(GUISlider*, dl_int, dl_int);

	GUISlider::GUISlider(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5976c0, this, label);
	}

	GUISlider::GUISlider(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams)
	{
		CALL(ConstructorWithCreateParams_t, 0x597730, this, pParent, label, createParams);
	}

	GUISlider::GUISlider(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorWithFlags_t, 0x5977c0, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUISlider::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x597670, this);
	}

	GUISlider::~GUISlider()
	{
		CALL(Destructor_t, 0x599590, this);
	}

	void GUISlider::OnDelete()
	{
		CALL(OnDelete_t, 0x598150, this);
	}

	dl_uint GUISlider::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5983f0, this, event);
	}

	dl_uint GUISlider::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x598170, this, event);
	}

	dl_uint GUISlider::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x598390, this, event);
	}

	dl_uint GUISlider::OnMouseLeave()
	{
		return CALL(OnMouseLeave_t, 0x598740, this);
	}

	dl_uint GUISlider::OnSize()
	{
		return CALL(OnSize_t, 0x5987b0, this);
	}

	dl_uint GUISlider::OnCreate()
	{
		return CALL(OnCreate_t, 0x598120, this);
	}

	dl_uint GUISlider::OnPreCreate(const _GUI_CREATE_WINDOW& createParams)
	{
		return CALL(OnPreCreate_t, 0x598770, this, createParams);
	}

	void GUISlider::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x597fb0, this, gc);
	}

	void GUISlider::SetPos(dl_int pos, dl_uint param_2)
	{
		CALL(SetPos_t, 0x597d60, this, pos, param_2);
	}

	void GUISlider::SetRange(dl_int min, dl_int max)
	{
		CALL(SetRange_t, 0x597b00, this, min, max);
	}
}