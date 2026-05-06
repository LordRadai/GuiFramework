#include "GUIColorSelector.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIColorSelector*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* ConstructorWithCreate_t)(GUIColorSelector*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(__fastcall* ConstructorWithFlags_t)(GUIColorSelector*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	typedef void(__fastcall* SetFloatColor_t)(GUIColorSelector*, const DLMT::DL_VECTOR4&, dl_float32);
	typedef void(__fastcall* SetIntColor_t)(GUIColorSelector*, const DLMT::DL_COLOR_32);
	typedef void(__fastcall* SetU8Color_t)(GUIColorSelector*, const DLMT2::DL_COLOR_U8);
	typedef void(__fastcall* SetHDRColor_t)(GUIColorSelector*, dl_pointer);

	typedef void(__fastcall* GetIntColor_t)(const GUIColorSelector*, DLMT::DL_COLOR_32&);
	typedef void(__fastcall* GetFloatColor_t)(const GUIColorSelector*, DLMT::DL_VECTOR4&);
	typedef void(__fastcall* GetU8Color_t)(const GUIColorSelector*, DLMT2::DL_COLOR_U8&);
	typedef void(__fastcall* GetHDRColor_t)(const GUIColorSelector*, dl_pointer);

	GUIColorSelector::GUIColorSelector(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5d3da0, this, label);
	}

	GUIColorSelector::GUIColorSelector(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createWindow)
	{
		CALL(ConstructorWithCreate_t, 0x5d3f20, this, pParent, label, createWindow);
	}

	GUIColorSelector::GUIColorSelector(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorWithFlags_t, 0x5d40d0, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUIColorSelector::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5d3d50, this);
	}

	GUIColorSelector::~GUIColorSelector()
	{
		CALL(Destructor_t, 0x5dd610, this);
	}

	void GUIColorSelector::OnDelete()
	{
		CALL(OnDelete_t, 0x5d55b0, this);
	}

	dl_uint GUIColorSelector::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5d5a70, this, event);
	}

	dl_uint GUIColorSelector::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x5d5ad0, this, event);
	}

	dl_uint GUIColorSelector::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x5d5c70, this, event);
	}

	dl_uint GUIColorSelector::OnRButtonDown(const MouseEvent& event)
	{
		return CALL(OnRButtonDown_t, 0x5d5cd0, this, event);
	}

	dl_uint GUIColorSelector::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x5d7320, this, input);
	}

	dl_uint GUIColorSelector::OnCommand(unsigned int cmdId)
	{
		return CALL(OnCommand_t, 0x5d7180, this, cmdId);
	}

	dl_uint GUIColorSelector::OnSize()
	{
		return CALL(OnSize_t, 0x5d5a40, this);
	}

	dl_uint GUIColorSelector::OnCreate()
	{
		return CALL(OnCreate_t, 0x5d5170, this);
	}

	void GUIColorSelector::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5d5610, this, gc);
	}

	void GUIColorSelector::OnNcRender(GraphicsContext& gc) const
	{
		CALL(OnNcRender_t, 0x5d5790, this, gc);
	}

	void GUIColorSelector::OnVirtualInput(const VirtualInput& input) const
	{
		CALL(OnVirtualInput_Const_t, 0x5d7ca0, this, input);
	}

	void GUIColorSelector::SetFloatColor(const DLMT::DL_VECTOR4& color, dl_float32 param_2)
	{
		CALL(SetFloatColor_t, 0x5d47c0, this, color, param_2);
	}

	void GUIColorSelector::SetIntColor(const DLMT::DL_COLOR_32 color)
	{
		CALL(SetIntColor_t, 0x5d4600, this, color);
	}

	void GUIColorSelector::SetU8Color(const DLMT2::DL_COLOR_U8 color)
	{
		CALL(SetU8Color_t, 0x5d4710, this, color);
	}

	void GUIColorSelector::SetHDRColor(dl_pointer color)
	{
		throw std::runtime_error("SetHDRColor is not implemented yet");
	}

	void GUIColorSelector::GetIntColor(DLMT::DL_COLOR_32& outColor) const
	{
		CALL(GetIntColor_t, 0x5d4440, this, outColor);
	}

	void GUIColorSelector::GetFloatColor(DLMT::DL_VECTOR4& outColor) const
	{
		CALL(GetFloatColor_t, 0x5d4550, this, outColor);
	}

	void GUIColorSelector::GetU8Color(DLMT2::DL_COLOR_U8& outColor) const
	{
		CALL(GetU8Color_t, 0x5d44e0, this, outColor);
	}

	void GUIColorSelector::GetHDRColor(dl_pointer outColor) const
	{
		throw std::runtime_error("GetHDRColor is not implemented yet");
	}
}