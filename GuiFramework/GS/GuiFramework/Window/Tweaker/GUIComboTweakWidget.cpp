#include "GUIComboTweakWidget.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIComboTweakWidget*, TGUISharedString<dl_wchar>);

	GUIComboTweakWidget::GUIComboTweakWidget(TGUISharedString<dl_wchar> label) : SuperClass()
	{
		CALL(Constructor_t, 0x59c670, this, label);
	}

	DLRF::DLRuntimeClass* GUIComboTweakWidget::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x59c620, this);
	}

	GUIComboTweakWidget::~GUIComboTweakWidget()
	{
		CALL(Destructor_t, 0x59d1d0, this);
	}

	void GUIComboTweakWidget::OnDelete()
	{
		CALL(OnDelete_t, 0x59ca70, this);
	}

	dl_uint GUIComboTweakWidget::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x59c770, this, input);
	}

	dl_uint GUIComboTweakWidget::OnSize()
	{
		return CALL(OnSize_t, 0x59cd10, this);
	}

	dl_uint GUIComboTweakWidget::OnCreate()
	{
		return CALL(OnCreate_t, 0x59ca90, this);
	}

	void GUIComboTweakWidget::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x59cd40, this, gc);
	}
}