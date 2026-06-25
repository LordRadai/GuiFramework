#include "GUITexture_DLTexture.h"

namespace GuiFramework
{
	GUITexture_DLTexture::GUITexture_DLTexture(DLGR::DLTextureBase* pTexture) : GUITextureBase(), m_pTexture(pTexture)
	{
		if (this->m_pTexture)
			this->m_pTexture->AddRef();
	}

	DLRF::DLRuntimeClass* GUITexture_DLTexture::GetRuntimeClassOfThis() const
	{
		return GUITextureBase::GetRuntimeClassOfThis();
	}

	GUITexture_DLTexture::~GUITexture_DLTexture()
	{
		if (this->m_pTexture)
			this->m_pTexture->UnRef();
	}

	void GUITexture_DLTexture::OnDelete()
	{
		if (this->m_pTexture)
		{
			this->m_pTexture->UnRef();
			this->m_pTexture = nullptr;
		}
	}

	dl_uint GUITexture_DLTexture::GetWidth()
	{
		return this->m_pTexture ? this->m_pTexture->GetWidth() : 0;
	}
	
	dl_uint GUITexture_DLTexture::GetHeight()
	{
		return this->m_pTexture ? this->m_pTexture->GetHeight() : 0;
	}

	dl_int GUITexture_DLTexture::GetTextureType()
	{
		dl_int dlType = this->m_pTexture ? this->m_pTexture->GetType() : GUITEXTYPE_INVALID;

		switch (dlType)
		{
		case DLGR::DLTEXTYPE_NONE:		return GUITEXTYPE_NONE;
		case DLGR::DLTEXTYPE_1:			return GUITEXTYPE_2;
		case DLGR::DLTEXTYPE_2:			return GUITEXTYPE_3;
		case DLGR::DLTEXTYPE_2D:		return GUITEXTYPE_2D;
		case DLGR::DLTEXTYPE_CUBE:		return GUITEXTYPE_CUBE;
		default:						return GUITEXTYPE_INVALID;
		}
	}

	dl_int GUITexture_DLTexture::GetFormat()
	{
		return this->m_pTexture ? this->m_pTexture->GetDLTextureFormat() : DLGR::DLTEXFMT_D24S8;
	}

	dl_uint GUITexture_DLTexture::GetMipMapLevelNum()
	{
		return this->m_pTexture ? this->m_pTexture->GetMipMapLevelNum() : 0;
	}

	dl_bool GUITexture_DLTexture::Apply(dl_uint mipLevel, GUIRenderImplBase* pRenderImpl)
	{
		pRenderImpl->SetDLTexture(mipLevel, this->m_pTexture);

		return true;
	}
}