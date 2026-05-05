#pragma once
#include "GUIRenderImplBase.h"

#undef DrawText

namespace GuiFramework
{
	class GUIRenderImpl : public GUIRenderImplBase
	{
	public:
		GUIRenderImpl();

		virtual ~GUIRenderImpl() override;
		virtual void SetBlendMode(dl_uint blendMode) override;
		virtual dl_bool GetViewport(GUI_VIEWPORT& viewport) const override;
		virtual void SetDefaultRenderState() override;
		virtual void SetTexture(dl_uint id, GUITextureBase* pTexture) override;
		virtual void UnSetTexture(dl_uint id) override;
		virtual void UploadShaderParameter(const _SHADER_PARAMETER& param) override;
		virtual void SetDLTexture(dl_uint id, DLGR::DLTextureBase* pTexture) override;
	};
}