#pragma once
#include "GuiFramework/Window/ControlEx/GUINumericEditBox.h"

namespace GuiFramework
{
	class GUIMultiNumericEditor : public GUIWidget
	{
		typedef GUIMultiNumericEditor ThisClass;
		typedef GUIWidget SuperClass;
	public:
		struct MULTI_NUMERIC_EDITOR_ITEM
		{
			TGUIObjectPtr<GUINumericEditBox> pEditBox;
			TGUIObjectPtr<GUIRangeDataBase> pRangeData;
		};

		GUIMultiNumericEditor() {}
		GUIMultiNumericEditor(dl_uint numValues, TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIMultiNumericEditor() override;
		virtual void OnDelete() override;
		virtual dl_uint IsMoveChild() const override { return false; }
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnVirtualInputRender(GraphicsContext& gc) const override;

	protected:
		dl_uint16 m_iVar110;
		dl_uint8 m_numValues;
		dl_uint8 m_selectedEditorIdx;
		MULTI_NUMERIC_EDITOR_ITEM* m_editors;
	};
}