#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	template<typename T>
	class TGUIBitFieldProxy
	{
		typedef TGUIBitFieldProxy<T> ThisClass;
	public:
		TGUIBitFieldProxy() : m_pValue(nullptr), m_bitIndex(0), m_numBits(0) 
		{
		}

		TGUIBitFieldProxy(T* pValue, dl_uint32 bitIndex, dl_uint32 numBits = 1) :
			m_pValue(pValue),
			m_bitIndex(bitIndex),
			m_numBits(numBits)
		{
		}

		T GetValue() const
		{
			if (!m_pValue) return 0;
			return (*m_pValue >> m_bitIndex) & ((1 << m_numBits) - 1);
		}

		TGUIBitFieldProxy& operator=(T value)
		{
			if (!m_pValue) return *this;

			T mask = ((1 << m_numBits) - 1) << m_bitIndex;
			*m_pValue = (*m_pValue & ~mask) | ((value << m_bitIndex) & mask);

			return *this;
		}

	protected:
		T* m_pValue;
		dl_uint8 m_bitIndex;
		dl_uint8 m_bitMask;
	};
}