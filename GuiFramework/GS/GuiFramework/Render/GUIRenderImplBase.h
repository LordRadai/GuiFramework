#pragma once
#include <dantelion2.h>

#include "GuiFramework/System/GUIFont.h"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/TGUIPoint.inl"

#include "GuiFramework/Window/Control/GUITextureBase.h"

#undef DrawText

namespace GuiFramework
{
	enum GUI_PRIMITIVE_TOPOLOGY : dl_uint
	{};

	struct GUI_TEXT_ATTRIBUTE
	{
		DLMT::DL_COLOR_32 Color;
		dl_float32 SizeX;
		dl_float32 SizeY;
		dl_float32 ShadowOffsetX;
		dl_float32 ShadowOffsetY;
		dl_bool Shadow;
		dl_bool Bold;
		dl_uint8 VAlign;
		dl_uint8 HAlign;
	};

	struct GUI_SAMPLER_STATE
	{
		dl_uint8 State;
	};

	struct GUI_VIEWPORT
	{
		dl_float32 fVar0;
		dl_float32 fVar4;
		dl_float32 fVar8;
		dl_float32 fVarC;
		dl_float32 fVar10;
		dl_float32 fVar14;
	};

	struct _SHADER_PARAMETER
	{
		dl_uint8 bVar0;
		dl_uint8 bVar1;
		dl_uint8 bVar2;
		dl_uint8 bVar3;
		dl_float32 fVar4;
		dl_float32 fVar8;
	};

	class GUIRenderImplBase
	{
	public:
		virtual ~GUIRenderImplBase();
		virtual dl_bool BeginText(const GUIFont& font, DLMT2::DL_COLOR_U8 color);
		virtual dl_bool BeginText(const GUIFont& font, DLMT::DL_COLOR_32 color) { return false; }
		virtual void DrawText(const Rect& pos, const dl_wchar* text) {}
		virtual void DrawText(dl_int x, dl_int y, const dl_wchar* text) {}
		virtual dl_float32 GetTextHeight() const { return 0.f; }
		virtual void SetTextScale(const Point2D& scale);
		virtual void SetTextScale(const DLMT::DL_VECTOR2& scale) {}
		virtual void SetTextShadowEnable(dl_uint enable) {}
		virtual void SetTextColor(DLMT2::DL_COLOR_U8 color, DLMT2::DL_COLOR_U8 shadowColor);
		virtual void SetTextColor(DLMT::DL_COLOR_32 color, DLMT::DL_COLOR_32 shadowColor) {}
		virtual void SetTextAttribute(const GUI_TEXT_ATTRIBUTE& attr, DLMT2::DL_COLOR_U8 color);
		virtual void SetTextAttribute(const GUI_TEXT_ATTRIBUTE& attr, DLMT::DL_COLOR_32 color) {}
		virtual void SetTextHAlign(dl_uint8 align);
		virtual void SetTextVAlign(dl_uint8 align);
		virtual DLMT::DL_FRECT GetTextExtent(const DLMT::DL_FRECT& pos, const dl_wchar* text) const;
		virtual DLMT::DL_FRECT GetTextExtent(dl_int x, dl_int y, const dl_wchar* text) const;
		virtual void EndText() {}
		virtual dl_bool SetScissorRect(const Rect& rect) { return false; }
		virtual dl_bool GetScissorRect(Rect& rect) const { return false; }
		virtual void SetShader(dl_uint shaderId) {}
		virtual void SetBlendMode(dl_uint blendMode) {}
		virtual dl_bool GetViewport(GUI_VIEWPORT& viewport) const { return false; }
		virtual void SetDefaultRenderState() {}
		virtual void SetTexture(dl_uint id, GUITextureBase* pTexture) {}
		virtual void UnSetTexture(dl_uint id) {}
		virtual void SetSamplerState(dl_uint slot, GUI_SAMPLER_STATE& state) {}
		virtual dl_bool DrawPrimitiveUP(GUI_PRIMITIVE_TOPOLOGY topology, dl_uint vertexCount, const void* pVertexData, dl_uint vertexStride) { return false; }
		virtual void FillWindowBasis(const Rect& rect, dl_float32 alpha) {}
		virtual void UploadShaderParameter(const _SHADER_PARAMETER& param) {}
		virtual void SetDLTexture(dl_uint id, DLGR::DLTextureBase* pTexture) {}

