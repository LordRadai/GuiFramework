#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
    struct _GUI_VIRTUAL_INPUT
    {
        dl_int InputID;

        bool IsKeyEvent(dl_char eventID) const
        {
            return InputID == eventID;
        }

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 4, GUI_ALLOCATOR);
        }

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
        }
    };

    typedef _GUI_VIRTUAL_INPUT VirtualInput;

    class GUIVirtualInput
    {
    public:
        VirtualInput* GetVirtualInput(dl_int idx) const
        {
            if (idx > m_inputs.size())
                return nullptr;

            return m_inputs[idx];
		}

        void AddVirtualInput(VirtualInput* pInput)
        {
            m_inputs.push_back(pInput);
		}

		dl_size GetNumVirtualInputs() const { return m_inputs.size(); }

    protected:
		DLUT::DLVector<VirtualInput*> m_inputs;
    };
}