#include "GUIRenderContext.h"

namespace GuiFramework
{
	typedef GUIRenderContext* (_fastcall* Constructor_t)(GUIRenderContext*, GUIRenderImplBase&);
	typedef GUIRenderContext* (_fastcall* CopyConstructor_t)(GUIRenderContext*, GUIRenderContext&);
	typedef dl_bool(_fastcall* BeginText_t)(GUIRenderContext*, const GUIFont&);
	typedef void(_fastcall* DrawText_t)(GUIRenderContext*, const Rect&, const dl_wchar*);
	typedef void(_fastcall* DrawText_Coords_t)(GUIRenderContext*, dl_int, dl_int, const dl_wchar*);
	typedef void(_fastcall* EndText_t)(GUIRenderContext*);
	typedef void(_fastcall* DrawPrimitive_t)(GUIRenderContext*, GUI_PRIMITIVE_TOPOLOGY, _GUI_VERTEX_ColorTex1*, dl_uint, GUI_BLEND, GUITextureBase*);
	typedef void(_fastcall* DrawSprite_Rect_t)(GUIRenderContext*, const GUI_SPRITE_RECT&, GUI_BLEND, GUITextureBase*, GUI_SHADERTYPE);
	typedef void(_fastcall* DrawSprite_GouraudRect_t)(GUIRenderContext*, const GUI_SPRITE_GOURAUD_RECT&, GUI_BLEND, GUITextureBase*, GUI_SHADERTYPE);
	typedef void(_fastcall* DrawSpriteCube_t)(GUIRenderContext*, const GUI_SPRITE_GOURAUD_RECT&, dl_uint, GUI_BLEND, GUITextureBase*, GUI_SHADERTYPE);
	typedef void(_fastcall* DrawSpriteCubeAllFace_t)(GUIRenderContext*, const GUI_SPRITE_GOURAUD_RECT&, GUI_BLEND, GUITextureBase*, GUI_SHADERTYPE);
	typedef void(_fastcall* DrawEdge_t)(GUIRenderContext*, const Rect&, dl_float32, DLMT::DL_COLOR_32, GUI_BLEND, dl_int);
	typedef void(_fastcall* FillGoraudRect_t)(GUIRenderContext*, const Rect&, const DLMT::DL_COLOR_32*, GUI_BLEND);
	typedef void(_fastcall* FillRect_t)(GUIRenderContext*, const Rect&, DLMT::DL_COLOR_32, GUI_BLEND);
	typedef void(_fastcall* FillSoftRect_t)(GUIRenderContext*, const Rect&, DLMT::DL_COLOR_32, GUI_BLEND);
	typedef void(_fastcall* SetDefaultRenderState_t)(GUIRenderContext*);
	typedef void(_fastcall* SetUnkParameter_t)(GUIRenderContext*, dl_bool);
	typedef void(_fastcall* SetBlendState_t)(GUIRenderContext*, dl_uint);
	typedef void(_fastcall* SetSamplerState_t)(GUIRenderContext*, const GUI_SAMPLER_STATE&);
	typedef void(_fastcall* SetScissorRect_t)(GUIRenderContext*, const Rect&);
	typedef void(_fastcall* SetTextAttribute_t)(GUIRenderContext*, const GUI_TEXT_ATTRIBUTE&);
	typedef void(_fastcall* SetTextColor_t)(GUIRenderContext*, DLMT::DL_COLOR_32);
	typedef void(_fastcall* SetTextHAlign_t)(GUIRenderContext*, dl_uint8);
	typedef void(_fastcall* SetTextVAlign_t)(GUIRenderContext*, dl_uint8);
	typedef void(_fastcall* SetTextScale_t)(GUIRenderContext*, const DLMT::DL_VECTOR2&);

	GUIRenderContext::GUIRenderContext(GUIRenderImplBase& impl)
	{
		CALL(Constructor_t, 0x55dd00, this, impl);
	}

	GUIRenderContext::GUIRenderContext(GUIRenderContext& other)
	{
		CALL(CopyConstructor_t, 0x55dfc0, this, other);
	}

	dl_bool GUIRenderContext::BeginText(const GUIFont& font)
	{
		return CALL(BeginText_t, 0x5615d0, this, font);
	}

	void GUIRenderContext::DrawText(const Rect& pos, const dl_wchar* text)
	{
		CALL(DrawText_t, 0x561710, this, pos, text);
	}

	void GUIRenderContext::DrawText(dl_int x, dl_int y, const dl_wchar* text)
	{
		CALL(DrawText_Coords_t, 0x561660, this, x, y, text);
	}

	void GUIRenderContext::DrawFormatText(dl_int x, dl_int y, const dl_wchar* fmt, ...)
	{
		dl_wchar buffer[1024];

		va_list args;
		va_start(args, fmt);
		vswprintf(buffer, sizeof(buffer) / sizeof(dl_wchar), fmt, args);
		va_end(args);

		DrawText(x, y, buffer);
	}