		typedef void(__fastcall* Destructor_t)(GUIRenderImplBase*);
		typedef dl_bool(__fastcall* BeginTextARGB_t)(GUIRenderImplBase*, const GUIFont&, DLMT2::DL_COLOR_U8);
		typedef dl_bool(__fastcall* BeginText_t)(GUIRenderImplBase*, const GUIFont&, DLMT::DL_COLOR_32);
		typedef void(__fastcall* DrawText_Rect_t)(GUIRenderImplBase*, const Rect&, const dl_wchar*);
		typedef void(__fastcall* DrawText_Coords_t)(GUIRenderImplBase*, dl_int, dl_int, const dl_wchar*);
		typedef dl_float32(__fastcall* GetTextHeight_t)(GUIRenderImplBase*);
		typedef void(__fastcall* SetTextScale_Point_t)(GUIRenderImplBase*, const Point2D&);
		typedef void(__fastcall* SetTextScale_Vector_t)(GUIRenderImplBase*, const DLMT::DL_VECTOR2&);
		typedef void(__fastcall* SetTextShadowEnable_t)(GUIRenderImplBase*, dl_uint);
		typedef void(__fastcall* SetTextColorARGB_t)(GUIRenderImplBase*, DLMT2::DL_COLOR_U8, DLMT2::DL_COLOR_U8);
		typedef void(__fastcall* SetTextColor_t)(GUIRenderImplBase*, DLMT::DL_COLOR_32, DLMT::DL_COLOR_32);
		typedef void(__fastcall* SetTextAttributeARGB_t)(GUIRenderImplBase*, const GUI_TEXT_ATTRIBUTE&, DLMT2::DL_COLOR_U8);
		typedef void(__fastcall* SetTextAttribute_t)(GUIRenderImplBase*, const GUI_TEXT_ATTRIBUTE&, DLMT::DL_COLOR_32);
		typedef void(__fastcall* SetHAlign_t)(GUIRenderImplBase*, dl_uint8);
		typedef void(__fastcall* SetVAlign_t)(GUIRenderImplBase*, dl_uint8);
		typedef DLMT::DL_FRECT(__fastcall* GetTextExtent_Rect_t)(const GUIRenderImplBase*, const DLMT::DL_FRECT&, const dl_wchar*);
		typedef DLMT::DL_FRECT(__fastcall* GetTextExtent_Coords_t)(const GUIRenderImplBase*, dl_int, dl_int, const dl_wchar*);
		typedef void(__fastcall* EndText_t)(GUIRenderImplBase*);
		typedef dl_bool(__fastcall* SetScissorRect_t)(GUIRenderImplBase*, const Rect&);
		typedef dl_bool(__fastcall* GetScissorRect_t)(GUIRenderImplBase*, Rect&);
		typedef void(__fastcall* SetShader_t)(GUIRenderImplBase*, dl_uint);
		typedef void(__fastcall* SetBlendMode_t)(GUIRenderImplBase*, dl_uint);
		typedef dl_bool(__fastcall* GetViewport_t)(GUIRenderImplBase*, GUI_VIEWPORT&);
		typedef void(__fastcall* SetDefaultRenderState_t)(GUIRenderImplBase*);
		typedef void(__fastcall* SetTexture_t)(GUIRenderImplBase*, GUITextureBase*);
		typedef void(__fastcall* UnsetTexture_t)(GUIRenderImplBase*);
		typedef void(__fastcall* SetSamplerState_t)(GUIRenderImplBase*, dl_uint, GUI_SAMPLER_STATE&);
		typedef dl_bool(__fastcall* DrawPrimitiveUP_t)(GUIRenderImplBase*, GUI_PRIMITIVE_TOPOLOGY, dl_uint, const void*, dl_uint);
		typedef void(__fastcall* FillWindowBasis_t)(GUIRenderImplBase*, const Rect&, dl_float32);
		typedef void(__fastcall* UploadShaderParameter_t)(GUIRenderImplBase*, const _SHADER_PARAMETER&);
		typedef void(__fastcall* SetDLTexture_t)(GUIRenderImplBase*, DLGR::DLTextureBase*);

	protected:
		GUI_TEXT_ATTRIBUTE m_textAttribute;
		dl_int m_iVar20;
		GUI_VIEWPORT m_viewport;
	};
}