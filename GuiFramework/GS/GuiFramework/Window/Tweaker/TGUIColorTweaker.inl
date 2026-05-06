#pragma once
#include "GUIColorTweaker.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIColorTweaker : public GUIColorTweaker
	{
		typedef TGUIColorTweaker<T> ThisClass;
		typedef GUIColorTweaker SuperClass;
	public:
		virtual ~TGUIColorTweaker() override
		{
			_Destroy();
		}

		virtual void OnDelete() override
		{
			m_pValue = nullptr;
			SuperClass::OnDelete();
		}

		virtual void Close() override
		{
			m_pValue = nullptr;
			SuperClass::Close();
		}

		virtual void OnUpdate() override;

	protected:
		void _Destroy()
		{
			this->OnDelete();
			this->m_nRefAndFlags &= 0xbfffffff;
			this->m_pColorSelector.UnRef();

			SuperClass::_Destroy();
		}

		T m_valueOld;
		T* m_pValue;
	};

	template<> void TGUIColorTweaker<DLMT::DL_COLOR_32>::OnUpdate();
	template<> void TGUIColorTweaker<DLMT::DL_VECTOR4>::OnUpdate();
	template<> void TGUIColorTweaker<DLMT2::DL_COLOR_U8>::OnUpdate();
}