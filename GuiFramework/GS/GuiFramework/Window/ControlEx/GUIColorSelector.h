#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Control/GUIEditBox.h"

namespace GuiFramework
{
	class GUIColorSelector : public GUIWidget
	{
		typedef GUIColorSelector ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUIColorSelector() {}
		GUIColorSelector(TGUISharedString<dl_wchar> label);
		GUIColorSelector(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createWindow);
		GUIColorSelector(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIColorSelector() override;
		virtual void OnDelete() override;
		virtual dl_uint IsMoveChild() const override { return false; }
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnRButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnCommand(unsigned int cmdId) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnNcRender(GraphicsContext& gc) const override;
		virtual void OnVirtualInput(const VirtualInput& input) const override;

		void SetFloatColor(const DLMT::DL_VECTOR4& color, dl_float32 param_2);
		void SetIntColor(const DLMT::DL_COLOR_32 color);
		void SetU8Color(const DLMT2::DL_COLOR_U8 color);
		void SetHDRColor(dl_pointer color);

		void GetIntColor(DLMT::DL_COLOR_32& outColor) const;
		void GetFloatColor(DLMT::DL_VECTOR4& outColor) const;
		void GetU8Color(DLMT2::DL_COLOR_U8& outColor) const;
		void GetHDRColor(dl_pointer outColor) const;
	protected:
		Rect16 m_rect110;
		Rect16 m_rect118;
		Rect16 m_rect120;
		Rect16 m_rect128;
		Rect16 m_rect130;
		Rect16 m_rect138;
		Rect16 m_rect140;
		Rect16 m_rect148;
		Rect16 m_rect150;
		Rect16 m_rect158;
		Rect16 m_rect160;
		Rect16 m_rect168;
		Rect16 m_rect170;
		Rect16 m_rect178;
		Rect16 m_rect180;
		Rect16 m_rect188;
		GUIEditBox* m_pEditBoxes[5];
		DLMT::DL_VECTOR3 m_hsv;
		DLMT::DL_VECTOR4 m_rgb;
		dl_float32 m_fVar1D4;
		dl_uint8 m_lumLimit;
		dl_uint8 m_alphaLimit;
		dl_uint8 m_iVar1DA;
		dl_int m_colorDisplayMode;
		dl_int m_displayDataType;
		dl_int m_alphaDisplayDataType;
		dl_int m_iVar1E8;
	};
}