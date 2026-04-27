#pragma once
#include "GUIListBox.h"

namespace GuiFramework
{
	class GUIDropDownList : public GUIListBox
	{
		typedef GUIDropDownList ThisClass;
		typedef GUIListBox SuperClass;
	public:
		GUIDropDownList() {}
		GUIDropDownList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIDropDownList() override;
		virtual void OnDelete() override;
		virtual void OnItemSelected(dl_int idx) override;
	};
}
