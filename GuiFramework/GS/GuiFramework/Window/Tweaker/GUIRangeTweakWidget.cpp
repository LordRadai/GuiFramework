#include "GUIRangeTweakWidget.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIRangeTweakWidget*, TGUISharedString<dl_wchar>, GUIRangeDataBase*);

	GUIRangeTweakWidget::GUIRangeTweakWidget(TGUISharedString<dl_wchar> label, GUIRangeDataBase* pRangeData) 
	{
		CALL(Constructor_t, 0x5431c0, this, label, pRangeData);
	}

	DLRF::DLRuntimeClass* GUIRangeTweakWidget::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x543170, this);
	}

	GUIRangeTweakWidget::~GUIRangeTweakWidget()
	{
		CALL(Destructor_t, 0x544c50, this);
	}

	void GUIRangeTweakWidget::OnDelete()
	{
		CALL(OnDelete_t, 0x5440e0, this);
	}

	dl_uint GUIRangeTweakWidget::OnMButtonDown(const MouseEvent& event)
	{
		return CALL(OnMButtonDown_t, 0x543e90, this, event);
	}

	dl_uint GUIRangeTweakWidget::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x543670, this, input);
	}

	dl_uint GUIRangeTweakWidget::OnSize()
	{
		return CALL(OnSize_t, 0x543e60, this);
	}

	dl_uint GUIRangeTweakWidget::OnCreate()
	{
		return CALL(OnCreate_t, 0x543900, this);
	}

	void GUIRangeTweakWidget::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x543330, this, gc);
	}

	GUINumericEditBox* GUIRangeTweakWidget::CreateEditBox()
	{
		return CALL(CreateEditBox_t, 0x5437a0, this);
	}

	void GUIRangeTweakWidget::_Destroy()
	{
		CALL(_Destroy_t, 0x5432a0, this);
	}
}