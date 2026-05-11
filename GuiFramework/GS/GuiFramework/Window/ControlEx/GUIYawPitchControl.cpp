#include "GUIYawPitchControl.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIYawPitchControl*, TGUISharedString<dl_wchar>);
	typedef void(_fastcall* ConstructorEx_t)(GUIYawPitchControl*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	typedef dl_float32(_fastcall* GetAngle_t)(const GUIYawPitchControl*);

	GUIYawPitchControl::GUIYawPitchControl(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5de850, this, label);
	}

	GUIYawPitchControl::GUIYawPitchControl(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorEx_t, 0x5de8f0, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUIYawPitchControl::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5de800, this);
	}

	GUIYawPitchControl::~GUIYawPitchControl()
	{
		CALL(Destructor_t, 0x5e0f70, this);
	}

	void GUIYawPitchControl::OnDelete()
	{
		CALL(OnDelete_t, 0x5dfa40, this);
	}

	dl_uint GUIYawPitchControl::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5e0450, this, event);
	}

	dl_uint GUIYawPitchControl::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x5e02f0, this, event);
	}

	dl_uint GUIYawPitchControl::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x5e03f0, this, event);
	}

	dl_uint GUIYawPitchControl::OnSize()
	{
		return CALL(OnSize_t, 0x5e02c0, this);
	}

	dl_uint GUIYawPitchControl::OnCreate()
	{
		return CALL(OnCreate_t, 0x5df3b0, this);
	}

	void GUIYawPitchControl::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5dfa90, this, gc);
	}

	dl_float32 GUIYawPitchControl::GetYaw() const
	{
		return CALL(GetAngle_t, 0x5e04a0, this);
	}

	dl_float32 GUIYawPitchControl::GetPitch() const
	{
		return CALL(GetAngle_t, 0x5e0500, this);
	}
}