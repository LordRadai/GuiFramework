#include "GUIRenderImplBase.h"
#include <Call.h>

namespace GuiFramework
{
	GUIRenderImplBase::~GUIRenderImplBase()
	{
		CALL(Destructor_t, 0xc57ae0, this);
	}

	dl_bool GUIRenderImplBase::BeginText(const GUIFont& font, DLMT2::DL_COLOR_U8 color)
	{
		return CALL(BeginTextARGB_t, 0xb679a0, this, font, color);
	}

	void GUIRenderImplBase::SetTextScale(const Point2D& scale)
	{
		CALL(SetTextScale_Point_t, 0xb68830, this, scale);
	}

	void GUIRenderImplBase::SetTextColor(DLMT2::DL_COLOR_U8 color, DLMT2::DL_COLOR_U8 shadowColor)
	{
		CALL(SetTextColorARGB_t, 0xb68790, this, color, shadowColor);
	}

	void GUIRenderImplBase::SetTextAttribute(const GUI_TEXT_ATTRIBUTE& attr, DLMT2::DL_COLOR_U8 color)
	{
		CALL(SetTextAttributeARGB_t, 0xb686a0, this, attr, color);
	}

	void GUIRenderImplBase::SetTextHAlign(dl_uint8 align)
	{
		CALL(SetHAlign_t, 0xc57d10, this, align);
	}

	void GUIRenderImplBase::SetTextVAlign(dl_uint8 align)
	{
		CALL(SetVAlign_t, 0xc57d40, this, align);
	}

	DLGR::DL_FRECT GUIRenderImplBase::GetTextExtent(const DLGR::DL_FRECT& pos, const dl_wchar* text) const
	{
		return CALL(GetTextExtent_Rect_t, 0xc57bd0, this, pos, text);
	}

	DLGR::DL_FRECT GUIRenderImplBase::GetTextExtent(dl_int x, dl_int y, const dl_wchar* text) const
	{
		return CALL(GetTextExtent_Coords_t, 0xc57c20, this, x, y, text);
	}
}