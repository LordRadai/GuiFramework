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
}