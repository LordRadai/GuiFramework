#pragma once
#include "GUIOnOffTweaker.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIOnOffTweaker : public GUIOnOffTweaker
	{
		typedef TGUIOnOffTweaker ThisClass;
		typedef GUIOnOffTweaker SuperClass;
	public:
		TGUIOnOffTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label, T* pValue) : SuperClass(pParent, label)
		{
			this->m_pValue = pValue;
			this->m_valueOld = *pValue;

			dl_bool bValueOn = (*pValue != static_cast<T>(0));

			SetCheck(bValueOn);
		}

		virtual ~TGUIOnOffTweaker() override
		{
			OnDelete();
			UnRef();
			GUIOnOffTweaker::_Destroy();
		}

		virtual void OnDelete() override
		{
			this->m_pValue = nullptr;
			SuperClass::OnDelete();
		}

		virtual void Update(dl_float32 dt) override
		{
			if (this->m_pValue == nullptr)
				return;

			if (*this->m_pValue == this->m_valueOld) 
			{
				dl_bool bToggled = IsCheckBoxToggled();
				dl_bool bValueOn = (this->m_valueOld != 0);

				if (bValueOn != bToggled)
				{
					if ((this->m_flags & 1) == 0) 
					{
						bool newState = IsCheckBoxToggled();

						this->m_valueOld = newState;
						*this->m_pValue = newState;

						this->InvokeCallback();
					}
					else
					{
						SetCheck(this->m_valueOld != 0);
					}
				}
			}
			else
			{
				this->m_valueOld = *this->m_pValue;
				SetCheck(this->m_valueOld != 0);
			}
		}

		virtual void Close() override
		{
			this->m_pValue = nullptr;
			SuperClass::Close();
		}

	private:
		T* m_pValue;
		T m_valueOld;
	};
}