#pragma once
#include <dantelion2.h>
#include <bitset>

namespace GuiFramework
{
	template<unsigned int N>
	struct GUIBitsetProxy
	{
		GUIBitsetProxy() {}

		std::bitset<N> Bitset;
	};
}