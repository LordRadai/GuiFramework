#pragma once
#include "GUIRangeTweaker.h"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/Window/ControlEx/TGUIRangeData.inl"

namespace GuiFramework
{
	template<typename T>
	class TGUIRangeTweaker : public GUIRangeTweaker
	{
		typedef TGUIRangeTweaker ThisClass;
		typedef GUIRangeTweaker SuperClass;
	public:
		TGUIRangeTweaker(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, T* pValue, T min, T max, T step, dl_float32 mult = 1.f) : SuperClass()
			, m_pValue(pValue)
		{
			TGUIRangeData<T>* pRangeData = new TGUIRangeData<T>(min, max, step, mult);
			this->m_pRangeData = pRangeData;
			Create(pParent, label);
		}

		virtual ~TGUIRangeTweaker() override
		{
			_Destroy();
		}

		virtual void OnDelete() override
		{
			this->m_pRangeData = nullptr;
			SuperClass::OnDelete();
		}

		virtual void Update(dl_float32 dt) override
		{
			if (this->m_pValue == nullptr)
				return;

			if (*this->m_pValue == this->m_valueOld)
			{
				if (this->m_valueOld != this->m_pRangeData->GetValue())
				{
					if (this->m_flags & 1)
					{
						this->m_valueOld = this->m_pRangeData->GetValue();
						*this->m_pValue = this->m_valueOld;
						this->InvokeCallback();
					}
					else
					{
						this->m_pRangeData->SetValue(this->m_valueOld);
						this->m_pWidget->Reflesh();
					}
				}
			}
			else
			{
				this->m_valueOld = *this->m_pValue;
				this->m_pRangeData->SetValue(this->m_valueOld);
				this->m_pWidget->Reflesh();
			}
		}

		virtual void Close() override
		{
			this->m_pValue = nullptr;
			SuperClass::Close();
		}

		virtual TGUIRangeData<T>* GetRangeData() const override
		{
			return this->m_pRangeData.Get();
		}
	private:
		void _Destroy() 
		{
			OnDelete();
			UnRef();
			SuperClass::_Destroy();
		}

		TGUIObjectPtr<TGUIRangeData<T>> m_pRangeData;
		T* m_pValue;
		T m_valueOld;
	};
}