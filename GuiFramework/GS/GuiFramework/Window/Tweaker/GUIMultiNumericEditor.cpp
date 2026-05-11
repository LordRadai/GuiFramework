#include "GUIMultiNumericEditor.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(_fastcall* Constructor_t)(GUIMultiNumericEditor*, dl_uint, TGUISharedString<dl_wchar>);

	typedef void(_fastcall* Reflesh_t)(GUIMultiNumericEditor*, dl_int);
	typedef void(_fastcall* SetRangeData_t)(GUIMultiNumericEditor*, dl_int, GUIRangeDataBase*);

	GUIMultiNumericEditor::GUIMultiNumericEditor(dl_uint numValues, TGUISharedString<dl_wchar> label)
	{
		CALL(Constructor_t, 0x5b48e0, this, numValues, label);
	}

	DLRF::DLRuntimeClass* GUIMultiNumericEditor::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5b4890, this);
	}

	GUIMultiNumericEditor::~GUIMultiNumericEditor()
	{
		CALL(Destructor_t, 0x5b5c90, this);
	}

	void GUIMultiNumericEditor::OnDelete()
	{
		CALL(OnDelete_t, 0x5b5840, this);
	}

	dl_uint GUIMultiNumericEditor::OnVirtualInput(const VirtualInput& input)
	{
		return CALL(OnVirtualInput_t, 0x5b5660, this, input);
	}

	dl_uint GUIMultiNumericEditor::OnSize()
	{
		return CALL(OnSize_t, 0x5b4ff0, this);
	}

	dl_uint GUIMultiNumericEditor::OnCreate()
	{
		return CALL(OnCreate_t, 0x5b4de0, this);
	}

	void GUIMultiNumericEditor::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5b5020, this, gc);
	}

	void GUIMultiNumericEditor::OnVirtualInputRender(GraphicsContext& gc) const
	{
		CALL(OnVirtualInputRender_t, 0x5b5190, this, gc);
	}

	void GUIMultiNumericEditor::Reflesh(dl_int idx)
	{
		CALL(Reflesh_t, 0x5b4bb0, this, idx);
	}

	void GUIMultiNumericEditor::SetRangeData(dl_int idx, GUIRangeDataBase* pRangeData)
	{
		CALL(SetRangeData_t, 0x5b4c10, this, idx, pRangeData);
	}
}