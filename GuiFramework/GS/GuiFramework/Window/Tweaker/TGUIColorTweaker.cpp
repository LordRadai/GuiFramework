#include "TGUIColorTweaker.inl"
#include <Call.h>

namespace GuiFramework
{
	template<>
	void TGUIColorTweaker<DLMT::DL_COLOR_32>::OnUpdate()
	{
		if (this->m_pValue == nullptr)
			return;

		if (*this->m_pValue == this->m_valueOld)
		{
			DLMT::DL_COLOR_32 color;
			this->GetIntColor(color);

			if (this->m_valueOld != color)
			{
				if ((this->m_flags & 1) == 0)
				{
					this->m_valueOld = color;
					*this->m_pValue = this->m_valueOld;
					this->InvokeCallback();
				}
				else
				{
					this->SetColor(this->m_valueOld);
				}
			}
		}
		else
		{
			this->m_valueOld = *this->m_pValue;
			this->SetColor(this->m_valueOld);
		}
	}

	template<>
	void TGUIColorTweaker<DLMT::DL_VECTOR4>::OnUpdate()
	{
		if (this->m_pValue == nullptr)
			return;

		if (*this->m_pValue == this->m_valueOld)
		{
			DLMT::DL_VECTOR4 color;
			this->GetFloatColor(color);

			if (this->m_valueOld != color)
			{
				if ((this->m_flags & 1) == 0)
				{
					this->m_valueOld = color;
					*this->m_pValue = this->m_valueOld;
					this->InvokeCallback();
				}
				else
				{
					this->SetColor(this->m_valueOld);
				}
			}
		}
		else
		{
			this->m_valueOld = *this->m_pValue;
			this->SetColor(this->m_valueOld);
		}
	}

	template<>
	void TGUIColorTweaker<DLMT2::DL_COLOR_U8>::OnUpdate()
	{
		if (this->m_pValue == nullptr)
			return;

		if (*this->m_pValue == this->m_valueOld)
		{
			DLMT2::DL_COLOR_U8 color;
			this->GetU8Color(color);

			if (this->m_valueOld != color)
			{
				if ((this->m_flags & 1) == 0)
				{
					this->m_valueOld = color;
					*this->m_pValue = this->m_valueOld;
					this->InvokeCallback();
				}
				else
				{
					this->SetColor(this->m_valueOld);
				}
			}
		}
		else
		{
			this->m_valueOld = *this->m_pValue;
			this->SetColor(this->m_valueOld);
		}
	}
}