#pragma once
#include "GUIComboTweaker.h"
#include "GuiFramework/System/TGUIValueStringPair.inl"
#include <Call.h>

namespace GuiFramework
{
	template<typename T>
	class TGUIComboTweaker : public GUIComboTweaker
	{
		typedef TGUIComboTweaker<T> ThisClass;
		typedef GUIComboTweaker SuperClass;
	public:
		TGUIComboTweaker() : SuperClass(), m_pValue(nullptr) {}
		TGUIComboTweaker(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, T* pValue, TGUIValueStringPairData<T>* items) : SuperClass(pParent, label, 0)
		{
			this->m_pValue = pValue;
			this->m_valueOld = *pValue;
			this->m_valueStringPairs = items;

			_Init();
		}

		virtual ~TGUIComboTweaker() override 
		{
			OnDelete();
			_Destroy();
		}

		virtual void OnDelete() override
		{
			this->m_valueStringPairs = nullptr;
			this->m_pValue = nullptr;
			SuperClass::OnDelete();
		}

		virtual void Update(dl_float32 dt) override
		{
			SuperClass::Update(dt);
			if (this->m_pValue && (*this->m_pValue != this->m_valueOld))
			{
				this->m_valueOld = *this->m_pValue;
				dl_int index = this->m_valueStringPairs->FindIndexByValue(this->m_valueOld);
				SetComboCurSel(index);
			}
		}

		virtual void Close() override
		{
			this->m_pValue = nullptr;
			SuperClass::Close();
		}

	protected:
		virtual void _OnComboSelChanged(dl_int idx) override
		{
			if ((this->m_flags & 1) == 0)
			{
				if (idx > this->m_valueStringPairs->GetNumPairs())
					return;

				this->m_valueOld = this->m_valueStringPairs->GetValueByIndex(idx);
				*this->m_pValue = this->m_valueOld;
			}
		}

		void _Destroy()
		{
			this->OnDelete();
			this->m_nRefAndFlags &= 0xbfffffff;
			this->m_valueStringPairs.UnRef();

			SuperClass::_Destroy();
		}

		void _Init()
		{
			typedef void(_fastcall* Init_t)(TGUIComboTweaker<T>*);
			CALL(Init_t, 0x566310, this);
		}

	private:
		T m_valueOld;
		T* m_pValue;
		TGUIObjectPtr<TGUIValueStringPairData<T>> m_valueStringPairs;
	};
}