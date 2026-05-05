#pragma once
#include "GuiFramework/Window/Control/GUITextureBase.h"

namespace GuiFramework
{
	class GUITexture_DLTexture : public GUITextureBase
	{
	public:
		GUITexture_DLTexture() : GUITextureBase() {}
		GUITexture_DLTexture(DLGR::DLTextureBase* pTexture);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITexture_DLTexture() {}
		virtual void OnDelete() override;
		virtual dl_uint GetWidth();
		virtual dl_uint GetHeight();
		virtual dl_uint GetDepth();
		virtual dl_int GetTextureFormat();
		virtual dl_int GetFormat();
		virtual dl_int GetMipMapLevel();
		virtual dl_int Apply(dl_uint mipLevel, GUIRenderImplBase* pRenderImpl);

	protected:
		DLGR::DLTextureBase* m_pTexture;
	};
}