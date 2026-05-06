#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
    struct _GUI_VIRTUAL_INPUT
    {
        dl_uint8 InputID;
		dl_float32 Param1;
		dl_float32 Param2;

		_GUI_VIRTUAL_INPUT() : InputID(0), Param1(0), Param2(0) {}
		_GUI_VIRTUAL_INPUT(dl_uint8 inputID, dl_float32 param1 = 0.f, dl_float32 param2 = 0.f) : InputID(inputID), Param1(param1), Param2(param2) {}

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
        GUIVirtualInput() {}

        virtual ~GUIVirtualInput();

        VirtualInput& GetVirtualInput(dl_int idx);
		void PushInput(const VirtualInput& input);

		dl_size GetNumVirtualInputs() const { return m_inputs.size(); }

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 4, GUI_ALLOCATOR);
		}

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
		}
    protected:
		DLUT::DLVector<VirtualInput> m_inputs;
    };
}