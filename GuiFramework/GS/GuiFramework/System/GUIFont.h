#pragma once
#include "GUIObject.h"
#include "TGUISharedString.inl"

namespace GuiFramework
{
	class GUITweakerDialog;

	class GUIFont : public GUIObject
	{
		typedef GUIFont ThisClass;
		typedef GUIObject SuperClass;
	public:
		GUIFont();

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIFont() override;
		virtual void OnDelete() override {}

		DLMT::DL_COLOR_32 GetColor() const { return m_color; }
		DLMT::DL_VECTOR2 GetSize() const { return m_size; }
		DLMT::DL_VECTOR2 GetShadowOffset() const { return m_shadowOffset; }
		dl_bool HasShadow() const { return m_hasShadow; }
		dl_bool IsBold() const { return m_isBold; }
		dl_uchar GetHorizontalAlign() const { return m_horizontalAlign; }
		dl_uchar GetVerticalAlign() const { return m_verticalAlign; }
		dl_uint GetFontId() const { return m_fontId; }
		dl_uint GetHeight() const { return m_height; }
		dl_uint GetDefaultHeight() const { return m_defaultHeight; }

		void SetColor(DLMT::DL_COLOR_32 color) { m_color = color; }
		void SetSize(DLMT::DL_VECTOR2 size) { m_size = size; }
		void SetShadowOffset(DLMT::DL_VECTOR2 offset) { m_shadowOffset = offset; }
		void SetHasShadow(dl_bool hasShadow) { m_hasShadow = hasShadow; }
		void SetIsBold(dl_bool isBold) { m_isBold = isBold; }
		void SetHorizontalAlign(dl_uchar align) { m_horizontalAlign = align; }
		void SetVerticalAlign(dl_uchar align) { m_verticalAlign = align; }
		void SetFontId(dl_int fontId) { m_fontId = fontId; }
		void SetHeight(dl_uint height) { m_height = height; }
		void SetDefaultHeight(dl_uint defaultHeight) { m_defaultHeight = defaultHeight; }

		void CreateTweaker(TGUISharedString<dl_wchar>& title, GUITweakerDialog* pWnd);

	private:
		DLMT::DL_COLOR_32 m_color;
		DLMT::DL_VECTOR2 m_size;
		DLMT::DL_VECTOR2 m_shadowOffset;
		dl_bool m_hasShadow;
		dl_bool m_isBold;
		dl_uchar m_horizontalAlign;
		dl_uchar m_verticalAlign;
		dl_int m_fontId;
		dl_int m_height;
		dl_int m_defaultHeight;
	};
}
