#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
    struct _GUI_VIRTUAL_INPUT
    {
        enum VIRTUAL_INPUT_ID : dl_uint8
        {
            // Basic Action Mappings
            GUI_INPUT_CANCEL = 0,
            GUI_INPUT_CONFIRM = 1,
            GUI_INPUT_SELECT = 2,

            // Directional / Navigation State
            GUI_INPUT_NAV_UP = 5,
            GUI_INPUT_NAV_LEFT = 6,
            GUI_INPUT_NAV_RIGHT = 7,
            GUI_INPUT_NAV_DOWN = 8,
            GUI_INPUT_NAV_HORIZONTAL = 9,

            // Utility / Meta Commands
            GUI_INPUT_ACCEPT_ALT = 10,
            GUI_INPUT_BACK_ALT = 11,

            // Directional (Discrete/Held)
            GUI_INPUT_DPAD_RIGHT = 14,
            GUI_INPUT_DPAD_LEFT = 15,
            GUI_INPUT_DPAD_Y = 16,

            // Shoulder / Tab Navigation
            GUI_INPUT_TAB_PREV = 17,
            GUI_INPUT_TAB_NEXT = 18,

            // Analog Input IDs
            GUI_INPUT_STICK_LEFT = 19,  // Param1: Y, Param2: X
            GUI_INPUT_STICK_RIGHT = 20, // Param1: Y, Param2: X

            GUI_INPUT_MAX_ID = 21
        };

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