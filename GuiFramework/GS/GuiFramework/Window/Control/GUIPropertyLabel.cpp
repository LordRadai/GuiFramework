#include "GUIPropertyLabel.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIPropertyLabel*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_int);

	GUIPropertyLabel::GUIPropertyLabel(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_int flags)
	{
		CALL(Constructor_t, 0x5566c0, this, pParent, label, flags);
	}

	DLRF::DLRuntimeClass* GUIPropertyLabel::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x556670, this);
	}

	GUIPropertyLabel::~GUIPropertyLabel()
	{
		CALL(Destructor_t, 0x557030, this);
	}

	void GUIPropertyLabel::OnDelete()
	{
		CALL(OnDelete_t, 0x556e20, this);
	}

	void GUIPropertyLabel::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x556920, this, gc);
	}
}