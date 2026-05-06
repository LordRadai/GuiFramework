#include "GUIVirtualInput.h"

namespace GuiFramework
{
	VirtualInput& GUIVirtualInput::GetVirtualInput(dl_int idx)
	{
		if (idx < 0 || idx >= static_cast<dl_int>(m_inputs.size()))
			throw std::out_of_range("Index out of range");

		return m_inputs[idx];
	}

	void GUIVirtualInput::PushInput(const VirtualInput& input)
	{
		auto& inputs = this->m_inputs;

		auto it = std::lower_bound(inputs.begin(), inputs.end(), input,
			[](const _GUI_VIRTUAL_INPUT& a, const _GUI_VIRTUAL_INPUT& b) {
				return a.InputID < b.InputID;
			});

		inputs.insert(it, input);
	}
}