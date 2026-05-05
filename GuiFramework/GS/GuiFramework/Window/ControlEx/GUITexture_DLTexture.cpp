#include "GUITexture_DLTexture.h"

namespace GuiFramework
{
	
	GUITexture_DLTexture::GUITexture_DLTexture(DLGR::DLTextureBase* pTexture) : GUITextureBase(), m_pTexture(pTexture)
	{
		if (this->m_pTexture)
			this->m_pTexture->Ref();
	}

	DLRF::DLRuntimeClass* GUITexture_DLTexture::GetRuntimeClassOfThis() const
	{
		return GUITextureBase::GetRuntimeClassOfThis();
	}

	GUITexture_DLTexture::~GUITexture_DLTexture()
	{
		if (this->m_pTexture)
			this->m_pTexture->Unref();
	}

	void GUITexture_DLTexture::OnDelete()
	{
		if (this->m_pTexture)
		{
			this->m_pTexture->Unref();
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
		dl_int dlType = this->m_pTexture ? this->m_pTexture->GetType() : -1;

		switch (dlType)
		{
		case 0:		return 0;
		case 1:		return 2;
		case 2:		return 3;
		case 3:		return 4;
		case 4:		return 1;
		default:	return -1;
		}
	}

	dl_int GUITexture_DLTexture::GetFormat()
	{
		return this->m_pTexture ? this->m_pTexture->GetFormat() : 0x86;
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