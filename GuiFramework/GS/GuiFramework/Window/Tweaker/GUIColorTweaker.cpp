#include "GUIColorTweaker.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIColorTweaker*, GUIWidget*, TGUISharedString<dl_wchar>, dl_uint);

	typedef void(__fastcall* SetFloatColor_t)(GUIColorTweaker*, const DLMT::DL_VECTOR4&);
	typedef void(__fastcall* SetIntColor_t)(GUIColorTweaker*, const DLMT::DL_COLOR_32&);
	typedef void(__fastcall* SetU8Color_t)(GUIColorTweaker*, const DLMT2::DL_COLOR_U8&);
	typedef void(__fastcall* SetHDRColor_t)(GUIColorTweaker*, dl_pointer);

	typedef void(__fastcall* GetFloatColor_t)(const GUIColorTweaker*, DLMT::DL_VECTOR4&);
	typedef void(__fastcall* GetIntColor_t)(const GUIColorTweaker*, DLMT::DL_COLOR_32&);
	typedef void(__fastcall* GetU8Color_t)(const GUIColorTweaker*, DLMT2::DL_COLOR_U8&);
	typedef void(__fastcall* GetHDRColor_t)(const GUIColorTweaker*, dl_pointer);

	GUIColorTweaker::GUIColorTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label, dl_uint flags)
	{
		CALL(Constructor_t, 0x5b0da0, this, pParent, label, flags);
	}

	DLRF::DLRuntimeClass* GUIColorTweaker::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5b0d50, this);
	}

	GUIColorTweaker::~GUIColorTweaker()
	{
		CALL(Destructor_t, 0x5b1c20, this);
	}

	void GUIColorTweaker::OnDelete()
	{
		CALL(OnDelete_t, 0x5b1210, this);
	}

	void GUIColorTweaker::Update(dl_float32 dt)
	{
		CALL(Update_t, 0x5b1990, this, dt);
	}

	void GUIColorTweaker::Close()
	{
		CALL(Close_t, 0x5b11c0, this);
	}

	void GUIColorTweaker::SetColor(const DLMT::DL_VECTOR4& color)
	{
		CALL(SetFloatColor_t, 0x5b1300, this, color);
	}

	void GUIColorTweaker::SetColor(const DLMT::DL_COLOR_32 color)
	{
		CALL(SetIntColor_t, 0x5b1240, this, color);
	}

	void GUIColorTweaker::SetColor(const DLMT2::DL_COLOR_U8 color)
	{
		CALL(SetU8Color_t, 0x5b12a0, this, color);
	}

	void GUIColorTweaker::SetColor(dl_pointer color)
	{
		throw std::runtime_error("SetColor with dl_pointer is not implemented yet");
	}

	void GUIColorTweaker::GetFloatColor(DLMT::DL_VECTOR4& outColor) const
	{
		CALL(GetFloatColor_t, 0x5b16d0, this, outColor);
	}

	void GUIColorTweaker::GetIntColor(DLMT::DL_COLOR_32& outColor) const
	{
		CALL(GetIntColor_t, 0x5b15c0, this, outColor);
	}

	void GUIColorTweaker::GetU8Color(DLMT2::DL_COLOR_U8& outColor) const
	{
		CALL(GetU8Color_t, 0x5b1640, this, outColor);
	}

	void GUIColorTweaker::GetHDRColor(dl_pointer outColor) const
	{
		throw std::runtime_error("GetHDRColor is not implemented yet");
	}
}