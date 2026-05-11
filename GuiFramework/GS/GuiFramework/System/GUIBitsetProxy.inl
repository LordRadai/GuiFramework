#pragma once
#include <bitset>

namespace GuiFramework
{
	template<unsigned int N>
	class GUIBitsetProxy : std::bitset<N>
	{
	public:
		GUIBitsetProxy() {}
	};
}