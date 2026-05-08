#pragma once
#include "GuiFramework/Window/ControlEx/GUINumericEditBox.h"
#include "GuiFramework/Window/ControlEx/TGUIRangeData.inl"

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

		void Reflesh(dl_int idx);
		void SetRangeData(dl_int idx, GUIRangeDataBase* pRangeData);

		template<typename T>
		TGUIRangeData<T>* GetRangeData(dl_int idx) const
		{
			if (idx > this->m_numValues)
				return nullptr;

			GUIRangeDataBase* pRangeData = this->m_editors[idx].pRangeData.Get();

			if (pRangeData == nullptr)
			{
				TGUIRangeData<T>* pRangeDataTyped = new TGUIRangeData<T>(0, 1000, 1);
				this->m_editors[idx].pRangeData = pRangeDataTyped;

				return pRangeDataTyped;
			}

			return dynamic_cast<TGUIRangeData<T>*>(pRangeData);
		}
	protected:
		dl_uint16 m_iVar110;
		dl_uint8 m_numValues;
		dl_uint8 m_selectedEditorIdx;
		MULTI_NUMERIC_EDITOR_ITEM* m_editors;
	};
}