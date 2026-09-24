#include "GUIVirtualInput.h"

#include <algorithm>

namespace GuiFramework
{
	GUIVirtualInput::~GUIVirtualInput()
	{
		m_inputs.clear();
	}

	VirtualInput& GUIVirtualInput::GetVirtualInput(dl_int idx)
	{
		if (idx < 0 || idx >= static_cast<dl_int>(m_inputs.size()))
			throw std::out_of_range("Index out of range");

		return m_inputs[idx];
	}

	void GUIVirtualInput::PushInput(const VirtualInput& input)
	{
		m_inputs.push_back(input);
	}
}