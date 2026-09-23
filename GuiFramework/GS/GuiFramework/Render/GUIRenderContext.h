#pragma once
#include "GuiFramework/Globals.h"
#include "GUIRenderImplBase.h"
#include "GUIPrimitiveTopology.h"
#include "GUIVertex.h"
#include "GUIBlend.h"
#include "GUISprite.h"
#include "GUIShaderType.h"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/GUIFont.h"
#include "GuiFramework/Window/Control/GUITextureBase.h"

namespace GuiFramework
{
	class GUIRenderContext
	{
		typedef GUIRenderContext ThisClass;
	public:
		GUIRenderContext(GUIRenderImplBase& impl);
		GUIRenderContext(GUIRenderContext& other);

		dl_bool BeginText(const GUIFont& font);
		void DrawText(const Rect& pos, const dl_wchar* text);
		void DrawText(dl_int x, dl_int y, const dl_wchar* text);
		void DrawFormatText(dl_int x, dl_int y, const dl_wchar* fmt, ...);
		void DrawFormatText(const Rect& pos, const dl_wchar* fmt, ...);
		void EndText();
		void DrawPrimitive(GUI_PRIMITIVE_TOPOLOGY topology, _GUI_VERTEX_ColorTex1* pVertices, dl_uint vertexCount, GUI_BLEND blendMode, GUITextureBase* pTexture);
		void DrawSprite(const GUI_SPRITE_RECT& spriteRect, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType);
		void DrawSprite(const GUI_SPRITE_GOURAUD_RECT& spriteRect, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType);
		void DrawSpriteCube(const GUI_SPRITE_GOURAUD_RECT& spriteRect, dl_uint faceIdx, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType);
		void DrawSpriteCubeAllFace(const GUI_SPRITE_GOURAUD_RECT& spriteRect, GUI_BLEND blendMode, GUITextureBase* pTexture, GUI_SHADERTYPE shaderType);
		void DrawEdge(const Rect& rect, dl_float32 thickness, DLMT::DL_COLOR_32 color, GUI_BLEND blendMode, dl_int flags);
		void FillGoraudRect(const Rect& rect, const DLMT::DL_COLOR_32* col, GUI_BLEND blendMode);
		void FillRect(const Rect& rect, DLMT::DL_COLOR_32 color, GUI_BLEND blendMode);
		void FillSoftRect(const Rect& rect, DLMT::DL_COLOR_32 color, GUI_BLEND blendMode);
		void SetDefaultRenderState();
		void SetUnkParameter(dl_bool value);
		void SetBlendState(dl_uint state);
		void SetSamplerState(const GUI_SAMPLER_STATE& state);
		void SetScissorRect(const Rect& rect);
		void SetTextAttribute(const GUI_TEXT_ATTRIBUTE& attr);
		void SetTextColor(DLMT::DL_COLOR_32 color);
		void SetTextHAlign(dl_uint8 align);
		void SetTextVAlign(dl_uint8 align);
		void SetTextScale(const DLMT::DL_VECTOR2& scale);

		static void* operator new(dl_size size)
		{
			return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Allocate(size, 8, GUIAllocator::s_pDefaultAllocator);
		}

		static void operator delete(void* p)
		{
			DLKRD::AllocationSupporter<DLKR::DLAllocator>::Deallocate(p, GUIAllocator::s_pDefaultAllocator);
		}

	private:
		GUIRenderImplBase* m_pImpl;
		dl_float32 m_X;
		dl_float32 m_Y;
		dl_float32 m_fVarC;
		dl_float32 m_fVar10;
		DLMT::DL_COLOR_32 m_Color0;
		DLMT::DL_COLOR_32 m_Color1;
		Rect m_ScissorRect;
		Rect m_ViewportRect;
		Rect m_Rect40;
		Rect m_Rect50;
		dl_uint m_iVar60;
		dl_uint m_iVar64;
		dl_uint m_iVar68;
		dl_int m_BlendState;
		dl_uint m_iVar70;
		dl_uint m_iVar74;
		dl_uint8 m_SamplerState;
	};

	typedef GUIRenderContext GraphicsContext;
}
