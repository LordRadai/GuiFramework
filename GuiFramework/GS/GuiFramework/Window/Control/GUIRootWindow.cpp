#include "GUIRootWindow.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Ctor_t)(GUIRootWindow*, TGUISharedString<dl_wchar>&);

	GUIRootWindow::GUIRootWindow(TGUISharedString<dl_wchar>& label)
	{
		CALL(Ctor_t, 0x572b00, this, label);
	}

	GUIRootWindow::~GUIRootWindow()
	{
		CALL(Destructor_t, 0x572c20, this);
	}
}
