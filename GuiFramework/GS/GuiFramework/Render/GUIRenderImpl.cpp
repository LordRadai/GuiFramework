#include "GUIRenderImpl.h"

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUIRenderImpl*);

	GUIRenderImpl::GUIRenderImpl()
	{
		CALL(Constructor_t, 0xc57150, this);
	}

	GUIRenderImpl::~GUIRenderImpl()
	{
		CALL(Destructor_t, 0xc57aa0, this);
	}

	void GUIRenderImpl::SetBlendMode(dl_uint blendMode)
	{
		CALL(SetBlendMode_t, 0xc57200, this, blendMode);
	}

	dl_bool GUIRenderImpl::GetViewport(GUI_VIEWPORT& viewport) const
	{
		return CALL(GetViewport_t, 0xc57440, this, viewport);
	}

	void GUIRenderImpl::SetDefaultRenderState()
	{
		CALL(SetDefaultRenderState_t, 0xc57490, this);
	}

	void GUIRenderImpl::SetTexture(dl_uint id, GUITextureBase* pTexture)
	{
		CALL(SetTexture_t, 0xc575d0, this, id, pTexture);
	}

	void GUIRenderImpl::UnSetTexture(dl_uint id)
	{
		CALL(UnSetTexture_t, 0xc57630, this, id);
	}

	void GUIRenderImpl::UploadShaderParameter(const _SHADER_PARAMETER& param)
	{
		CALL(UploadShaderParameter_t, 0xc57700, this, param);
	}

	void GUIRenderImpl::SetDLTexture(dl_uint id, DLGR::DLTextureBase* pTexture)
	{
		CALL(SetDLTexture_t, 0xc57a10, this, id, pTexture);
	}
}