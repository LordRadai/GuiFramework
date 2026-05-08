#pragma once
#include "GUIMultiTweaker.h"
#include "GuiFramework/Window/ControlEx/TGUIRangeData.inl"
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIMultiTweaker : public GUIMultiTweaker
	{
		typedef TGUIMultiTweaker ThisClass;
		typedef GUIMultiTweaker SuperClass;
	public:
		TGUIMultiTweaker(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint8 numValues, T* pValue, T min, T max, T step, dl_float32 mult) : SuperClass(numValues, label)
		{
			this->m_numValues = numValues;
			this->m_pValue = pValue;
			this->m_pValueOld = GUI_ALLOCATOR->AllocateAligned(sizeof(T) * numValues, 4);

			for (dl_uint8 i = 0; i < numValues; i++)
			{
				TGUIRangeData<T>* pRangeData = new TGUIRangeData<T>(min, max, step, mult);
				
				this->m_pMultiNumericEditor->SetRangeData(i, pRangeData);
			}

			Create(pParent, label);
		}

		virtual ~TGUIMultiTweaker() override
		{
			OnDelete();
			UnRef();

			GUIMultiTweaker::_Destroy();
		}

		virtual void OnDelete() override
		{
			if (this->m_pValueOld)
			{
				GUI_ALLOCATOR->Free(this->m_pValueOld);
				this->m_pValueOld = nullptr;
			}

			this->m_pValue = nullptr;
			SuperClass::OnDelete();
		}

		virtual void Update(dl_float32 dt) override
		{
			if (this->m_pValue == nullptr)
				return;

			dl_bool bValueChanged = false;

			for (size_t i = 0; i < this->m_numValues; i++)
			{
				TGUIRangeData<T>* pRangeData = this->m_pMultiNumericEditor->GetRangeData<T>(i);

				if (this->m_pValue[i] == this->m_pValueOld[i])
				{
					if (this->m_pValueOld[i] != pRangeData->GetValue())
					{
						if ((this->m_flags & 1) == 0)
						{
							this->m_pValueOld[i] = pRangeData->GetValue();
							this->m_pValue[i] = pRangeData->GetValue();
							bValueChanged = true;
						}
						else
						{
							pRangeData->SetValue(this->m_pValueOld[i]);
							this->m_pMultiNumericEditor->Reflesh(i);
						}
					}
				}
				else
				{
					this->m_pValueOld[i] = this->m_pValue[i];
					pRangeData->SetValue(this->m_pValueOld[i]);
					this->m_pMultiNumericEditor->Reflesh(i);
				}
			}

			if (bValueChanged)
				InvokeCallback();
		}

		virtual void Close() override
		{
			this->m_pValue = nullptr;
			SuperClass::Close();
		}
	private:
		dl_uint8 m_numValues;
		T* m_pValue;
		T* m_pValueOld;
	};
}