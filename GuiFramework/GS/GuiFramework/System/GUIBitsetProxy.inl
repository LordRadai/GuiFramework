#pragma once
#include <bitset>

namespace GuiFramework
{
	template<unsigned int N>
	class GUIBitsetProxy
	{
	public:
		GUIBitsetProxy(std::bitset<N>* pBitset, dl_int bitIndex) : m_pBitset(pBitset), m_bitIndex(bitIndex) {}

		dl_bool test() const
		{
			if (m_pBitset == nullptr || m_bitIndex < 0 || m_bitIndex >= N)
				return false;
			return m_pBitset->test(m_bitIndex);
		}

		void set(dl_bool value)
		{
			if (m_pBitset == nullptr || m_bitIndex < 0 || m_bitIndex >= N)
				return;
			m_pBitset->set(m_bitIndex, value);
		}

		void reset()
		{
			if (m_pBitset == nullptr || m_bitIndex < 0 || m_bitIndex >= N)
				return;
			m_pBitset->reset(m_bitIndex);
		}
	private:
		std::bitset<N>* m_pBitset;
		dl_int m_bitIndex;
	};
}