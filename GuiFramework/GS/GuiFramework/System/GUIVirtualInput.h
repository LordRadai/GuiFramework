#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
    struct _GUI_VIRTUAL_INPUT
    {
        enum VIRTUAL_INPUT_ID : dl_uint8
        {
            GUI_INPUT_RESTORE,
            GUI_INPUT_MINIMIZE,
            GUI_INPUT_SELECT,

            GUI_INPUT_3,
			GUI_INPUT_4,

            GUI_INPUT_NAV_UP,
            GUI_INPUT_NAV_DOWN,
            GUI_INPUT_DPAD_DOWN,
            GUI_INPUT_DPAD_UP,
            GUI_INPUT_9,

            GUI_INPUT_ACCEPT,
            GUI_INPUT_BACK,

            GUI_INPUT_12,
			GUI_INPUT_13,

            GUI_INPUT_DPAD_RIGHT,
            GUI_INPUT_DPAD_LEFT,
            GUI_INPUT_DPAD_Y,

            GUI_INPUT_TAB_NEXT,
            GUI_INPUT_TAB_PREV,

            GUI_INPUT_STICK_LEFT,
            GUI_INPUT_STICK_RIGHT,

            GUI_INPUT_MAX_ID
        };

        dl_uint8 InputID;
		dl_int Param1;
        dl_int Param2;

		_GUI_VIRTUAL_INPUT() : InputID(0), Param1(0), Param2(0) {}
		_GUI_VIRTUAL_INPUT(dl_uint8 inputID, dl_int param1 = 0, dl_int param2 = 0) : InputID(inputID), Param1(param1), Param2(param2) {}

        bool IsKeyEvent(dl_char eventID) const
        {
            return InputID == eventID;
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
            return DLKRD::AllocationSupporter<DLKR::DLAllocator>::Allocate(size, 4, GUIAllocator::s_pDefaultAllocator);
		}

        static void operator delete(void* p)
        {
            DLKRD::AllocationSupporter<DLKR::DLAllocator>::Deallocate(p, GUIAllocator::s_pDefaultAllocator);
		}
    protected:
		DLUT::DLVector<VirtualInput> m_inputs;
    };
}