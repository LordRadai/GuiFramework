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
		virtual ~GUITexture_DLTexture();
		virtual void OnDelete() override;
		virtual dl_uint GetWidth() override;
		virtual dl_uint GetHeight() override;
		virtual dl_uint GetDepth() override;
		virtual dl_int GetTextureType() override;
		virtual dl_int GetFormat() override;
		virtual dl_uint GetMipMapLevelNum() override;
		virtual dl_bool Apply(dl_uint mipLevel, GUIRenderImplBase* pRenderImpl) override;

	protected:
		DLGR::DLTextureBase* m_pTexture;
	};
}