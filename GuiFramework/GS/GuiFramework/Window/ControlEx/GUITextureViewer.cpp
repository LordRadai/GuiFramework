#include "GUITextureViewer.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* ConstructorWithLabel_t)(GUITextureViewer*, TGUISharedString<dl_wchar>);
	typedef void(__fastcall* ConstructorWithParentAndLabelAndCreateParams_t)(GUITextureViewer*, GUIWindowBase*, TGUISharedString<dl_wchar>, const _GUI_CREATE_WINDOW&);
	typedef void(__fastcall* ConstructorWithParentAndLabelAndFlags_t)(GUITextureViewer*, GUIWindowBase*, TGUISharedString<dl_wchar>, dl_uint, dl_uint);

	GUITextureViewer::GUITextureViewer(TGUISharedString<dl_wchar> label)
	{
		CALL(ConstructorWithLabel_t, 0x5a75b0, this, label);
	}

	GUITextureViewer::GUITextureViewer(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams)
	{
		CALL(ConstructorWithParentAndLabelAndCreateParams_t, 0x5a7640, this, pParent, label, createParams);
	}

	GUITextureViewer::GUITextureViewer(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4)
	{
		CALL(ConstructorWithParentAndLabelAndFlags_t, 0x5a76f0, this, pParent, label, flags, param_4);
	}

	DLRF::DLRuntimeClass* GUITextureViewer::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x5a7560, this);
	}

	GUITextureViewer::~GUITextureViewer()
	{
		CALL(Destructor_t, 0x5aa960, this);
	}

	void GUITextureViewer::OnDelete()
	{
		CALL(OnDelete_t, 0x5aa610, this);
	}

	dl_uint GUITextureViewer::OnMouseMove(const MouseEvent& event)
	{
		return CALL(OnMouseMove_t, 0x5a7a40, this, event);
	}

	dl_uint GUITextureViewer::OnLButtonDown(const MouseEvent& event)
	{
		return CALL(OnLButtonDown_t, 0x5a7ae0, this, event);
	}

	dl_uint GUITextureViewer::OnLButtonUp(const MouseEvent& event)
	{
		return CALL(OnLButtonUp_t, 0x5a8760, this, event);
	}

	dl_uint GUITextureViewer::OnRButtonDown(const MouseEvent& event)
	{
		return CALL(OnRButtonDown_t, 0x5a7bc0, this, event);
	}

	dl_uint GUITextureViewer::OnMouseWheel(const MouseEvent& event)
	{
		return CALL(OnMouseWheel_t, 0x5a98b0, this, event);
	}

	dl_uint GUITextureViewer::OnCommand(dl_uint cmdId)
	{
		return CALL(OnCommand_t, 0x5a9c90, this, cmdId);
	}

	dl_uint GUITextureViewer::OnSize()
	{
		return CALL(OnSize_t, 0x5a9c60, this);
	}

	void GUITextureViewer::OnRender(GraphicsContext& gc) const
	{
		CALL(OnRender_t, 0x5a87c0, this, gc);
	}
}