	void GUIRenderContext::DrawFormatText(const Rect& pos, const dl_wchar* fmt, ...)
	{
		dl_wchar buffer[1024];
		va_list args;
		va_start(args, fmt);
		vswprintf(buffer, sizeof(buffer) / sizeof(dl_wchar), fmt, args);
		va_end(args);

		DrawText(pos, buffer);
	}

	void GUIRenderContext::EndText()
	{
		CALL(EndText_t, 0x561610, this);
	}

	void GUIRenderContext::DrawPrimitive(GUI_PRIMITIVE_TOPOLOGY topology, _GUI_VERTEX_ColorTex1* pVertices, dl_uint vertexCount, GUI_BLEND blendMode, GUITextureBase* pTexture)
	{
		CALL(DrawPrimitive_t, 0x55f810, this, topology, pVertices, vertexCount, blendMode, pTexture);
	}

	void GUIRenderContext::DrawSprite(const GUI_SPRITE_RECT& spriteRect, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType)
	{
		CALL(DrawSprite_Rect_t, 0x55e2e0, this, spriteRect, blendMode, pTexture, shaderType);
	}

	void GUIRenderContext::DrawSprite(const GUI_SPRITE_GOURAUD_RECT& spriteRect, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType)
	{
		CALL(DrawSprite_GouraudRect_t, 0x55e8f0, this, spriteRect, blendMode, pTexture, shaderType);
	}

	void GUIRenderContext::DrawSpriteCube(const GUI_SPRITE_GOURAUD_RECT& spriteRect, dl_uint faceIdx, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType)
	{
		CALL(DrawSpriteCube_t, 0x55ef30, this, spriteRect, faceIdx, blendMode, pTexture, shaderType);
	}

	void GUIRenderContext::DrawSpriteCubeAllFace(const GUI_SPRITE_GOURAUD_RECT& spriteRect, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType)
	{
		CALL(DrawSpriteCubeAllFace_t, 0x55f420, this, spriteRect, blendMode, pTexture, shaderType);
	}

	void GUIRenderContext::DrawEdge(const Rect& rect, dl_float32 thickness, DLMT::DL_COLOR_32 color, GUI_BLEND blendMode, dl_int flags)
	{
		CALL(DrawEdge_t, 0x55f8e0, this, rect, thickness, color, blendMode, flags);
	}

	void GUIRenderContext::FillGoraudRect(const Rect& rect, const DLMT::DL_COLOR_32* col, GUI_BLEND blendMode)
	{
		CALL(FillGoraudRect_t, 0x560880, this, rect, col, blendMode);
	}

	void GUIRenderContext::FillRect(const Rect& rect, DLMT::DL_COLOR_32 color, GUI_BLEND blendMode)
	{
		CALL(FillRect_t, 0x5603a0, this, rect, color, blendMode);
	}

	void GUIRenderContext::FillSoftRect(const Rect& rect, DLMT::DL_COLOR_32 color, GUI_BLEND blendMode)
	{
		CALL(FillSoftRect_t, 0x5610c0, this, rect, color, blendMode);
	}

	void GUIRenderContext::SetDefaultRenderState()
	{
		CALL(SetDefaultRenderState_t, 0x5620f0, this);
	}

	void GUIRenderContext::SetUnkParameter(dl_bool value)
	{
		CALL(SetUnkParameter_t, 0x562180, this, value);
	}

	void GUIRenderContext::SetBlendState(dl_uint state)
	{
		CALL(SetBlendState_t, 0x562ad0, this, state);
	}

	void GUIRenderContext::SetSamplerState(const GUI_SAMPLER_STATE& state)
	{
		CALL(SetSamplerState_t, 0x561f90, this, state);
	}

	void GUIRenderContext::SetScissorRect(const Rect& rect)
	{
		CALL(SetScissorRect_t, 0x561d70, this, rect);
	}

	void GUIRenderContext::SetTextAttribute(const GUI_TEXT_ATTRIBUTE& attr)
	{
		CALL(SetTextAttribute_t, 0x561d10, this, attr);
	}

	void GUIRenderContext::SetTextColor(DLMT::DL_COLOR_32 color)
	{
		CALL(SetTextColor_t, 0x561ba0, this, color);
	}

	void GUIRenderContext::SetTextHAlign(dl_uint8 align)
	{
		CALL(SetTextHAlign_t, 0x561c90, this, align);
	}

	void GUIRenderContext::SetTextVAlign(dl_uint8 align)
	{
		CALL(SetTextVAlign_t, 0x561cd0, this, align);
	}

	void GUIRenderContext::SetTextScale(const DLMT::DL_VECTOR2& scale)
	{
		CALL(SetTextScale_t, 0x561ad0, this, scale);
	}
}