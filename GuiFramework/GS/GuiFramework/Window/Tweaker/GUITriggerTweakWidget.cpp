#include "GUITriggerTweakWidget.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(const GUITriggerTweakWidget*, TGUISharedString<dl_wchar>);

	typedef GUIButton*(_fastcall* AddButton_t)(GUITriggerTweakWidget*, TGUISharedString<dl_wchar>);

	GUITriggerTweakWidget::GUITriggerTweakWidget(TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x594b80, this, label);
	}

	DLRF::DLRuntimeClass* GUITriggerTweakWidget::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x594b30, this);
	}

	GUITriggerTweakWidget::~GUITriggerTweakWidget()
	{
		CALL(Destructor_t, 0x595990, this);
	}

	void GUITriggerTweakWidget::OnDelete()
	{
		CALL(OnDelete_t, 0x594ec0, this);
	}

	dl_uint GUITriggerTweakWidget::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x595210, this, input);
	}

	dl_uint GUITriggerTweakWidget::OnSize()
	{
		return CALL(OnSize_t, 0x594e90, this);
	}

	dl_uint GUITriggerTweakWidget::OnCreate()
	{
		return CALL(OnCreate_t, 0x594dd0, this);
	}

	void GUITriggerTweakWidget::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x594f50, this, gc);
	}

	void GUITriggerTweakWidget::OnVirtualInputRender(GraphicsContext& gc) const
	{
		CALL(OnVirtualInputRender_t, 0x5950c0, this, gc);
	}

	GUIButton* GUITriggerTweakWidget::AddButton(TGUISharedString<dl_wchar> label)
	{
		return CALL(AddButton_t, 0x594c90, this, label);
	}
}