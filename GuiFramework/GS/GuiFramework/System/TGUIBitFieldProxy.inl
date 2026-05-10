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

		~TGUIBitFieldProxy()
		{
			Finalize();
		}

		void Finalize()
		{
			m_pValue = nullptr;
		}

		T GetMask() const
		{
			return (static_cast<T>(1) << m_numBits) - 1;
		}

		T GetValue() const
		{
			if (!m_pValue) return 0;
			return (*m_pValue >> m_bitIndex) & GetMask();
		}

		TGUIBitFieldProxy& operator=(T value)
		{
			if (!m_pValue) return *this;

			T mask = GetMask();
			*m_pValue = (*m_pValue & ~(mask << m_bitIndex)) | ((value & mask) << m_bitIndex);

			return *this;
		}

		dl_size GetDataBitSize() const { return sizeof(T) * 8; }

		operator T() const { return GetValue(); }
	protected:
		T* m_pValue;
		dl_uint8 m_bitIndex;
		dl_uint8 m_numBits;
	};
}